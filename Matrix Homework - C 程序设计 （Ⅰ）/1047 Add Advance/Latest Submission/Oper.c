#include <string.h>
#include <stdlib.h> 
#include "Oper.h"

void add(char add1[], char add2[], char sum[])
{
	int len1 = strlen(add1);
	int len2 = strlen(add2);
	int gap = len1 - len2,i  = 0;
	if(len2>len1){	
		add(add2,add1,sum);
		return ;
	}
	for(i = 1;i<=len2;i++){//注意从1开始
		sum[len1-i+1] = add1[len1-i]+add2[len2-i]-'0'-'0';		
	}
	for(i = len2+1;i<=len1;i++){
		sum[len1-i+1] = add1[len1-i]-'0';
	}
	for(i = len1;i>0;i--){				//从后往前进位
		sum[i-1] +=sum[i]/10;
		sum[i] %=10;		
		sum[i]+='0';
	}
	sum[0] += '0';
	if(sum[0]=='0'){//如果第一位没有 则全体往前移
		for(i = 0;i<len1;i++){
			sum[i] = sum[i+1];
		}
		sum[i] = '\0';
	}			
}

char* addTripleNum(char left[], char mid[], char right[]){
	char *sum1 =(char *)malloc(31*sizeof(char));
	char *sum2 =(char *)malloc(31*sizeof(char));
	memset (sum1,'\0',31);	
	memset (sum2,'\0',31);	
	add(left,mid,sum1);
	add(right,sum1,sum2);
	free(sum1);
	return sum2;
}

void freeSum(void* sumPtr)
{
	free(sumPtr);
}

