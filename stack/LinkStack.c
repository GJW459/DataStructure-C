#include<stdio.h>
#include<stdlib.h>
/*
    链栈 存储结构是链式存储结构
    通过头插法实现栈结构
 */
typedef struct LinkStack
{

    int data;
    struct LinkStack *next;
}LinkStack;
LinkStack * initStack()
{
    LinkStack *head;
    head=(LinkStack *)malloc(sizeof(LinkStack));
    head->next=NULL;
}
int isEmpty(LinkStack *stack)
{
    if(stack->next==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*
    入栈 头插法
 */
void push(LinkStack *stack,int x)
{
    LinkStack *node;
    node=(LinkStack *)malloc(sizeof(LinkStack));
    node->next=NULL;
    
    node->data=x;
    node->next=stack->next;
    stack->next=node;
}
/*
    出栈
 */
int pop(LinkStack *stack,int *e)
{
    LinkStack *p;
    if(stack->next==NULL)
    {
        return 0;
    }
    p=stack->next;
    *e=p->data;
    stack->next=p->next;
    free(p);
    return 1;
}
int main()
{

    return 0;
}