#include<stdio.h>
#define MAXSIZE 100
typedef struct SqlList
{
    int data[MAXSIZE];
    int length;
}SqlList;

/*
    删除 顺序表中最小的元素
 */
int del_min(SqlList *list,int *value)
{
    if(list->length==0)
    {
        return 0;
    }
    int min=list->data[1];
    int pos;
    for(int i=1;i<list->length;i++)
    {
        if(list->data[i]<min)
        {
            min=list->data[i];
            pos=i;
        }
    }
    list->data[pos]=list->data[list->length-1];
    list->length=list->length-1;
    *value=min;
    return 1;
    

}
/*
    删除顺序表中所有值为x的元素 时间复杂度为O(1) 空间复杂度为O(n)
 */
void del_x(SqlList *list,int x)
{
    int k=0;
    for(int i=0;i<list->length;i++)
    {
        if(list->data[i]!=x)
        {
            list->data[k]=list->data[i];
            k++;
        }
    }
    list->length=k;
}
/*
    有序表 删除 s<=x<=t中的数 并将后面的元素往前移动
 */
int del_s_t(SqlList *list,int s,int t)
{
    if(list->length==0||s>=t)
    {
        return 0;
    }
    // i j 存储有序表中>=s的第一个位置 和>t的第一个位置
    int i,j;
    for(i=0;i<list->length&&list->data[i]<s;i++)
    if(i>=list->length) return 0;
    for(j=i;j<list->length&&list->data[j]<=t;j++)
    //开始往前移动
    for(;j<list->length;i++,j++)
    {
        list->data[i]=list->data[j];
    }
    list->length=i;
}
int main()
{

    return 0;
}