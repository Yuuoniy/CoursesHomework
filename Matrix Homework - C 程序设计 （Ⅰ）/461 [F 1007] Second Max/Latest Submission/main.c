#include <stdio.h>

int main()
{
	int times = 0;
	int number = 0;
	int c = 0,max1 = 0; 
    int n = 0,i = 0;    
    scanf("%d",&times); 
	int secondbig[times];  
    for(i;i<times;i++)
    {
    	scanf("%d",&number);
    	int list[number];
    	for(n = 0;n<number;n++)
    	{
   	      scanf("%d",&list[n]);
	    }
	    max1 = list[0];
    	for(n = 0;n<number;n++)	
    	{
		   if (list[n]>=list[0])		
    	   {
    	    	c = list [0];
    	    	list[0] = list[n];
				list[n] = c;   	     	   		
		    }		      		       
		}
		for(int t = 1;t<number;t++)
		{
			if(list[t]>=list[1])
			{
				list[1]=list[t];
			}
		}		
		secondbig[i] = list[1];		
	} 
	for(int a = 0;a<times;a++)
	    {
		printf("%d\n",secondbig[a]);
	    } 
	return 0;
} 