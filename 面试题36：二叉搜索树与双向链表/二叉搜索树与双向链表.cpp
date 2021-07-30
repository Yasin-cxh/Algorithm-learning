//题目
//输入一颗二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
//要求不能创建任何新的节点，只能调整树中心节点指针的指向。

//因为要求是有序的，采用中序遍历的形式
//左子树指向前一个数字，右子树指向后一个数字，因此，递归的时候需要保存前一个节点的指针
//直接上LeetCode版本
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(){}
    Node(int _val){
        val = _val;
        left = nullptr;
        right = nullptr;
    }
    Node(int _val, Node *_left, Node *_right){
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution{
public:
    void inorder(Node *root, Node* pre){
        if(root == nullptr) return;
        inorder(root->left, pre);
        if(pre != nullptr) pre->right = root;
        root->left = pre;
        inorder(root->right,root);
    }
    Node* treeToDoublyList(Node *root){
        if(root == nullptr) return nullptr;
        Node *listHead = root;
        while(listHead != nullptr){
            if(listHead->left == nullptr)break;
            listHead = listHead->left;
        }
        Node *listEnd = root;
        while(listEnd != nullptr ){//这么写居然会有问题！编译器不知道listEnd->right是不是nullptr,即使你是短路的写法，在LeetCode上也是不行的
            if(listEnd->right == nullptr) break;
            listEnd = listEnd->right;
        }
        inorder(root,nullptr);
        listHead->left = listEnd;
        listEnd->right = listHead;
        return listHead;
    }
};

//看了K神的解法自己写一遍
class Solution1{
public:
    Node* treeToDoublyList(Node *root){
        if(root == nullptr) return nullptr;
        inorder(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
private:
    Node *head, *pre;
    void inorder(Node *root){
        if(root == nullptr) return;
        inorder(root->left);
        if(pre != nullptr) pre->right = root;
        else head = root;
        root->left = pre;
        pre = root;
        inorder(root->right);
    }
};