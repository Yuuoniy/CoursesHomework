#include <stdio.h>
int GCD(int a,int b);

int main()
{
	int num1 = 0,num2 = 0,deno1 = 0,deno2 = 0;
	int num = 0,deno = 0,gcd = 0,times = 0,i = 0;
	scanf("%d",&times);
	for(i;i<times;i++){
		scanf("%d%d",&num1,&deno1);//分子1 分母1
		scanf("%d%d",&num2,&deno2);
		num = num1*num2;
		deno = deno1*deno2;
		if((num ==0)&&(deno!=0))//特殊情况
			printf("0\n");
		else if(deno==0)//特殊情况
			printf("Not A Number\n");
		else{
			gcd = GCD(num,deno);
			num /= gcd;
			deno /=gcd;		
			if(deno==1)//特殊情况
				printf("%d\n",num);
			else 
				printf("%d/%d\n",num,deno);
		}
	}		
	return 0;
}
int GCD(int a,int b){

	return (b==0)?a:GCD(b,a%b);
}
