#include <stdio.h>

int main()
{
	int my_queue[11] = {0};
	int front_index = 0,rear_index = 0,p1 = 0,p2 = 0;
	char ch = '\0';		
	while(scanf("%d",&p1)!=EOF) {			
	if(p1==0)
		if(front_index==rear_index)
			printf("Pop Failed. The queue is empty.\n");
		else{		
			printf("%d\n",my_queue[front_index++]);
			front_index %=11;
		}			
	if(p1==1){	
		scanf("%d",&p2);
		if((rear_index + 1 )%11== front_index)
			printf("Push Failed. The queue is full.\n");
		else{
			my_queue[rear_index++] = p2;	
			rear_index %=11;	
			}
		}	
	}		
}