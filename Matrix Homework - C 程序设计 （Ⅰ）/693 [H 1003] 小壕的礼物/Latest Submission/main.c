#include <stdio.h>
#include <string.h>
int main()
{
	int times = 0,a1= 0,n = 0,type = 0;
	scanf("%d",&times);
	char gift[100][100], temp[100];
	for(n = 0;n<times;n++){
		scanf("%d %s",&type,temp);
		if (type==1){//说明是礼物
      strcpy(gift[a1++],temp);     
			}
		else {//说明是人 
			printf("%s %s\n",temp,gift[--a1]);		
		}
	}	
	return 0;
}