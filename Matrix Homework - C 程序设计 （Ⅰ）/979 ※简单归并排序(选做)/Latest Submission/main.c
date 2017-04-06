 #include <stdio.h>

void mergesort(int num[],int num2[],int start,int end,const int n);
int main()
{
	int n = 0,i = 0;
	int num[100] = {0},num2[100] = {0};
	scanf("%d",&n);
	for(i = 0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	for(i = 0;i<n;i++)
	{
		num2[i] = num[i];
	}		
	mergesort(num,num2,0,n-1,n);
	return 0;		
}
void mergesort(int num[],int num2[], int start,int end,const int n)
{
	if (start >= end)
		return;
	int i = 0,mid = 0;	
	int len = end-start;
	mid = (len >> 1) + start;
//	mid = ((len%2) == 1)?(len/2+start):(len/2+start-1);	
	int start1 = start,end1 = mid;
	int start2 = mid+1,end2 = end;
	mergesort(num,num2,start1,end1,n);
	mergesort(num,num2,start2,end2,n);
	int k = start;
	
	while (start1 <= end1 && start2 <= end2)
		num2[k++] = num[start1] < num[start2] ? num[start1++] : num[start2++];
	while (start1 <= end1)
		num2[k++] = num[start1++];
	while (start2 <= end2)
		num2[k++] = num[start2++];
	for (k = start; k <= end; k++)
		num[k] = num2[k];
		
	for(i = 0;i<n-1;i++)
		printf("%d ",num2[i]);
	printf("%d\n",num2[i]); 	
	
}