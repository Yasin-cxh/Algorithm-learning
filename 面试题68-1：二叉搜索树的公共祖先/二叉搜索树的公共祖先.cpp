//题目
//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if((root->val > p->val && root->val < q->val) && (root->val < p->val && root->val > q->val)) return root;
        if(root->val < p->val && root->val < q->val) lowestCommonAncestor(root->right,p,q);
        if(root->val > p->val && root->val > q->val) lowestCommonAncestor(root->left,p,q);
    }
};