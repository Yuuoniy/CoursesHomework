#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ReadTable(int n)
{
	int i = 0;
  int j = 0;
	for(i = 0;i<n;i++){
		scanf(" %c %s %s %d",&raw[i].gender,raw[i].name,raw[i].id,&raw[i].score);	
    for(j = strlen(raw[i].name);j<6;j++){
      raw[i].name[j] = ' ';
    raw[i].name[6] = '\0';
    }
    
    
    
		getchar();
	}	
}

void PrintTable(int n,node pt[])
{
	int i = 0;
	printf("Gender Name   Id       Score\n");
	for(i = 0;i<n;i++){
		printf("%-6c %s %8s %-5d\n",pt[i].gender,pt[i].name,pt[i].id,pt[i].score);	
	}
  printf("\n");
}

int cmpStruct(const node *firstStructPtr, const node *secondStructPtr, void *wayPtr)
{
	int *wayptr = (int*)wayPtr;
	int way = *wayptr;
	switch(way)
	{
			case 1:
			if(firstStructPtr->gender == secondStructPtr->gender)
				return strncmp(firstStructPtr->id,secondStructPtr->id,8);
			else 
				return (firstStructPtr->gender - secondStructPtr->gender);
		case 2:
      if(strncmp(firstStructPtr->name,secondStructPtr->name,6)==0)
        return strncmp(firstStructPtr->id,secondStructPtr->id,8);
      else
						return strncmp(firstStructPtr->name,secondStructPtr->name,6);
		case 3:
			return strncmp(firstStructPtr->id,secondStructPtr->id,8);
		case 4:
      if((secondStructPtr->score-firstStructPtr->score)==0)
        return strncmp(firstStructPtr->id,secondStructPtr->id,8);
			return (secondStructPtr->score-firstStructPtr->score);
		default:return 0;

	}
}

