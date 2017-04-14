
#include<stdio.h>

int main()

{
	int a = 0;
	int gewei = 0,shiwei = 0, baiwei = 0,a10 = 0;
	
	scanf("%d",&a);
	gewei = a%10;
	shiwei = (a/10)%10;
	baiwei =  a/100;
	printf("%d\n",gewei+shiwei+baiwei);
	
	return 0;
}