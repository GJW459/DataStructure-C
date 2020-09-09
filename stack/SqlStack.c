#include<stdio.h>

/*
    顺序stack 逻辑结构 先进后出 
    存储结构 顺序存储结构 底层使数组
 */
#define MAXSIZE 100
typedef struct SqlStack
{

    int data[MAXSIZE];
    int top;// 栈顶指针
}SqlStack;

/*
    初始化栈
 */
void initStack(SqlStack *stack,int arr[],int length)
{
    stack->top=-1;
    for(int i=0;i<length;i++)
    {
        stack->data[i]=arr[i];
        stack->top=stack->top+1;
    }
}
/*
    判断栈是否为空
 */
int isEmpty(SqlStack stack)
{
    if(stack.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
/*
    入栈 操作
 */
int push(SqlStack *stack,int x)
{
    // 栈满不能入栈
    if(stack->top==MAXSIZE-1)
    {
        return 0;
    }
    stack->top=stack->top+1;
    stack->data[stack->top]=x;
    return 1;

}
/*
    出栈 操作
 */
int pop(SqlStack *stack,int *e)
{
    // 栈空不能出栈
    if(stack->top==-1)
    {
        return 0;
    }
    *e=stack->data[stack->top];
    stack->top=stack->top-1;
    return 1;
}

int main()
{

    int arr[]={1,3,4,5,6,9};
    SqlStack stack;
    stack.top=-1;// 初始化栈
    int flag=isEmpty(stack);
    printf("is Empty:%d\n",flag);
    push(&stack,2);
    int e ;
    pop(&stack,&e);
    printf("e:%d\n",e);
    SqlStack stack2;
    initStack(&stack2,arr,6);
    int flag2=isEmpty(stack2);
    printf("is Empty:%d\n",flag2);
    int e2 ;
    pop(&stack2,&e2);
    printf("e2:%d\n",e2);
}