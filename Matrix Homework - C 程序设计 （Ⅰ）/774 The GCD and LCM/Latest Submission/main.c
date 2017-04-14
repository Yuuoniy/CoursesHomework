#include <stdio.h>

int GCD(int a,int b);
int LCM(int a,int b);
int main()

{
	int a = 0,b = 0;
	scanf("%d%d",&a,&b);
	if(a<=0||b<=0)
		printf("invalid\n");
	else	
		printf("%d %d\n",GCD(a,b),LCM(a,b));
	return 0;
} 
int GCD(int a,int b){
	return ((b==0)?a:GCD(b,a%b));//递归求最大公因数
}
int LCM(int a,int b) {
	int sum = a*b;
	int gcd = GCD(a,b);
	return sum/gcd;//乘积除以最大公因数
}
