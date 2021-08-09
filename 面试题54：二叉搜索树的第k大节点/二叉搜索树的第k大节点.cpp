//题目
//给定一颗二叉搜索树，请找出期中第k大的节点。
//思路，二叉搜索树的逆中序遍历能得到逆序序列



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 

class Solution {
public:
    void reInorder(TreeNode* root, int k){
        if(root == nullptr || count > k) return ;
        reInorder(root->right,k);
        if(++count == k) res = root->val;
        reInorder(root->left,k);
    }
    int kthLargest(TreeNode* root, int k) {
      reInorder(root, k);
      return res;
    }
private:
    int count = 0;
    int res = 0;
};