//题目
//输入两颗二叉树A和B，判断B是不是A的子结构。二叉树节点的定义如下
struct BinaryTreeNode
{
    double m_dbValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

//书本版本
bool Equal(double val1, double val2)
{
    if(val1 - val2 < 0.000001 && val1 - val2 > -0.000001){
        return true;
    }
    else{
        return false;
    }
}

bool CheckStructure(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
    if(root2 == nullptr) return true;
    if(root1 == nullptr) return false;
    bool result = false;
    if(Equal(root1->m_dbValue,root2->m_dbValue)){
        result = true;
    }
    return result && CheckStructure(root1->m_pLeft,root2->m_pLeft) && CheckStructure(root1->m_pRight,root2->m_pRight);


}

bool IsSubStructure(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
    if (root1 == nullptr || root2 == nullptr) return false;
    bool result = false;
    if(Equal(root1->m_dbValue, root2->m_dbValue)){
        result = CheckStructure(root1,root2);
    }
    if(!result){
        result = IsSubStructure(root1->m_pLeft, root2);
    }
    if(!result){
        result = IsSubStructure(root1->m_pRight,root2);
    }
    return result;
}

//LeetCode版本
struct TreeNode{
    int val;//是int啊，那没事了
    TreeNode *left;
    TreeNode *right;
};

class Solution{
public:
    bool CheckStructure(TreeNode *A, TreeNode *B){
        if(B == nullptr) return true;
        if(A == nullptr) return false;
        bool result = false;
        if(A->val == B->val) result = true;
        return result && CheckStructure(A->left,B->left) && CheckStructure(A->right,B->right);
    }
    bool isSubStructure(TreeNode *A, TreeNode *B){
        if(A == nullptr || B == nullptr) return false;//因为LeetCode题目规定了空树不是任何一棵树的子树
        bool result = false;
        if(A->val == B->val){
            result = CheckStructure(A,B);
        }
        if(!result){
            result = isSubStructure(A->left,B);
        }
        if(!result){
            result = isSubStructure(A->right,B);
        }
        return result;
    }
};

//LeetCode 简化版
class Solution{
public:
    bool CheckStructure(TreeNode *A, TreeNode *B){
        if(B == nullptr) return true;//到叶节点了
        if(A == nullptr) return false;
        return A->val == B->val && CheckStructure(A->left,B->left) && CheckStructure(A->right,B->right);
    }
    bool isSubStructure(TreeNode *A, TreeNode *B){
        if(A == nullptr || B == nullptr) return false;
        return CheckStructure(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
};