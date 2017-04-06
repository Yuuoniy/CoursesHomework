#include <stdio.h>


int main()
{
	char a;
	int b;
	float c;
	long long int d;
	long long int f;
	double e;
	scanf("%c%d%f%lld%lld%lf",&a,&b,&c,&d,&f,&e) ;
	printf("%c %d %.2f %lld %lld %.7lf\n",a,b,c,d,f,e);
	return 0;
}