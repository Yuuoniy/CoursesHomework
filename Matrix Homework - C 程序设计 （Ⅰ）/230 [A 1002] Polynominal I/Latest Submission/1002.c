
#include<stdio.h>

int main()
{
	int a1 = 0,a2 = 0, b1 = 0, b2 = 0;
	
	
	scanf("%d%d",&a1,&b1);
	scanf("%d%d",&a2,&b2);
	
	int a1a2 = a1*a2;
    int a1b2a2b1 = a1*b2+a2*b1;
    int b1b2 = b1*b2;
    
	printf("%d%c%c%d%c%d%c%c%d\n",a1a2,'x','^',2,'+',a1b2a2b1,'x','+',b1b2);
	
	return 0;
}