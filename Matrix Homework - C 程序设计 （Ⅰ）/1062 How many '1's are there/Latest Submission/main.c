 #include <stdio.h>

int main()
{
	int times = 0, i =0,num = 0,count = 0;
	scanf("%d",&times);
	for(i = 0;i<times;i++){
		scanf("%d",&num);
		count = 0;
		while(num){
			if(num&1)//利用逻辑与
				count++;
			num = num>>1;//右移一位
		}
		printf("%d\n",count);
	}
	return 0;
}