//题目
//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印一行

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
#include<vector>
#include<queue>
using namespace std;
class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode *root){
        if(root == nullptr) return {};
        vector<vector<int>> result;
        queue<TreeNode *> que;
        que.push(root);
        que.push(nullptr);
        while(!que.empty()){
            TreeNode * node = que.front();
            vector<int> temp;
            while(node != nullptr){
                que.pop();
                temp.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                node = que.front();
            }
            que.pop();
            result.push_back(temp);
            if(!que.empty())//queue里必须要有东西才加nullptr
                que.push(nullptr);

        }
        return result;
    }
};