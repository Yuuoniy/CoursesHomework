#define MAX_TOTAL 10
#define MAX_SIZE 4
#include <stddef.h>


void inputMatrices(int matrix[][MAX_SIZE], size_t size);
void printMatrices(int  matrix[][MAX_SIZE], size_t size);
int cmpMatrices(const void *firstMatrixPtr, const void *secondMatrixPtr, void *sizePtr);
