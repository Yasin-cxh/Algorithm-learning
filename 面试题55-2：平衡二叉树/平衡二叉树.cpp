//题目
//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
//如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树.

#include<algorithm>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

//从上到下的写法
class Solution {
public:
    int subTreeDepth(TreeNode *root){
        if(root == nullptr) return 0;
        int leftDepth = subTreeDepth(root->left);
        int rightDepth = subTreeDepth(root->right);
        return max(leftDepth,rightDepth)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int leftDepth =subTreeDepth(root->left);
        int rightDepth = subTreeDepth(root->right);
        if(abs(leftDepth-rightDepth) >1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};

//后序遍历的写法
//在后序遍历过程中维护depth变量，比较左右子树的深度
class Solution1 {
public:
    bool isbalanced(TreeNode *root, int &depth){
        if(root == nullptr){
            depth = 0;
            return true;
        }
        int ldepth,rdepth;
        bool lb = isbalanced(root->left,ldepth);
        bool rb = isbalanced(root->right,rdepth);
        if(lb&&rb){
            if(abs(ldepth-rdepth) <=1){
                depth = max(ldepth,rdepth)+1;
                return true;
            }
        }
        return false;

    }
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isbalanced(root,depth);
    }
};

//后序遍历
//如果不是平衡树返回-1，是平衡树返回树高
class Solution2 {
public:
    int subTreeDepth(TreeNode *root){
        if(root == nullptr) return 0;
        int ld = subTreeDepth(root->left);
        if(ld == -1) return -1;
        int rd = subTreeDepth(root->right);
        if(rd == -1) return -1;
        return abs(ld-rd)<=1?max(ld,rd)+1:-1;
    }
    bool isBalanced(TreeNode* root) {
        return subTreeDepth(root) != -1;
    }
};