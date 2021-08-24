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

class Solution {
public:
    void conversion(Node *root){
        if(root == nullptr) return ;
        conversion(root->left);
        if(pre!= nullptr) pre->right = root;
        else head = root;
        root->left = pre;
        pre = root;
        conversion(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        conversion(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
private:
    Node *head = nullptr, *pre = nullptr;
};