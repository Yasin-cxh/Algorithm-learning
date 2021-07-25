//题目
//请完成一个函数。输入一颗二叉树，该函数输出它的镜像。二叉树节点的定义如下：
struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
    BinaryTreeNode(){}
    BinaryTreeNode(int x):m_nValue(x),m_pLeft(nullptr),m_pRight(nullptr){}
};

BinaryTreeNode *pTest0 =new BinaryTreeNode;
BinaryTreeNode *pTest1 =new BinaryTreeNode();
BinaryTreeNode *pTest2 =new BinaryTreeNode(5);

//书本版本
BinaryTreeNode* Mirror(BinaryTreeNode *root)
{
    if(root == nullptr) return root;
    Mirror(root->m_pLeft);
    Mirror(root->m_pRight);
    BinaryTreeNode *pNode = root->m_pLeft;
    root->m_pLeft = root->m_pRight;
    root->m_pRight = pNode;
    return root;
}

//LeetCode版本
//前序遍历
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
TreeNode *mirrorTree(TreeNode *root){
    if(root == nullptr) return root;
    mirrorTree(root->left);
    mirrorTree(root->right);
    TreeNode *pNode = root->left;
    root->left = root->right;
    root->right = pNode;
    return root;
}
};