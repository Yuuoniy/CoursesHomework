#include <stdio.h>
int main()
{
	int alp[27]={0};
	int words = 0,count = 0,flag = 0,max = 0,n =0,word =0,i = 0;
	char ch;
	while((ch=getchar())!=EOF){		//计算单词数和各个字符数	
		if((ch=='\n')||(ch==32))//字符特殊
			word = 0;
		else if(word==0){
			word = 1;//标志
			words++;
		}
				alp[ch-97]++;//计算各个字符个数
		}
	}	
	alp[26] = words;
	for(i=0;i<27;i++){//找出频率最高的字母
		if(alp[i]>max)
			max=alp[i];
	}
	for(n=max;n>0;n--){//从上往下输出
	  /* for(i=h,flag=0;i<27;i++){  //看各个字母有没有输出 并标记
	   		if(alp[i]>=n){
	   			flag=1;
	   			break;
	   	   }  
	   	 } */
       		printf("%d\t",n); 
	        for(i=h;i<27;i++) {
	       			if(alp[i]){		
										if((alp[i]-n)>=0){      		//看各个字母在该处有没有输出	
												printf("*");
										}
										else
												printf("%c",' ');
										if (i==26){//输出最后一个时
												printf("\n");
										}						
	    					}	    	    	
	        }		
	}
	printf(" \t");
	for(i=0;i<26;i++){//输出最后一行
		if(alp[i]!=0)
			printf("%c",97+i);

	}
	printf("W\n");
	
	return 0;
	
}