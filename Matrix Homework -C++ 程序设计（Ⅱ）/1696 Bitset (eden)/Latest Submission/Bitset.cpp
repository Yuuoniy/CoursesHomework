#include"Bitset.h"

bitset::bitset(){
	for(int i = 0;i<N;i++){
		a[i] = 0;
	}
}
void bitset::set(int pos){
	int index = pos/32;
	int site = pos%32;
	long int temp = 1;
	a[index] |=(temp<<site);
	//std::cout << "set" <<std::endl;

}//把位置pos设置成1
void bitset::reset(int pos){
	int index = pos/32;
	int site = pos%32;
	unsigned int temp = 1;
	a[index]&=(	~0^(temp<<site));
}
//将位置pos设置成0
int bitset::count() const{
	//std::cout<< "in count"<<std::endl;
	int count = 0;
	for(int i = 0;i<N;i++){
		unsigned int temp = a[i];
		for(int j = 0;temp;temp>>=1)
			count += temp&1;
	}
	//std::cout << "after count"<<std::endl;
	return count;
}//输出一共有多少个为1的位
bool bitset::test(int pos) const{
	int index = pos/32;
	int site = pos%32;
	if(a[index]&(1<<site))
		return true;
	else
		return false;
}
bool bitset::any() const{
	return count()!=0?true:false;
}
//是否有是1的位
bool bitset::none() const{
	return count()==0?true:false;
}
//是否没有是1的位
bool bitset::all() const{
	return count()==32*5?true:false;
}

//位运算部分和普通数字的位运算相同。
bitset& bitset::operator&= (const bitset& b){
	for(int i = 0;i<N;i++){
		a[i]&=b.a[i];
	}
	return *this;
}
bitset& bitset::operator|= (const bitset& b){
	for(int i = 0;i<N;i++){
		a[i]|=b.a[i];
	}
	return *this;
}
bitset& bitset::operator^= (const bitset& b){
	for(int i = 0;i<N;i++){
		a[i]^=b.a[i];
	}
	return *this;
}
bitset& bitset::operator= (const bitset& b){
	for(int i = 0;i<N;i++){
		a[i] =b.a[i];
	}
	return *this;
}
bitset& bitset::operator <<= (int pos){
	for(int i = N - 1;i>0;i--){
		a[i]<<= pos;
		for(int j = 0;j<pos;j++){
			if(test(i*32+j-pos))
				set(i*32+j);
			else
				reset(i*32+j);
			}
		}
	
	a[0] <<= pos;
	for(int i = 0;i<pos;i++){
		reset(i);
	}
	return *this;
}


bitset& bitset::operator >>= (int pos){
	for(int i = 0;i<N-1;i++){
		a[i] >>= pos;
		for(int j = 0;j<pos;j++){
			if(test((i+1)*32+j))
				set((i+1)*32+j-pos);
			else
				reset((i+1)*32+j-pos);
		}
	}
	a[N-1] >>= pos;
	for(int i = 0 ;i<pos;i++){
		set(32*N-1-i);
	}
	return *this;
}
bitset bitset::operator~() const{
	bitset temp;
	for(int i = 0;i<N;i++){
		temp.a[i] = ~a[i];
	}
	return temp;
}
bitset bitset::operator&(const bitset& b) const{
	bitset temp;
	for(int i = 0;i<N;i++){
		temp.a[i] = a[i]&b.a[i];
	}
	return temp;
}
bitset bitset::operator|(const bitset& b) const{
	bitset  temp;
	for(int i = 0;i<N;i++){
		temp.a[i] = a[i]|b.a[i];
	}
	return temp;
}
bitset bitset::operator^(const bitset& b) const{
	bitset  temp;
	for(int i = 0;i<N;i++){
		temp.a[i] = a[i]^b.a[i];
	}
	return temp;
}
bitset bitset::operator<<(int pos) const{
	bitset temp ;
	temp =  *this;
	for(int i = N - 1;i>0;i--){
		temp.a[i]<<= pos;
		for(int j = 0;j<pos;j++){
			if(temp.test(i*32-pos+j))
				temp.set(i*32+j);
			else
				temp.reset(i*32+j);
		
		}
	}
	
	temp.a[0] <<= pos;
	for(int i = pos-1;i>=0;i--){
		temp.reset(i);
	}
	return temp;

}

bitset bitset::operator>>(int pos) const{
	bitset temp;
	temp = *this;
	for(int i = 0;i<N-1;i++){
		temp.a[i] >>= pos;
		for(int j = 0;j<pos;j++){
			if(temp.test((i+1)*32+j))
				temp.set((i+1)*32+j-pos);
			else
				temp.reset((i+1)*32+j-pos);

		}
	}
	temp.a[N-1] >>= pos;
	for(int i = 0 ;i<pos;i++){
		temp.set(32*N-1-i);
	}
	return temp;
}
bool bitset::operator== (const bitset& b) const{
	for(int i = 0;i<N;i++){
		if(a[i]!=b.a[i])
			return false;
	}
	return true;
}
bool bitset::operator!= (const bitset& b) const{
	for(int i = 0;i<N;i++){
		if(a[i]!=b.a[i])
			return true;
	}
	return false;
}
bool bitset::operator[] (int pos) const{
	return test(pos)?true:false;
}