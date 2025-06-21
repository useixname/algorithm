#include<bits/stdc++.h>
using namespace std;
typedef int QElemType;
typedef int Status;
#define LIST_INIT_SIZE 10 /* 线性表存储空间的初始分配量 */
#define LIST_INCREMENT 2 /* 线性表存储空间的分配增量 */
#ifndef OVERFLOW
#define OVERFLOW -1
#endif
#define ERROR -2
#define OK 1
#define INFEASIBLE 0
/* c3-2.h 单链队列－－队列的链式存储结构 */
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front,rear; /* 队头、队尾指针 */
}LinkQueue;

/* bo3-2.c 链队列(存储结构由c3-2.h定义)的基本操作(9个) */
void InitQueue(LinkQueue *Q)
{	/* 构造一个空队列Q */
	(*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(QNode));
	if(!(*Q).front)
		exit(OVERFLOW);
	(*Q).front->next=NULL;
}

void DestroyQueue(LinkQueue *Q)
{	/* 销毁队列Q(无论空否均可) */
	while((*Q).front)
	{
		(*Q).rear=(*Q).front->next;
		free((*Q).front);
		(*Q).front=(*Q).rear;
	}
}

void ClearQueue(LinkQueue *Q)
{	/* 将Q清为空队列 */
	QueuePtr p,q;
	(*Q).rear=(*Q).front;
	p=(*Q).front->next;
	(*Q).front->next=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
}

Status QueueEmpty(LinkQueue Q)
{	/* 若Q为空队列，则返回TRUE，否则返回FALSE */
	if(Q.front->next==NULL)
		return true;
	else
		return false;
}

int QueueLength(LinkQueue Q)
{	/* 求队列的长度 */
	int i=0;
	QueuePtr p;
	p=Q.front;
	while(Q.rear!=p)
	{
		i++;
		p=p->next;
	}
	return i;
}

Status GetHead_Q(LinkQueue Q,QElemType *e) /* 避免与bo2-6.c重名 */
{	/* 若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR */
	QueuePtr p;
	if(Q.front==Q.rear)
		return ERROR;
	p=Q.front->next;
	*e=p->data;
	return OK;
}

void EnQueue(LinkQueue *Q,QElemType e)
{	/* 插入元素e为Q的新的队尾元素 */
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p) /* 存储分配失败 */
		exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	(*Q).rear->next=p;
	(*Q).rear=p;
}

Status DeQueue(LinkQueue *Q,QElemType *e)
{	/* 若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR */
	QueuePtr p;
	if((*Q).front==(*Q).rear)
		return ERROR;
	p=(*Q).front->next;
	*e=p->data;
	(*Q).front->next=p->next;
	if((*Q).rear==p)
		(*Q).rear=(*Q).front;
	free(p);
	return OK;
}

void QueueTraverse(LinkQueue Q,void(*vi)(QElemType))
{	/* 从队头到队尾依次对队列Q中每个元素调用函数vi() */
	QueuePtr p;
	p=Q.front->next;
	while(p)
	{
		vi(p->data);
		p=p->next;
	}
	printf("\n");
}

void PrintElem(QElemType e) {
    cout << e << " ";
}

int main(){
    LinkQueue Q;
    InitQueue(&Q);
    QElemType e;
    cout<<"请输入要入队的元素e:";
    cin>>e;
    while(e!=-1){
        EnQueue(&Q,e);
        cout<<"元素"<<e<<"入队成功。"<<'\n';
        if (GetHead_Q(Q, &e) == OK) {
		    cout << "当前队头元素为" << e << '\n';
		} else {
		    cout << "队列为空，无法获取队头元素" << '\n';
		}
        cout<<"当前队列的长度为"<<QueueLength(Q)<<'\n';
        cout<<"当前队列的元素为：";
        QueueTraverse(Q,PrintElem);
        cout<<"请输入要入队的元素e:";
        cin>>e;
    }
    cout<<"元素"<<e<<"入队失败。"<<'\n';
    DeQueue(&Q,&e);
    cout<<"元素"<<e<<"出队成功。"<<'\n';
    cout<<"当前队列的长度为"<<QueueLength(Q)<<'\n';
    cout<<"当前队列的元素为：";
    QueueTraverse(Q,PrintElem);
    if (GetHead_Q(Q, &e) == OK) {
		    cout << "当前队头元素为" << e << '\n';
	} else {
	    cout << "队列为空，无法获取队头元素" << '\n';
	}
    // 检查队列是否为空
    if (QueueEmpty(Q)) {
        cout << "队列为空。" << endl;
    } else {
        cout << "队列不为空。" << endl;
    }
    // 清空队列
    ClearQueue(&Q);
    cout << "清空后的队列内容: ";
    QueueTraverse(Q, PrintElem); // 打印队列内容

    // 销毁队列
    DestroyQueue(&Q);

    return 0;
}