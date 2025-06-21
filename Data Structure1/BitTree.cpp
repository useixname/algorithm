#include <iostream>
using namespace std;
 
// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
// 二叉树类定义
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { destroy(root); }
 
    // 插入节点
    void insert(int val) {
        insert(root, val);
    }
 
    // 删除节点
    void remove(int val) {
        remove(root, val);
    }
 
    // 查找节点
    bool find(int val) {
        return find(root, val);
    }
 
    // 前序遍历
    void preOrder() {
        preOrder(root);
    }
 
    // 中序遍历
    void inOrder() {
        inOrder(root);
    }
 
    // 后序遍历
    void postOrder() {
        postOrder(root);
    }
 
private:
    TreeNode* root;
 
    // 插入节点
    void insert(TreeNode*& node, int val) {
        if (node == nullptr) {
            node = new TreeNode(val);
        } else if (val < node->val) {
            insert(node->left, val);
        } else if (val > node->val) {
            insert(node->right, val);
        }
    }
 
    // 删除节点
    void remove(TreeNode*& node, int val) {
        if (node == nullptr) {
            return;
        } else if (val < node->val) {
            remove(node->left, val);
        } else if (val > node->val) {
            remove(node->right, val);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                TreeNode* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node;
                node = node->left;
                delete temp;
            } else {
                TreeNode* temp = findMin(node->right);
                node->val = temp->val;
                remove(node->right, temp->val);
            }
        }
    }
 
    // 查找节点
    bool find(TreeNode* node, int val) {
        if (node == nullptr) {
            return false;
        } else if (val < node->val) {
            return find(node->left, val);
        } else if (val > node->val) {
            return find(node->right, val);
        } else {
            return true;
        }
    }
 
    // 查找最小节点
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
 
    // 前序遍历
    void preOrder(TreeNode* node) {
        if (node != nullptr) {
            cout << node->val << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
 
    // 中序遍历
    void inOrder(TreeNode* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->val << " ";
            inOrder(node->right);
        }
    }
 
    // 后序遍历
    void postOrder(TreeNode* node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->val << " ";
        }
    }
 
    // 销毁节点
    void destroy(TreeNode* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
};

// 测试代码
int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
 
    cout << "前序遍历: ";
    tree.preOrder();
    cout << endl;
 
    cout << "中序遍历: ";
    tree.inOrder();
    cout << endl;
 
    cout << "后序遍历: ";
    tree.postOrder();
    cout << endl;
 
    cout << "查找节点 4: " << (tree.find(4) ? "存在" : "不存在") << endl;
 
    tree.remove(3);
    cout << "删除节点 3 后的中序遍历: ";
    tree.inOrder();
    cout << endl;
 
    return 0;
}