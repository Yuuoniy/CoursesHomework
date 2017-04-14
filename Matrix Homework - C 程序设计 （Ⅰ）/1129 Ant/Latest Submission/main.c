#include <stdio.h>

int main()
{
	int n = 0,len = 0,i = 0,dis = 0;
	
	char ch = 0;
	int time[1000],temp = 0,max = 0;
	scanf("%d%d",&n,&len);
	for(i = 0;i<n;i++){//循环 算出路程最大的 
		scanf(" %c %d",&ch,&dis);
		if(ch=='L')
			temp = dis;
		else
			temp = len-dis;
		if(temp>max)
			max = temp;
	}
	printf("%d\n",max );

}