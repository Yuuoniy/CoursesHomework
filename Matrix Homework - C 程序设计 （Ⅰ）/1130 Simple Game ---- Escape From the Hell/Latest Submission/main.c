#include <stdio.h>
#include <stddef.h>
#include "utility.h"

char mov; 
int main()
{
	int map_size = 0,map_row = 0, map_col = 0,find_human = 0;
	int is_alive = 1,is_stop = 0;
	scanf("%d",&map_size);
	readMap(map_size);
	for (map_row = 1;map_row<=map_size;map_row++)//找到一开始人的坐标 
	{
		for(map_col = 1;map_col<=map_size;map_col++)
			if(map[map_row][map_col]=='A')
			{
				human_x = map_row;
				human_y = map_col;
				find_human =1; 
				break; 
			 }
		if(find_human)
			break; 		 
	}	

	while(scanf(" %c",&mov)!=EOF&&is_alive)
	{
		move(map_size, &is_alive, &is_stop);		
		if(is_alive)
			printMap(map_size);
		else 
			printf("Game Over!\n");
	}
	return 0;	
}

void readMap(const size_t map_size)
{
	int i = 0;	
	for(i;i<map_size+2;i++)
	{
		getchar();
		fgets(map[i],map_size+3,stdin);
	}
}

void printMap(const size_t map_size)
{
	int i = 0;
	for(i;i<map_size+2;i++)
		printf("%s\n",map[i]);
}

void move(size_t map_size, int *is_alive, int *is_stop)
{	

	static int flag = 0;//判断当前人物的位置是否是水 
	int next_x = human_x, next_y = human_y;
	if(!(*is_stop))
	{
		switch(mov)
		{
			case 'a':
				if(--next_y==0)
					next_y = map_size;
				switch (map[next_x][next_y])
				{
					case ' ':
						map[human_x][human_y] =flag?'@':' ';//判断人物当前位置是否是水 
						flag = 0; 
						human_y = next_y;
						map[human_x][human_y] = 'A';//人物移动的位置 
						break;				
					case '$':
						*is_alive = 0; 
						break;
					case '@':
						*is_stop = 1;								
						map[human_x][human_y] =flag?'@':' ';//人物移动前的位置 
						flag = 0; 
						human_y = next_y;
						map[human_x][human_y] = 'A';//人物移动后 					
						flag = 1;//水被覆盖
						break;
					default :break;																											
				 } 
				 break;							
			case 'd':
				if(++next_y>map_size)
					next_y = next_y%map_size;			
				switch (map[next_x][next_y])
				{
					case ' ':
						map[human_x][human_y] =flag?'@':' ';//判断人物当前位置是否是水 
						flag = 0; 
						human_y = next_y;
						map[human_x][human_y] = 'A';//人物移动的位置 
						break;				
					case '$':
						*is_alive = 0; 
						break;
					case '@':
						*is_stop = 1;								
						map[human_x][human_y] =flag?'@':' ';//人物移动前的位置 
						flag = 0; 
						human_y = next_y;
						map[human_x][human_y] = 'A';//人物移动后 					
						flag = 1;//水被覆盖
						break;
					default :break;																											
				 } 			
				break;
			case 'w':
				if(--next_x==0)
					next_x  = map_size;
				switch (map[next_x][next_y])
				{
						case ' ':
							map[human_x][human_y] =flag?'@':' ';//判断人物当前位置是否是水 
							flag = 0; 
							human_x = next_x;
							map[human_x][human_y] = 'A';//人物移动的位置 
							break;												
						case '$':
							*is_alive = 0; 
							break;
						case '@':
							*is_stop = 1;								
							map[human_x][human_y] =flag?'@':' ';//人物移动前的位置 
							flag = 0; 
							human_x = next_x;
							map[human_x][human_y] = 'A';//人物移动后 					
							flag = 1;//水被覆盖
							break;
						default :break;																											
				 }
				 break; 	
				 			
			case 's':
				if(++next_x>map_size)
					next_x = next_x%map_size;
				switch (map[next_x][next_y])
				{
					case ' ':
						map[human_x][human_y] =flag?'@':' ';//判断人物当前位置是否是水 
						flag = 0; 
						human_x = next_x;
						map[human_x][human_y] = 'A';//人物移动的位置 
						break;			
					case '$':
						*is_alive = 0; 
						break;
					case '@':
						*is_stop = 1;								
						map[human_x][human_y] =flag?'@':' ';//人物移动前的位置 
						flag = 0; 
						human_x = next_x;
						map[human_x][human_y] = 'A';//人物移动后 					
						flag = 1;//水被覆盖
						break;
					default :break;																											
				 } 						
			default :break;															
		}
	}
	else
		*is_stop = 0;
}

