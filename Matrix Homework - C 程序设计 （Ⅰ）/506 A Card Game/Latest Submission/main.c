#include <stdio.h>
int main()
{
	unsigned long int i = 0,j = 0;	
	
	unsigned long int n = 0,sum = 0;
	int flag = 0;	
	scanf("%ld",&i);
	int num[i];
	for(n,sum;n<i;n++)
	{
		scanf("%d",&num[n]);
		if(num[n]==0)
			flag = 1;
	    sum = sum + num[n];
	}
	//printf("%ld\n",sum);
	if(flag==0||(sum%3!=0)||(sum<3))
		printf("no such number\n");
	else
	{
		for(n=0;n<i;n++)
		{	
			if(num[n]==9)
				printf("%d",num[n]);
		}
			
		for(n=0;n<i;n++)
		{	
			if(num[n]==7)
				printf("%d",num[n]);		
		}
					
	    for(n=0;n<i;n++)
		{	
			if(num[n]==5)
				printf("%d",num[n]);
			
		}	
		for(n=0;n<i;n++)
		{	
			if(num[n]==3)
				printf("%d",num[n]);
			
		}
		for(n=0;n<i;n++)
		{	
			if(num[n]==0)
				printf("%d",num[n]);
			
		}		
	    printf("\n");
	}
	return 0;
}