#include<stdio.h>
#include<stdlib.h>
#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*Linklist;

bool InitList(Linklist &L){
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    return true;
}

bool Insert(Linklist &L,int i,int e){
    LNode *p=L;
    int j=0;
    while(p->next!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    LNode *s=(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next->next;
    p->next=s;
    return true;
}

bool Delete(Linklist &L,int i,int &e){
    LNode *p=L;
    int j=0;
    while(p->next!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p->next==NULL||j>i-1){
        return false;
    }
    LNode *q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}

bool Insert_Head(Linklist &L){
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    int n;
    scanf("%d",&n);
    while(n--){
        ElemType x;
        scanf("%d",&x);
        LNode *s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
    }
    return true;
}

bool Insert_Tail(Linklist &L){
    L=(LNode*)malloc(sizeof(LNode));//L是头节点
    LNode *r=L;//r是尾指针
    int n;
    scanf("%d",&n);
    while(n--){
        ElemType x;
        scanf("%d",&x);
        LNode *s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;  
    }
    r->next=NULL;
    return true;
}

int GetLength(Linklist L){
    int l=0;
    LNode *p=L;
    while(p->next!=NULL){
        p=p->next;
        l++;
    }
    return l;
}

LNode *FindByValue(Linklist L,int value){
    LNode *p=L;
    while(p!=NULL&&p->data!=value){
        p=p->next;
    }
    return p;
}

LNode *FindByIndex(Linklist L,int i,int &e){
    LNode *p=L;
    int j=0;
    while(p!=NULL&&j<i){
        p=p->next;
        j++;
    }
    return p;
}

void reverse(Linklist &L){
    // 如果链表为空或只有一个节点，不用动
    if (L == nullptr || L->next == nullptr) {
        return;
    }

    LNode *prev = nullptr;   // 已反转部分的“尾部”（初始时为空）
    LNode *cur  = L;         // cur 指向当前要处理的节点（最开始是原来的头）
    LNode *next = nullptr;   // 暂存 cur->next

    while (cur != nullptr) {
        next = cur->next;    // (1) 先记住 cur 的后继节点
        cur->next = prev;    // (2) 让 cur 断开指向后继，回头指向 prev
        prev = cur;          // (3) prev 移动到 cur：此时 prev 指向新“已反转链表”的新头
        cur = next;          // (4) cur 移动到下一待处理节点
    }

    // 循环结束时，prev 指向原链表最后一个节点，也就是反转后的“新头”
    L = prev;                // 更新外部传入的指针，让它指向反转后的头
}

void print(Linklist L){
    LNode *p=L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    Linklist L;
    Insert_Tail(L);
    print(L);
    reverse(L);
    print(L);
    return 0;
}