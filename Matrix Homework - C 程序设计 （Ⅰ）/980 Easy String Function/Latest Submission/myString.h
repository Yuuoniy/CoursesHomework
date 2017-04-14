int myStrlen(char a[]) 
{
    int len = 0;
    for(len = 0;a[len]!='\0';len++);
    return len;
}
int myStrcmp(char a[], char b[])
{
	int i = 0, j =0;
     while(a[i] == b[j])
    {
        if(a[i] == '\0')
            return 0;        
        i++;
        j++;
    }
    return (a[i] -b[j]);
}

void myStrcpy(char des[], char src[]) 
{
    int i = 0, j =0;
	while ((des[i++]=src[j++])!='\0'); 
}