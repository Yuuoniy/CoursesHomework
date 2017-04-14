#include <stdio.h>
#include <math.h>

int main()
{
	int n = 0, m = 0;
	int flag = 1;
	int i = 0;
	scanf("%d%d",&n,&m);
	for(i=n;i<=m;i++)
	{
		flag = 1;
				
		for(int test=2;test<i;test++)
		{
			if((i%test)==0)
		    {
			  flag = 0;
		      break;
		    }
		}
		if(flag&&(i!=1))
		{
			printf("%d\n",i);
		    break;
	    }
	}
	if(!flag)
	    printf("none\n");
    return 0;
}
	

