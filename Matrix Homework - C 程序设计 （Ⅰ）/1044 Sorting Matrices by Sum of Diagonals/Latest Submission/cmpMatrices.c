#define MAX_TOTAL 10
#define MAX_SIZE 4
#include <stddef.h>
#include "cmpMatrices.h"

void inputMatrices(int matrix[][MAX_SIZE], size_t size)
{
	int i = 0,j = 0;
	for(i = 0;i<size;i++)
	{
		for (j = 0;j<size;j++)
			scanf("%d",(*(matrix+i)+j));
	}
}

void printMatrices(int  matrix[][MAX_SIZE], size_t size)
{
	int i = 0,j = 0;
	for(i = 0;i<size;i++)
	{			
		for(j = 0;j<size-1;j++)
			printf("%d ",*(*(matrix+i)+j));
		printf("%d\n",*(*(matrix+i)+j));

	}
	printf("\n");
}

int cmpMatrices(const void *firstMatrixPtr, const void *secondMatrixPtr, void *sizePtr)
{
	size_t *matrixSizePtr = (size_t *)sizePtr;
 	size_t matrixSize = *matrixSizePtr;
 	//int *firstarr = *(int (*)[matrixSize])firstMatrixPtr;
 //	int *secondarr = *(int (*)[matrixSize])secondMatrixPtr;
  	//int  (*firstmatrix)[matrixSize] = (int (*)[matrixSize])firstMatrixPtr;
 	 // int  (*secondmatrix)[matrixSize] = (int (*)[matrixSize])secondMatrixPtr;
	int  *firstmatrix = *(int (*)[4])firstMatrixPtr;
 	int  *secondmatrix = *(int (*)[4])secondMatrixPtr;
 	int  i = 0,j = 0,sum1 = 0,sum2 = 0;
 	for(i = 0;i<matrixSize;i++)
 	{
 		for(j = 0;j<matrixSize;j++)
 			if((i==j)||((i+j)==(matrixSize-1)))
    		{
 						sum1 +=*(firstmatrix+(i*4)+j);
      		sum2 +=*(secondmatrix+(i*4)+j);  

      			//sum1 +=*(firstarr+(i*matrixSize)+j);
      			//sum2 +=*(secondarr+(i*matrixSize)+j);   
 			}
  }
 	return (sum1-sum2);	
}