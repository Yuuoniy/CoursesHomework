#include <stdio.h>
int main()
{
	int num[32][32];
	int row = 0;
	scanf("%d",&row);
	int a = 0, b =0;
	for(a=0;a<row;a++)
	{
		for(b=0;b<=a;b++)
			{
				if (a==b||b==0)
				    num[a][b]=1;
			else
	
				num[a][b]=num[a-1][b]+num[a-1][b-1];
        	}
    }
	for(a=0;a<row;a++)
	{	
		for(b=0;b<=a;b++)
		{
		    if(b==0)
				printf("%*d",row-a,num[a][b]);
			else 
				printf(" %d",num[a][b]);
		}
		printf("\n");
    }
    return 0;
		
}