
#include<stdio.h>
#include<math.h> 

int main()
{
	int a = 0, b = 0,c = 0;
	float  x1 = 0.0f,x2 = 0.0f, deta = 0;
	scanf("%d%d%d",&a,&b,&c);
	deta = sqrt(b*b-4*a*c);
	
	
	x1 = (-b-deta)/(2*a);
	x2 = (-b+deta)/(2*a);
	if (x1>x2)
	  printf("%.3f %.3f\n",x2,x1);
	else
	  printf("%.3f %.3f\n",x1,x2);
	  
	
		return 0;
	  
 } 