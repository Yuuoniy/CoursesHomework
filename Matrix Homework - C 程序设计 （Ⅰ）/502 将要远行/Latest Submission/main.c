#include <stdio.h>

int main(){
	char num[100];
	int lon = 0，i = 0,sum = 0;
	scanf("%s",num);
	for (i;num[i]!='\0';i++){
		sum = sum +(num[i]-48);
	}
	if (sum%3==0)
		printf("God\n");
	else 
		printf("Issac\n");
	return 0;
}

	

	


