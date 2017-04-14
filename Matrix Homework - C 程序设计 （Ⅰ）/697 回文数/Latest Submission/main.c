#include <stdio.h>
#include <string.h>


int main()
{
	int num = 0,i = 0,length = 0,n = 0,flag = 1;
	char ch[11];
	char ch1;
	scanf("%d",&num);
	for(i;i<num;i++)
	{					
		flag = 1;
		scanf("%s",ch);
		length = strlen(ch);
		if(length==1)
		printf("Yes\n");		
		else 
		{	
			for(n=0;n<=length/2;n++)
			{
				if(ch[n]!=ch[length-1-n])
				{
					flag = 0;
					break;					
				}				
			}
			
			if (flag==1)
				printf("Yes\n");
			else		
				printf("No\n");
	 	}	 	
	}	
        return 0;
}
	