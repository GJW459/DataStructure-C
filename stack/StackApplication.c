#include<stdio.h>

/*
    什么时候会用到栈 ?
    当一个问题变成一个子问题 并且无法解决的时候 栈这时就起了起到了记忆作用
    栈的应用
    括号匹配
    表达式计算
    递归
 */

/*
    括号匹配 
    遍历字符数组 如果是‘(’ 直接入栈

 */
#define MAXSIZE 100
int match(char exp[],int n)
{

    // 定义栈
    char stack[MAXSIZE];
    int top=-1;
    for(int i=0;i<n;i++)
    {
        if(exp[i]=='(')
        {
            stack[++top]=exp[i];//入栈操作
        }
        if(exp[i]==')')
        {
             // 栈中为空 并且当前又是右括号的时候
            if(top==-1)
            {
                return 0;
            }
            else
            {
                top--;// 如果栈不为空 就代表是) 出栈 
            }
        }
    }
    if(top==-1)
    {
        return 1;// 遍历完后 栈顶指针为-1代表是空栈 括号匹配成功
    }
    else
    {
        return 0;
    }

    
}
/*
    后缀表达式的计算也是用栈来解决的
    思想就是 如果是数字就入栈 如果是运算符就出栈最上面的两个元素 然后进行计算
    然后再将计算结果入栈
    知道遇到'\0' 此时栈顶的元素就是计算的结果 
 */
int com(char expt [])
{
    int a,b,c;// a b 是操作数 c来保存结果
    int stack[MAXSIZE];
    int top=-1;
    char op;// 用来取操作符
    // 字符数组 也就是字符串 都是以'\0'结束
    for(int i=0;expt[i]!='\0';i++)
    {
        if(expt[i]>='0'&&expt[i]<='9')
        {
            stack[++top]=expt-'0';
        }
        else
        {
            // 获取操作符
            op=expt[i];
            // 出栈头两个字符
            a=stack[top--];
            b=stack[top--];
            c=Op(a,op,b);
            stack[++top]=c;
        }

    }
    // 循环结束后栈顶元素就是结果
    return stack[top];

}
int Op(int a,char op,int b)
{
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    if(op=='/')
    {
        if(b==0)
        {
            printf("分母不能为0\n");
            return 0;
        }
        else
        {
            return a/b;
        }
    }
}