#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int times = 0,i = 0,basic = 0,length = 0,n = 0;
	long int  reslut1 = 0,reslut2 = 0;
	char num[20] = {0};	
	scanf("%d%d",&times,&basic);
	for(i = 0;i<times;i++)		
	{
		reslut1 = 0;
		reslut2 = 0;
		scanf("%s",num);		
		length = strlen(num);
		for(n = 0;n<length;n++)
		{
			
			reslut1 = reslut1 + (num[n]-48)*pow(basic,n);
			reslut2 = reslut2 + (num[n]-48)*pow(basic,length-n-1);
			
		}
		printf("%ld %ld\n",reslut2,reslut1);
		
		
	}
	return 0;

}