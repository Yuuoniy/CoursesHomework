#include <stdio.h>
int main(){
	char str1[50],str2[50],i =0,find = 1;
	int con1[52]={0},con2[52] = {0};
	scanf("%s",str1);
  scanf("%s",str2);
	for(i = 0;str1[i]!='\0';i++)
		con1[str1[i]-65]++;//计算各个字符出现的次数
	for(i = 0;str2[i]!='\0';i++)
		con2[str2[i]-65]++;
	for(i = 0;i<52;i++)
		if(con1[i]!=con2[i]){//如果有一个不同 就可以判断不是异构体
			find = 0;
			break;
		}
	if(find)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}