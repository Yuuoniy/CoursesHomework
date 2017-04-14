#include "point_sort.h"

void point_sort(struct point a[], int n)
{
	struct point temp;
	for(int i = 0;i<n;i++)//冒泡排序
	{
		for(int j = 0;j<n-1;j++)
		{		
			if((a[j].x>a[j+1].x)||((a[j].x==a[j+1].x)&&(a[j].y>a[j+1].y)))
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
