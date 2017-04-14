#include<stdio.h>
#include<math.h>

int main()
{
	int a = 0,b = 0,c = 0, number2 = 0;
	float x = 0,y = 0;
	float out1 = 0, out2 = 0, out3 = 0,out4 = 0,number1 = 0;
	scanf("%d%d%d%f%f",&a,&b,&c,&x,&y);
	number1 = pow(10,3.5)+2;
	number2 = pow(a,2)+pow(b,2)	;
	out1 = 1200/(24-4*5);
	out2 = c * (sqrt(number2));
	out3 =log(log(number1));
	out4 = y + a % 5 * (int)(x + y) / 2 % 4 ;
	
	printf("%.3f\n%.3f\n%.3f\n%.3f\n",out1,out2,out3,out4);

	return 0;
}