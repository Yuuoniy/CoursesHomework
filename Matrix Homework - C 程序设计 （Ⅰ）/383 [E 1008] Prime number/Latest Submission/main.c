#include <stdio.h>

int main(){
	long int a = 2;
	int div = 2;
	scanf("%ld",&a);
	if (a == 1)
	printf("No\n");
	else
			
	{
		
	for(div;div<=(a/2);div++)
	{
		if ((a%div)==0)
		   { printf("No\n");
		      return 0;
           } 		
	}
	printf("Yes\n");
	}
	return 0;
}