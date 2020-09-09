#include<stdio.h>
/*
    顺序队 队列的逻辑结构 先入先出
    通常使从队尾入 队首出
    入队的时候 队尾指针要向后移动一位
    出队的时候 队首指针也要向后移动一位
    这样会出现下面的情况 两个指针同时到达MASIZE-1的位置
    虽然队里已经没有元素了但是 却无法再次入队 这种情况就是假溢出
    
    针对上面的问题的解决方法就是循环队列 
    如 队首指针 front      出队操作 front=(front+1)%MAXSIZE 如果MAXSIZE大小为8
    就会产生 0到7的数 相当于一个环 会一直走下去 

    描述队空 queue.front==queue.rear
    描述队满 (rear+1)%MAXSIZE==queue.front
 */
#define MAXSIZE 100
typedef struct SqlQueue
{
    int data[MAXSIZE];
    int front;
    int rear;
}SqlQueue;

/*
    初始化队列
 */

void initQueue(SqlQueue *queue)
{
    queue->front=0;
    queue->rear=0;
}

/*
    判断是否为空
 */
int isEmpty(SqlQueue *queue)
{
    if(queue->front==queue->rear)
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
int enQueue(SqlQueue *queue,int x)
{
    // 队满不能入队
    if((queue->rear+1)%MAXSIZE==queue->front)
    {
        return 0;
    }

    queue->rear=(queue->rear+1)%MAXSIZE;
    queue->data[queue->rear]=x;
    return 1;
}
/*
    出队
 */
int deQueue(SqlQueue *queue,int *e)
{
    // 队空不能出队
    if(queue->front==queue->rear)
    {
        return 0;
    }
    *e=queue->data[queue->front];
    queue->front=(queue->front+1)%MAXSIZE;
    return 1;
}