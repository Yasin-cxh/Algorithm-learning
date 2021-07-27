//题目
//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
//LeetCode版本
#include<vector>
#include<queue>
using namespace std;
class Solution{
public:
    vector<int> levelOrder(TreeNode *root){
    if(root == nullptr) return {};
    queue<TreeNode *> que;
    vector<int> result;
    que.push(root);
    while(!que.empty()){
        TreeNode *node = que.front();
        result.push_back(node->val);
        if(node->left != nullptr) que.push(node->left);
        if(node->right != nullptr) que.push(node->right);
        que.pop();
    }   
    return result;    
 }
};