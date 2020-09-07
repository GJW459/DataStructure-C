#include<stdio.h>
#include<stdlib.h>
/*
    双向链表就是再定义的时候多了一个 struct Node *prior 指针
    尾插法创建 双向链表
    Node *end;
    Node *node=(Node *)malloc(sizeof(Node));
    node->data=e;
    end->next=node;
    node->prior=end;
    end=node;

    插入所指元素之后 诀窍 现将两个链接起来
    p 节点 所指元素 s 所插元素
    s->next=p->next;
    s->prior=p;
    p->next=s;
    s->next->prior=s;

    删除所指元素之后
    p 所指 q 要删除的元素
    q=p->next;
    p->next=q->next;
    q->next->prior=p;
    free(q);

    循环链表 判断p走到尾节点
    p->next=head;

*/
typedef struct Node
{
    /* data */
    int data;
    struct Node *next;
}Node;
/*

    单链表的操作
    初始化 头插法 尾插法
    插入 删除 查找 归并
*/
// 头插法
Node * createLinkedListHead(int arr[],int length)
{

    Node * head;
    head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    Node *node;
    for(int i=0;i<length;i++)
    {
        node=(Node*)malloc(sizeof(Node));
        node->data=arr[i];
        node->next=head->next;
        head->next=node;
    }
    return head;
}
// 尾插法
Node * createLinkedListTail(int arr[],int length)
{
    Node *head;
    head=(Node *)malloc(sizeof(Node));
    head->data=NULL;
    Node * end;
    end=head;//指向尾节点
    Node *node;
    for(int i=0;i<length;i++)
    {
        node=(Node *)malloc(sizeof(Node));
        node->data=arr[i];
        end->next=node;
        end=end->next;
        
    }
    end->next=NULL;
}
// 插入元素 e 插入元素的数据 i是插入元素的位置 第几个位置
int insert(Node *list,int e,int i)
{


    Node * p=list->next;//指向第一个节点
    for(int j=1;j<=i;j++)
    {
        // 指针移动到指定位置
        if(p!=NULL)
        {
             p=p->next;
        }
        else
        {
            break;
        }
        
    }
    // 退出循环后 指针已经指向指定的元素了
    // 开始插入
    Node *node =(Node *)malloc(sizeof(Node));
    node->data=e;
    node->next=p->next;
    p->next=node;
    return 1;
}
// 删除指定位置的元素
int delete(Node *list,int i)
{
    // Node *p=list->next;// 指向第一个元素
    // for(int j=1;j<i;j++)
    // {

    //     if(p!=NULL)
    //     {
    //         p=p->next;// 向后移动知道移动到i位置的前一个元素
    //     }
    //     else
    //     {
    //         break;
    //     }
        
    // }
    // // 开始删除元素
    // Node *elementDel=p->next;// 指向要删除的元素
    // p->next=elementDel->next;// 要删除的前一个元素指向 要删除的后一个元素
    // free(elementDel);// 释放内存
    // return 1;
    Node * p;
    p=list;
    int j=0;// 初始指向头结点 所以j=0
    while(p->next!=NULL && j!=i-1)
    {
        // 指针移动到i位置的前一个
        p=p->next;
        j++;

    }
    // 开始删除元素
    Node *elementDel=p->next;
    p->next=elementDel->next;
    free(elementDel);
    return 1;

}

int findDelete(Node *list,int e)
{

    Node *p;
    p=list;// 指向单链表的头结点
    /* 查找开始 */
    while(p->next!=NULL)
    {
        if(p->next->data==e)
        {
            // 退出的时候指向要删除的前一个
            break;
        }
        p=p->next;
    }
    if(p->next==NULL)
    {
        // 如果后面一个节点为空 代表要删除的元素不存在
        return 0;
    }
    else
    {
        // 开始删除元素
        Node *q=p->next;
        // 移动指针
        p->next=q->next;
        // 释放元素
        free(q);
        return 1;
    }

}

/*

    单链表的归并操作 也就是将两个有序的单链表 AB 链接成一个任然有序的单链表 C
    同时遍历 AB两个单链表然后将小的那一个链接到C后面 使用尾插法
    如果有一个表还没有连接完 就将全部尾插到C后面
*/

Node * mergeTail(Node *A,Node *B)
{

    // 指向 A B 的第一个元素
    Node *p=A->next;
    Node *q=B->next;
    // C 链表使用A的头结点
    Node *C=A;
    C->next=NULL;
    free(B);// 释放 头结点B
    Node *end;// 尾节点 使用尾插法
    end=C;
    // 开始同时遍历 AB 
    while(p!=NULL && q!=NULL)
    {
        // 将小的元素插入到
        if(p->data<=q->data)
        {
            // p 小 则将p元素插入到尾部
            end->next=p;
            p=p->next;
            end=end->next;
        }
        else
        {
            // q 小 则将q元素插入到尾部
            end->next=q;
            p=p->next;
            end=end->next;
        }
    }
    end->next=NULL;
    if(p!=NULL)
    {
        end->next=p;// p后面的全部连接到C后面
    }
    if(q!=NULL)
    {
        end->next=q;// q后面的全部连接到C后面
    }
    return C;
}
// 如果使用的头插法来创建的单链表 就和数组中的元素的次序相反
// 所以要合并后要还是一样的次序就使用头插法合并 AB
Node * mergeHead(Node *A,Node *B)
{

    Node *p=A->next;
    Node *q=B->next;
    // 不用再使用尾指针了 使用一个指针要记录要插入的元素
    Node *node;
    Node *C;
    C=A;
    C->next=NULL;
    free(B);
    while (p!=NULL && q!=NULL)
    {

        /* code */
        if(p->data<=q->data)
        {
            // 头插 p
            node=p;
            p=p->next;
            node->next=C->next;
            C->next=node;

        }
        else
        {
            node=q;
            p=p->next;
            node->next=C->next;
            C->next=node;
        }
    }
    // 可能 p或者q都还没有遍历完 那么都再循环进行头插
    while(p!=NULL)
    {
        node=p;
        p=p->next;
        node->next=C->next;
        C->next=node;
    }
    while (q!=NULL)
    {
        /* code */
        node=q;
        p=p->next;
        node->next=C->next;
        C->next=node;
    }

    return C;
    
    
}

/*

    A 和 B 的差集 删除AB中相同的
*/
void difference(Node *A,Node *B)
{
    Node *p=A->next;
    Node *q=B->next;
    Node *pre=A;
    Node *node;
    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
            pre=p;
            p=p->next;
        }
        else if(p->data>q->data)
        {

            q=q->next;
        }
        else
        {
            pre->next=p->next;
            node=p;
            p=p->next;
            free(node);
        }
        
    }
}
int main()
{

    return 0;
}