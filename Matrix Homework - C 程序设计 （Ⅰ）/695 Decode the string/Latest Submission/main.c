#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	char ch[100],ch1,ch2,ch3;
	int length = 0,i = 0,n=0,j=0,digit = 0,num = 0;
	int a[4]={0};
	scanf("%s",ch);
	length = strlen(ch);
	ch2=ch[0];  //ch2代表需要重复输出的字符
    for (j=1;j<length;j++){		  
	    ch1=ch[j];  								
				if((ch1>=48)&&(ch1<58)){//如果是数字
					while((j!=length)&&(ch1>=48)&&(ch1<58)){//一直是数字
						a[i++] = ch1-48;
			    digit++;
			    ch1=ch[++j];			 //获取下一个ch1  	
			 		}
        num = a[0]*pow(10,--digit)+a[1]*pow(10,--digit)+a[2]*pow(10,--digit)+a[3]*pow(10,--digit);			//计算连起来的数字的数值
        if(num>7)//根据题意
            num = num%7+1;				
        for(n = 1;n<=num;n++){//重复输出
          printf("%c",ch2);
        }
        ch2=ch1;//此时ch1不是数字
        i = 0;num = 0;digit = 0;//准备下一轮
        a[0]=0;a[1]=0;a[2]=0;a[3]=0;			
			}				
			else {		//如果不是数字    
			    printf("%c",ch2);//先输出原来存的ch2 
						ch2=ch1;
		}
	}	
	if((ch2!='\0')&&((ch2<48)||(ch2>58)))//测试最后一个数
		printf("%c",ch2);
	printf("\n");
	return 0;
}


