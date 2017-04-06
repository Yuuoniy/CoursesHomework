#include <math.h>
#include <string.h>
long long unsigned basicNumberReading(int a)
{	
		long long unsigned reslut1 = 0;	
		char num[100];
		int length = 0, n =0;
		scanf("%s",num);		
		length = strlen(num);
		for(n = 0;n<length;n++)
		{		
			reslut1 = reslut1 + (num[n]-48)*pow(a,length-n-1);	
		}
		//printf("%ld %ld\n",reslut2,reslut1);
		return reslut1;		
}