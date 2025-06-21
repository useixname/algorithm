#include <iostream>
using namespace std;

//二叉排序树结点
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

// 在二叉排序树中搜索关键字为key的结点
BSTNode* BSTSearch(BSTree T, int key) {
    if (T == NULL || T->key == key)
        return T;
    if (key < T->key)
        return BSTSearch(T->lchild, key);
    else
        return BSTSearch(T->rchild, key);
}

// 在二叉排序树中查找最小值结点
BSTNode* findMin(BSTree T) {
    if (T == NULL)
        return NULL;
    else if (T->lchild == NULL)
        return T;
    else
        return findMin(T->lchild);
}

// 删除结点z
void BST_Delete(BSTree &T, int key) {
    if (T == NULL)
        return;
    else if (key < T->key)
        BST_Delete(T->lchild, key);
    else if (key > T->key)
        BST_Delete(T->rchild, key);
    else {
        // 找到了要删除的结点
        if (T->lchild && T->rchild) {
            // 如果有两个子节点
            BSTNode* minRight = findMin(T->rchild); // 找到右子树的最小值结点
            T->key = minRight->key; // 用右子树的最小值替换当前结点
            BST_Delete(T->rchild, minRight->key); // 删除右子树的最小值结点
        } else {
            // 如果只有一个子节点或者是叶子结点
            BSTNode* temp = T;
            if (T->lchild == NULL) // 如果只有右子树或者是叶子结点
                T = T->rchild;
            else if (T->rchild == NULL) // 如果只有左子树
                T = T->lchild;
            free(temp); // 释放删除结点的内存
        }
    }
}

//在二叉排序树插入关键字为k的新结点（递归实现）
int BST_Insert(BSTree &T,int k){
    //原树为空，新插入的结点为根结点
    if(T==NULL){
        T=(BSTree)malloc(sizeof(BSTNode));
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;
    }
    else if(k==T->key) //树中存在相同关键字的结点，插入失败
        return 0;
    else if(k<T->key) //插入到T的左子树
        return BST_Insert(T->lchild,k);
    else //插入到T的右子树
        return BST_Insert(T->rchild,k);
}

//按str[]中的关键字序列建立二叉树
void Creat_BST(BSTree &T,int str[],int n){
    T=NULL;
    int i=0;
    //依次将每个关键字插入到二叉排序树中
    while(i<n){
        BST_Insert(T,str[i]);
        i++;
    }
}

// 中序遍历打印二叉排序树
void InOrder(BSTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        cout << T->key << " ";
        InOrder(T->rchild);
    }
}

int main() {
    BSTree T = NULL;

    // 插入操作测试
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    Creat_BST(T, arr, n);

    cout << "Binary Search Tree (Inorder): ";
    InOrder(T);
    cout << endl;

    // 搜索操作测试
    int searchKey = 40;
    BSTNode* searchResult = BSTSearch(T, searchKey);
    if (searchResult != NULL)
        cout << "Key " << searchKey << " found in the tree." << endl;
    else
        cout << "Key " << searchKey << " not found in the tree." << endl;

    // 删除操作测试
    int deleteKey = 30;
    cout << "Deleting key " << deleteKey << endl;
    BST_Delete(T, deleteKey);

    cout << "Binary Search Tree after deletion: ";
    InOrder(T);
    cout << endl;

    return 0;
}