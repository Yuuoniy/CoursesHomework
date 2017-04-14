#include <stdio.h>
#include <string.h>

int mark_used[9]={0};//用来标记
int sequence[9];//组成的排列 因为采用递归 所以直接使用全局变量在各个函数都可以使用

void find(int head,int n,int use[]);

int main(void){
	int n,i = 0;
	scanf("%d",&n);
	int use[n];
	for(i = 0;i<n;i++){
		use[i] = i+1;
	}
	find(0,n-1,use);
	return 0;
}

void find(int head,int n,int use[]){
	int i;
	for(i=0;i<=n;i++){
		if(mark_used[i]==0){//没用过 说明可以用
    sequence[head]=use[i];
			mark_used[i]=1;			//标记使用
		if(head==n){
			for(head=0;head<n;head++)
				printf("%d ",sequence[head]);//输出序列
			printf("%d\n",sequence[n]);
		}
		else
			find(head+1,n,use);//递归
		mark_used[i]=0;//重新赋值 进入下一轮循环  
		}
	}
}