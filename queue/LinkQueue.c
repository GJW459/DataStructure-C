#include<stdio.h>
#include<stdlib.h>
/*
    链队
 */
typedef struct QNode
{

    int data;
    struct QNode *next;
}QNode;

typedef struct LinkQueue
{

    QNode *front;
    QNode *rear;
}LinkQueue;

LinkQueue *initQueue()
{
    LinkQueue *lqu=(LinkQueue *)malloc(sizeof(LinkQueue));
    lqu->front=NULL;
    lqu->rear=NULL;
}
int isEmpty(LinkQueue *queue)
{
    if(queue->front==NULL||queue->rear==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
/*
    入队
 */
void enQueue(LinkQueue *queue,int x)
{
    QNode *node;
    node=(QNode *)malloc(sizeof(QNode));
    node->data=x;
    node->next=NULL;
    if(queue->rear==NULL)
    {
        queue->front=node;
        queue->rear=node;
    }
    else
    {
        queue->rear->next=node;
        queue->rear=node;
    }
}
// 出队
void deQueue(LinkQueue *queue,int *e)
{

    QNode *node;
    // 如果队空
    if(queue->rear==NULL)
    {
        return 0;//不能入队
    }
    else
    {
        node=queue->front;
    }
    // 只有一个元素
    if(queue->front==queue->rear)
    {
        queue->front=NULL;
        queue->rear=NULL;
    }
    else
    {
        queue->front=queue->front->next;
    }
    *e=node->data;
    free(node);
    return 1;
}