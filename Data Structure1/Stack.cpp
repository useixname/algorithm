#include<bits/stdc++.h>
using namespace std;
typedef int SElemType;
typedef int Status;
#ifndef OVERFLOW
#define OVERFLOW -1
#endif
#define ERROR -2
#define OK 1
#define INFEASIBLE 0

#define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
#define STACK_INCREMENT 2 /* 存储空间分配增量 */

typedef struct SqStack
{
	SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
	SElemType *top; /* 栈顶指针 */
	int stacksize; /* 当前已分配的存储空间，以元素为单位 */
}SqStack; /* 顺序栈 */

/* bo3-1.c 顺序栈的基本操作(9个) */
void InitStack(SqStack *S)
{	/* 构造一个空栈S */
	(*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!(*S).base)
		exit(OVERFLOW); /* 存储分配失败 */
	(*S).top=(*S).base;
	(*S).stacksize=STACK_INIT_SIZE;
}

void DestroyStack(SqStack *S)
{	/* 销毁栈S，S不再存在 */
	free((*S).base);
	(*S).base=NULL;
	(*S).top=NULL;
	(*S).stacksize=0;
}

void ClearStack(SqStack *S)
{	/* 把S置为空栈 */
	(*S).top=(*S).base;
}

Status StackEmpty(SqStack S)
{	/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
	if(S.top==S.base)
		return true;
	else
		return false;
}

int StackLength(SqStack S)
{	/* 返回S的元素个数，即栈的长度 */
	return S.top-S.base;
}

Status GetTop(SqStack S,SElemType *e)
{ /* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
	if(S.top>S.base)
	{
		*e=*(S.top-1);
		return OK;
	}
	else
		return ERROR;
}

void Push(SqStack *S,SElemType e)
{	/* 插入元素e为新的栈顶元素 */
	if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
	{
		(*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACK_INCREMENT)*sizeof(SElemType));
		if(!(*S).base)
			exit(OVERFLOW); /* 存储分配失败 */
		(*S).top=(*S).base+(*S).stacksize;
		(*S).stacksize+=STACK_INCREMENT;
	}
	*((*S).top)++=e;
}

Status Pop(SqStack *S,SElemType *e)
{	/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
	if((*S).top==(*S).base)
		return ERROR;
	*e=*--(*S).top;
		return OK;
}

void StackTraverse(SqStack S,void(*visit)(SElemType))
{	/* 从栈底到栈顶依次对栈中每个元素调用函数visit() */
	while(S.top>S.base)
		visit(*S.base++);
	printf("\n");
}

void PrintElem(SElemType e) {
    cout << e << " ";
}

int main(){
    SqStack S;
    InitStack(&S);
    SElemType e;
    cout<<"请输入要入栈的元素e:";
    cin>>e;
    while(e!=-1){
        Push(&S,e);
        cout<<"元素"<<e<<"入栈成功。"<<'\n';
        if (GetTop(S, &e) == OK) {
		    cout << "当前栈顶元素为" << e << '\n';
		} else {
		    cout << "栈为空，无法获取栈顶元素" << '\n';
		}
        cout<<"当前顺序栈的长度为"<<StackLength(S)<<'\n';
        cout<<"当前顺序栈的元素为：";
        StackTraverse(S,PrintElem);
        cout<<"请输入要入栈的元素e:";
        cin>>e;
    }
    Pop(&S,&e);
    cout<<"元素"<<e<<"出栈成功。"<<'\n';
    cout<<"当前顺序栈的长度为"<<StackLength(S)<<'\n';
    cout<<"当前顺序栈的元素为：";
    StackTraverse(S,PrintElem);
    if (GetTop(S, &e) == OK) {
		    cout << "当前栈顶元素为" << e << '\n';
	} else {
	    cout << "栈为空，无法获取栈顶元素" << '\n';
	}
    // 检查顺序栈是否为空
    if (StackEmpty(S)) {
        cout << "顺序栈为空。" << endl;
    } else {
        cout << "顺序栈不为空。" << endl;
    }
    // 清空顺序栈
    ClearStack(&S);
    cout << "清空后的顺序栈内容: ";
    StackTraverse(S, PrintElem); // 打印顺序栈内容

    // 销毁顺序栈
    DestroyStack(&S);

    return 0;
}