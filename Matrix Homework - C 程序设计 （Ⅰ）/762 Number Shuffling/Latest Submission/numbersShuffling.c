#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RandLoop(int a[],int b,int c[]);
int main()
{
	int num = 0,seed = 0, i =0,num1 = 0,num2 = 0;
	scanf("%d",&num);
	int ser1[num],ser2[num],randnum1[num],randnum2[num];	
	for(i;i<num;i++)
	{
		scanf("%d",&ser1[i]);
	}
	num1 = num;
	memcpy(ser2,ser1,sizeof(ser1));
	scanf("%d",&seed);
	srand(seed);
	for(i = 0;i<num-1;i++)
	{
		randnum1[i]=rand()%(num1--);
	}
	num1 = num;
	for(i = 0;i<num-1;i++)
	{
		randnum2[i]=rand()%(num1--);
		//printf("%d ",randnum2[i]);
	}	
	RandLoop(ser1,num,randnum1);
	RandLoop(ser2,num,randnum2);
	return 0;	
}

void RandLoop(int a[],int b,int c[])
{
	int i = b-1,ran = 0,temp = 0,count = 0,n=0;
	for(count,i,n;count<b-1;count++,i--,n++)
	{

		temp = a[i];
		a[i] = a[c[n]];
		a[c[n]] = temp;
	}
		printf("{");
	for(i = 0;i<=count;i++)	
	{
		if(i==count)
			printf("%d}\n",a[count]);
		else
			printf("%d, ",a[i]);
	}
}