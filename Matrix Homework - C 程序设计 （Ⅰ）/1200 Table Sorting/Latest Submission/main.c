#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"


int main()
{
	int n = 0,way = 0;
	scanf("%d",&n);
	ReadTable(n);
	node pt[100];
	while(scanf("%d",&way)&&(way!=-1))
	{
		memcpy(pt,raw,100*sizeof(node));
		qsort_r(pt, n, sizeof(pt[0]), &cmpStruct, &way);
		PrintTable(n,pt);
	}

}
