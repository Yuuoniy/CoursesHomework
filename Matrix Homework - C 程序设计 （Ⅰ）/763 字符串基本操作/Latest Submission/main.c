#include <stdio.h>
#include <string.h>
#include <ctype.h>
void CompareStr(char a[],char b[]);
int main()
{
	char str1[40],str2[40];
	int comp = 0,n = 0,x = 0, y = 0,i = 0,len = 0;
	scanf("%s%s%d%d%d",str1,str2,&n,&x,&y);
	//scanf("%s",str2);
	//scanf("%d%d%d",&n,&x,&y);
	CompareStr(str1,str2);
	strncat(str1,str2,n);
	len = strlen(str1);
	for(i = x;i<=y;i++)
		str1[i] = toupper(str1[i]);
	printf("the length of \"%s\" is %d\n",str1,len);
	strcpy(str2,str1);
	len = strlen(str2);
	for(i=0;i<len;i++)
		str2[i] = tolower(str2[i]);
	//strlwr(str2);
	CompareStr(str1,str2);
	len = strlen(str1);
	if((len/2)-10>0)
		printf("%s\n",str1 );
	else
		printf("%s\n",str2 );
	return 0;
}

void CompareStr(char a[],char b[])
{
	int comp = 0;
	comp = strcmp(a,b);
	if(comp==0)
		printf("%s = %s\n",a,b);
	else if(comp<0)
		printf("%s < %s\n",a,b);
	else
		printf("%s > %s\n",a,b);
}