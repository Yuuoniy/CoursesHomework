#include <stdio.h>
int main(){
	int n = 0,x = 0;
	float m = 0;
	x = scanf("%d",&n);
	if ((n<0)||(n>100)||x!=1)
	    printf("Invalid\n");
	else if(n<60)
	    printf("Failed\n");
	else
	{
		m = ((float)n-50)/10;
		printf("%.1f\n",m);
	}
	
	    
	return 0;
}