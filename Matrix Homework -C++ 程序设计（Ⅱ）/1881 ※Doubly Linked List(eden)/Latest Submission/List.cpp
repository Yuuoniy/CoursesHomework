#include "List.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;
	 
list::list(){
	head = NULL;
	tail = NULL;
	_size = 0;
	// construct a list from an exist array
}
list::list(const data_type other[], int length){
	// cout << "arraycopy const" << endl;
	_size = 0;
	head = tail = NULL;
	for(int i = 0;i<length;i++){
		(*this).insert(i,other[i]);
	}
	// cout << "aftercopy const" << endl;

}

list::list(const list& other){
	head = tail = NULL;
	_size = 0;
	*this = other;
}
list& list::operator=(const list& other){
	if(this==&other)
		return *this;
	clear();
	int temp = 0,count = 0;
	listPointer current = other.head;
	while(current!=NULL){

		temp = current->data;
		(*this).insert(count++,temp);
		current = current->next;
	}

	return *this;
}

list::~list(){
	clear();
}

	// Capacity
bool list::empty(void) const{
	return _size==0?true:false;
}
list::size_type list::size(void) const{
	return _size;
}

	// Element access
list::data_type& list::front(void) const{
	return head->data;
}
list::data_type& list::back(void) const{
	return tail->data;
}


std::string list::toString(void) const{
	ostringstream op;
	op << "NULL";
	if(_size!=0){
		for(listPointer ptr = head;ptr->next;ptr = ptr->next){
			if(ptr==head)
				op << "<-" << ptr->data;
			else
				op << "<->" << ptr->data;
		}
		if(_size==1)
			op << "<-"<< tail->data<<"->NULL"; 
		else
			op << "<->"<< tail->data<<"->NULL"; 
	}
	return op.str();

}

	// Modifiers
void list::assign(const list& other){
	cout << "in assign " << endl;
	(*this) = other;
	cout << "afetr assign " << endl;
}

void list::assign(const data_type datas[], int length){
	clear();
	for(int i = 0;i<length;i++){
		(*this).insert(i,datas[i]);
	}


}
void list::push_front(const data_type& data){
		(*this).insert(0,data);

}
void list::push_back(const data_type& data){
	(*this).insert(_size,data);
}
void list::pop_front(void){
	if(_size==0)
		return ;
	else
		(*this).erase(0);

}
void list::pop_back(void){
	if(_size==0)
		return;
	else(*this).erase(_size-1);
}

void list::insert(int position, const data_type& data){
	// cout<< "in insert"<<endl;
	if(position>_size||position<0)
		return;
	listPointer temp = new node(data);
	if(head==NULL||position==0){
		// cout << "in if " << endl;
		if(head==NULL)
			head = temp;
		else{//listPointer temp = new node(data);
			temp->next = head;
			temp->prev = NULL;
			head->prev = temp;
			head = temp;
		}
		// cout << "after if" <<endl;
	}
	else{
		// cout << "in else" << endl;
		listPointer find = at(position-1);
		//listPointer temp = new node(data);
		temp->next = find->next;
		find->next = temp;
		if(temp->next!=NULL)
			temp->next->prev = temp;
		temp->prev = find;
		// cout << "after else" <<endl;
	}
	if(position==_size)
		tail = temp;
	_size++;
	// cout << "size = " << _size <<endl;
	return ;

}
void list::erase(int position){
	//cout << "in erase initial" << endl;
	if(position<0||position>=_size)
		return;
	else if(position==0){
		// cout << "in erase first" << endl;
		listPointer temp = head;
		if(head->next!=NULL)
			head->next->prev = NULL;
		head = head->next;
		_size--;
		if(_size==0)
			tail = NULL;
		delete temp;
		// cout << "after erase first" << endl;
	}
	else if(position==_size-1){
		// cout << "in erase"<<endl;
		listPointer temp = tail;
		tail->prev->next = NULL;
		tail = tail->prev;
		_size--;
		delete temp;
		// cout << "after erase"<<endl;
	}
	else{
		// cout << "in erase third" << endl;
		listPointer temp = at(position);
			if(temp==NULL)
				return;
			else{
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				_size--;
				delete temp;
			}
		// cout << "after erase first" << endl
	}

}
void list::clear(void){
	if(this->head!=NULL){
		listPointer ptr = head;
		while(ptr!=NULL){
			node *temp = ptr;
			ptr = ptr->next;
			delete temp;
		}
		
	}
	head = tail = NULL;
	_size = 0;
}

	// Operations
	// split this list into to lists at the given position
void list::split(int position, list* des1, list* dest2){
	(*des1).clear();
	(*dest2).clear();
	int i = 0;
	for(i;i<position;i++){
		(*des1).insert(i,(*this).at(i)->data);
	}
	for(i;i<_size;i++){
		(*dest2).insert(i-position,(*this).at(i)->data);
	}
	
}

list& list::merge(const list& src1, const list& src2){
	// cout << "in merge" <<cout;
	list temp1 = src1;
	list temp2 = src2;
	clear();
	/*(*this) = src1;
	(*this)+=src2;*/
	(*this) = temp1;
	(*this)+=temp2;
	// cout << "finish merge" <<endl;
	return *this;
}

list& list::remove_if(bool (*condition)(listPointer)){
	int i = 0;
	// cout << "in remove" << endl;
	listPointer temp = head;
	while(temp!=NULL){
		if(condition(temp)){
			temp = temp->next;
			(*this).erase(i);
		}
		else{
			i++;
			temp = temp->next;
		}
	}
/*	for(;temp!=NULL;temp = temp->next){
		if((condition(temp))&&temp!=NULL){
			(*this).erase(i);
		}
		else
			i++;
	}*/
	// cout << "after remove"<<endl;
	return(*this);
}

	// remove duplicate elements
list& list::unique(void){
	if(head == NULL||head->next==NULL)
		return *this;
	int temp[_size];
	int tempsize = _size;
	char flag[_size]={0};
	int index = 0;
	for(int i = 0;i<_size;i++){
		temp[i] = (*this).at(i)->data;
	}
	for(int i = _size-1;i>=0;i--){
		for(int j = 0;j!=i;j++){
			if(temp[i]==temp[j])
				 flag[i] = 1;
		}
	}
	clear();
	for(int i = 0;i<tempsize;i++){
		if(flag[i]!=1)
			insert(index++,temp[i]);
	}
	// cout << "after unique" << endl;
	// reverse the list
}
list& list::reverse(void){
	list temp = (*this);
	clear();
	for(int i = temp._size-1;i>=0;i--){
		(*this).insert(temp._size-1-i,temp.at(i)->data);
	}
	return *this;
}

	// operators
list::data_type& list::operator[](int index){
	return (*this).at(index)->data;
}
list& list::operator+=(const list&other){
	// cout << "in +=" << endl;
	if(other.head==NULL)
		return *this;
	int temp = 0;
	listPointer current = other.head;
	for(;current->next;current = current->next){
		if(current!=NULL){
			temp = current->data;
			insert(_size,temp);
		}
	}
	if(current!=NULL)
		insert(_size,current->data);
	// cout << "after +=" << endl;
	return (*this);
}
std::ostream& operator<<(std::ostream& os, const list& li){
	os << li.toString();
	return os;
}


