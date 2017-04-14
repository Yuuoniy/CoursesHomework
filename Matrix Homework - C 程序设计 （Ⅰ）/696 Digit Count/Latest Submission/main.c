#include <string.h>

int main(){
	int i,n,count[10]={0},num,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){	
		scanf("%d",&num);
		memset(count,0,sizeof(count));//初始化数组 
		for(j=1;j<=num;j++){
			if(j<=9)
				count[j]++;
			else{
				count[j%10]++;//获得十位数 
				count[j/10]++;//获得个位数 
			}								
		}
		for(j = 0;j<9;j++)//输出 
			printf("%d ",count[j]);
		printf("%d\n",count[j]);
		
	}
} 