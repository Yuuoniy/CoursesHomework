void swapArray(int len, int arr1[len], int arr2[len])
{
	int  i = 0;
	int temp[len];
	for(i = 0;i<len;i++)
		temp[i] = arr1[i];
	for(i = 0;i<len;i++)
		arr1[i] = arr2 [i];
	for(i = 0;i<len;i++)
		arr2[i] = temp[i];
	

}
void swapMatrix(int len, int mat1[len][len], int mat2[len][len])
{
	int temp = 0, i =0,j = 0;
	for(i = 0;i<len;i++)
	{
		for(j = 0;j<len;j++)
		{
			temp = mat2[i][j];
			mat2[i][j] = mat1[i][j];
			mat1[i][j] = temp;

		}

	}
}