 #include <stdio.h>

int main()
{
	int magic = 0,alldist = 0,alltime = 0;
	int dist1 = 0,time = 0,flag = 1,dist2 = 0;
	while(scanf("%d%d%d",&magic,&alldist,&alltime)!=EOF)
	{
    
		dist1 = 0,time = 0,flag = 1,dist2 = 0;
		while(alltime--)
		{	time++;
			if(magic>=10)
			{
				dist1 += 60;
				magic -=10;
			}
			else
				magic +=4;
			dist2 +=17;
			if(dist1>dist2)
				dist2 = dist1;
			if(dist2>=alldist)
			{		
				printf("Yes\n%d\n",time);
				flag = 0;
				break;
			}
		}
		if(flag)
		printf("No\n%d\n",dist2);
	}
	
	return 0;
}