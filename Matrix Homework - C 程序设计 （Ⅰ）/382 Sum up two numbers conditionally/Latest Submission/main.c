#include <stdio.h>

int main(){
	long int sum1 = 0;
	long int sum2 = 0;
	long int sum = 0;
	
	scanf("%ld%ld",&sum1,&sum2);
	sum = sum1+sum2;
	printf("%ld\n",(sum%sum2)==0? sum:sum1);
	return 0;
}