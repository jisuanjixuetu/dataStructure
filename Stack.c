#include<stdio.h>
#include<stdlib.h>
#define Stack_Init_Size 100
#define StackIncease 10
typedef struct stack{
    int *base;
    int *top;
    int stacksize;
}Stack;
void InitStack(Stack *stack){
    stack->base = (int *)malloc(Stack_Init_Size*sizeof(int));
    if(!stack->base){
        exit(1);
    }
    stack->top = stack->base;
    stack->stacksize = Stack_Init_Size;
}
int GetTop(Stack stack,int e){
    if (stack.top == stack.base){
        printf("error\n");
    }
    e = *(stack.top-1);
    return e;
}
void Push(Stack *stack,int e){
    if(stack->top - stack->base >= stack->stacksize)
    {
        stack->base = (int *)malloc((Stack_Init_Size+StackIncease)*sizeof(int));
        if(!stack->base){
            exit(1);
        }
        stack->top = stack->base+Stack_Init_Size;
        stack->stacksize = stack->stacksize+StackIncease;
    }
    *stack->top++ = e;
}
int Pop(Stack *stack){
    if (stack->top == stack->base){
        printf("error\n");
    }
    int e = * --stack->top;
    return e;
}
int main(){
    Stack stack;
    InitStack(&stack);
    for(int i = 0;i < 10;i++){
        printf("please enter the %d node\n",i+1);
        int e;
        scanf("%d",&e);
        Push(&stack,e);
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n",Pop(&stack));
    }
    return 0;
}

