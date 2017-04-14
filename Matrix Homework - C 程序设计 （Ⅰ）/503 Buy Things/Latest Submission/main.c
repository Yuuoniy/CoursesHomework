#include <stdio.h>

int main(){
	int money = 0,item = 0, num = 0, i = 0，flag = 1;
	scanf("%d%d",&money,&item);
	int items[item];//建立数组 对应各个商品的价格
	for(i = 0;i<item;i++){
		scanf("%d",&items[i]);//读取价格
	}
	while(flag)
	{
		scanf("%d",&num);//读取行为
		if(num==-1){
	  	 printf("Bye.\n");
	  	 break;	    
		}
		else if(num==10){
	    	printf("Ihen!\nBye.\n");
	   	 	break;
	   	 }	 
		else
	   	 	money -= items[num];//成功购买 收钱
		if(money>0)
	    	printf("You have %d yen now.\n",money);
		else{
	    	printf("BAKA!\nBye.\n");
	    	break;   
		}   
	}	
	return 0;
}
	
	