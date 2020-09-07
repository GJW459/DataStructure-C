#include<stdio.h>
#define MAXSIZE 100
typedef struct ArrayList
{

    /* data */
    int data[MAXSIZE];
    int length;
}ArrayList;

/*
    顺序表的操作
    初始化
    增删查找
*/
void init(ArrayList *list)
{
    list->length=0;
}
int insert(ArrayList *list,int i,int e)
{
    if(list->length==MAXSIZE||i<0||i>list->length)
    {
        return 0;
    }
    for(int j=list->length-1;j>=i;j--)
    {
        list->data[j+1]=list->data[j];
    }
    list->data[i]=e;
    list->length=list->length+1;
    return 1;

}
int delete(ArrayList *list,int i)
{
    if(list->length==0||i<0||i>list->length-1)
    {
        return 0;
    }
    for(int j=i;j<list->length;j++)
    {
        list->data[j]=list->data[j+1];
    }

    list->length=list->length-1;
    return 1;
}

int findElem(ArrayList list,int e)
{
    for(int i=0;i<list.length;i++)
    {
        if(e==list.data[i])
        {
            return 1;
        }
    }
    return 0;
}

// 转置 数组转置
void reverse(int arr[],int left,int right,int k)
{
    int temp;
    for(int i=left,j=right;i<j&&i<left+k;i++,j--)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
/*
    两个数组 一个数组前m个有序 后面从m开始到n结束也是有序 
    请设计一个算法 使整个都有序
    算法的时间复杂度 O(mn)
*/

void insertElem(int arr[],int m,int n)
{

    int i,j;
    int temp;
    for(i=m;i<m+n;i++)
    {
        temp=arr[i];
        // temp和前面的m个元素进行大小比较
        for(j=i-1;j>=0;j--)
        {
            if(temp<arr[j])
            {
                // 元素向后移动一个位置
                arr[j+1]=arr[j];
            }
            else
            {
                arr[j+1]=temp;
                break;
            }
        }
    }

}
int main()
{

    return 0;
}