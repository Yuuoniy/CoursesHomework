 void add(char lhs[], char rhs[],char sum[])
{
	int len1 = 0,len2 = 0,i = 0, n = 0;
	long int num1 = 0,num2 = 0,total = 0;
	int  sum1[10];
	len1 = strlen(lhs);
	len2 = strlen(rhs);
	for(i = len1-1,n = 0;i>=0;i--,n++)
	{
		num1 += (lhs[i]-'0')*(pow(10,n));
	}
	for(i = len2-1,n = 0;i>=0;i--,n++)
	{
		num2 +=(rhs[i]-'0')*(pow(10,n));
	}
	total = num1+num2;
//	printf("%ld\n",total);
	i = 0;
	n = 0;
	while(total)
	{
		sum1[i++] = total%10;
		total/=10;
		n ++;
	}
  	if(total==0)
	sum[0] = '0';
	for(i = 0;i<n;i++)
	{
		sum[i] = sum1[n-i-1]+'0';
	}	
}