//题目
//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
//第二层按照从右到左的顺序打印，第三层再按照从左到右的顺序打印，其他行以此类推 
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode *root){
        if(root == nullptr) return {};
        vector<vector<int>> result;
        stack<int>stk;
        bool right = false;
        queue<TreeNode *> que;
        que.push(root);
        que.push(nullptr);
        while(!que.empty()){
            TreeNode *pNode = que.front();
            vector<int> temp;
            while(pNode != nullptr){
                que.pop();
                if(right){
                    stk.push(pNode->val);
                }else{
                    temp.push_back(pNode->val);
                }
                if(pNode->left) que.push(pNode->left);
                if(pNode->right) que.push(pNode->right);
                pNode = que.front();
            }
            que.pop();
            if(right){
                while(!stk.empty()){
                    temp.push_back(stk.top());
                    stk.pop();
                }
            }
            right = !right;
            result.push_back(temp);
            if(!que.empty()){
                que.push(nullptr);
            }
        } 
        return result;
    }
};

//双辅助队列，辅助栈
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<TreeNode *> que;
        que.push(root);
        bool right = false;
        while(!que.empty()){
            queue<TreeNode*>level;
            vector<int> temp;
            stack<int> stk;
            while(!que.empty()){
                TreeNode * pNode = que.front();
                if(right) stk.push(pNode->val);
                else temp.push_back(pNode->val);
                if(pNode->left) level.push(pNode->left);
                if(pNode->right) level.push(pNode->right);
                que.pop(); 
            }
            if(right){
                while(!stk.empty()){
                    temp.push_back(stk.top());
                    stk.pop();
                }
            }
            res.push_back(temp);
            right = !right;
            que = level;
            
        }
        return res;
    }
};