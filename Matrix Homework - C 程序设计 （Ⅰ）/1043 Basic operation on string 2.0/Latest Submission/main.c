#include <stdio.h>
#include <string.h>
#include "function.h"



int main()
{
	char ret[100][100];
	char str[100],del='\0';
	memset(ret,'\0',10000);
	memset(str,'\0',100);
	fgets(str, 100, stdin);	
	scanf("%c",&del);	
	split(ret,str,del);
	getchar();
	fgets(str, 100, stdin);
	scanf("%c",&del);	
	lstrip(str,del);
	printf("%s\n",str);
	rstrip(str,del);
	printf("%s\n",str);
	getchar();	
	fgets(str, 100, stdin);
	scanf("%c",&del);	
	lstrip(str,del);	
	rstrip(str,del);
	printf("%s\n",str);
	return 0;
}