#include <stdlib.h>//提供malloc free
#define STACK_MAX_SIZE 6

int stack_push(int *stack, int num){
	static int i = 1;
	if(stack[0]==0)
		i = 0;
	stack[++i] = num;
	if(i>STACK_MAX_SIZE)
		return 0;
	else {	
		stack[0]++;//成功入栈 数目加1
		return 1;
	}
}

int stack_pop(int *stack){//出栈 数目减1
	if((stack[0])==0)
		return 0;
	else
		stack[0]--;
}

int stack_top(int *stack, int *ret){
	if((stack[0])==0)
		return 0;
	else
		*ret = stack[stack[0]];//栈顶的数
}

int *stack_constructor(void){
	int *p = (int*)calloc(100,sizeof(int));//分配空间
	return p;
}

void stack_destructor(int *stack){//释放空间
	free(stack);
}

