#include <stdio.h>

int main(){
	int a,b,c;
	a = b = c =0;
	scanf("%d%d%d",&a,&b,&c);
	if(((a+b)>c)&&((a+c)>b)&&((c+b)>a))
	  printf("valid\n");
	else 
	  printf("invalid\n");
	return 0;
	
}