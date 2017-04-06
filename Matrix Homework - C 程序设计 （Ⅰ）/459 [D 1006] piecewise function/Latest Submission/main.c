#include <stdio.h>
#include <math.h>

int main(){
	float x = 0;
	float y = 0;
	scanf("%f",&x);
	if (x<-1)
	{
		y = x+1;
	}
	else if(x>=1)
	{
		y = log10(x);
	}
	else
	{
		y = fabs(x);
	}
    printf("%.2f\n",y);
    return 0;
}