#include <stdio.h>

int main(){
	int line = 0, i = 0,col = 0,j = 0;
	scanf("%d%d",&line,&col);//几行几列
	char num[100][100], ch;
	for(i;i<line;i++){				
		scanf("%s",num[i]);			
	}	
	for(i = 0;i<line;i++){
		for(j=col-1;j>=0;j--){//从后往前输出
			if(num[i][j]!=' '){				
				if(num[i][j]=='b')	//讨论特殊情况									
					printf("d");				 				
				else if(num[i][j]=='d')					
					printf("b");
				else 
					printf("%c",num[i][j]);//一般情况
			}
		}
		printf("\n");
	}
	return 0;
}