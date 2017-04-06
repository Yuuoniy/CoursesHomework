int split(char ret[][100], const char str[], const char del)
{
	int i = 0, j = 0,k = 0;
	for(i = 0,k;str[i]!='\n';i++){
		if(str[i]!=del)
			ret[j][k++] = str[i];
		else{			//遇到分隔符 存新的单词
			j++;
			k = 0;//注意
		}
	}
	for(i = 0;i<=j;i++)
		printf("%s\n",ret[i] );
	return 0;
}

void lstrip(char str[], const char del){
	char tem[100];
	memset(tem,'\0',100);
	int i = 0,j = 0;
	while(str[i]==del)
		i++;
	for(j = 0;str[i]!='\n';i++)
		tem[j++] = str[i];
	tem[j] = '\0';//要自己添加'\0’
	strncpy(str,tem,100);	//字符串的复制
}
void rstrip(char str[], const char del){
	char tem[100];
	memset(tem,'\0',100);//初始化
	int i = 0, j =0;
	for(i=0;str[i]!='\0';i++);		 
	while(str[i-1]==del)//从尾部往前
		i--;
	for(j = 0;j<i;j++){
		tem[j] = str[j];
	}
	tem[j] = '\0';
	strncpy(str,tem,100);
}




