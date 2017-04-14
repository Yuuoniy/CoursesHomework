#include <stdio.h>
int find(long int,long int);
int main(){
	long int a,b,mid;
	int c;
	scanf("%ld %ld",&a,&b);
	
	printf("%d\n",(a>b)?find(a,b):find(b,a));
	}
	
int find(long int a,long int b)
{

	return ((b == 0) ? a : find(b, a % b));  
}
