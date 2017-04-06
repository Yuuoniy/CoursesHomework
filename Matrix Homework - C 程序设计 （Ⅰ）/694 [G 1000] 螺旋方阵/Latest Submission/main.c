#include <stdio.h>

int main()
{

	int b = 0,row = 0,col = 0,n = 0,m = 1;
	int a[100][100];
	scanf("%d",&b);
	b--;
	for(n= 0;n<=(b/2);n++)
	{
		for(col=n;col<=b-n;col++)
			a[n][col] = m++;
		for(row=n+1;row<=b-n;row++)
			a[row][b-n]=m++;
		for(col=b-n-1;col>=n;col--)
			a[b-n][col]=m++;
		for(row=b-n-1;row>n;row--)
			a[row][n]=m++;
		
	}
	for(row=0;row<=b;row++)
		for(col=0;col<=b;col++)
		{
			if(col==b)
				printf("%d\n",a[row][col]);
			else
				printf("%d ",a[row][col]);
		}
		return 0;
}
