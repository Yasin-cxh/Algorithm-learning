//题目
//请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
//例如，二叉树 [1,2,2,3,4,4,3] 是对称的。



//LeetCode版本
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//如果是对称的，前序遍历(父，左，右) 和 前序对称遍历(父，右，左)的结果是一样的
class Solution{
public:
    bool isSymmetricCore(TreeNode *root1, TreeNode *root2){
        if(root1 == nullptr && root2 == nullptr) return true;
        if(root1 ==nullptr || root2 == nullptr) return false;
        return root1->val == root2->val && isSymmetricCore(root1->left,root2->right) && isSymmetricCore(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode *root){
         if(root == nullptr) return true;//空树默认是对称的,这种边界问题要和面试官商量好，或者使用测试用例测试
         return isSymmetricCore(root->left,root->right);
    }
};