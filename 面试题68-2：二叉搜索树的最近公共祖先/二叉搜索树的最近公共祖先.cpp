//题目
//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//普通的二叉树找公共祖先
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 //先找从根节点到目标节点的路径
 //寻找路径最后的公共节点
 #include<vector>
 using namespace std;
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode *target, vector<TreeNode*> &vec){
        if(root == nullptr) return false;
        if(root == target) return true;
        vec.push_back(root);
        bool lfind = findPath(root->left,target,vec);
        bool rfind = findPath(root->right,target,vec);
        if(!lfind && !rfind) vec.pop_back();
        return lfind || rfind;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        findPath(root,p,path1);
        path1.push_back(p);
        findPath(root,q,path2);
        path2.push_back(q);
        TreeNode* res ;
        int idx = 0;
        while(idx < path1.size() && idx < path2.size()){
            if(path1[idx] == path2[idx]){
                res = path1[idx];
            }
            idx ++;
        }
        return res;

    }
};
//k神版
//太妙，后序遍历可以保证深度最深
//太妙了
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;        
    }
};