//题目
//输入一颗二叉树和一个整数，打印出二叉树中节点值和为输入整数的所有路径。
//从树的根节点开始一直到叶节点所经过的节点形成一条路径

//一定是要根节点到叶节点
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (){}
    TreeNode (int x):val(x),left(nullptr),right(nullptr){}
    TreeNode (int x ,TreeNode *left, TreeNode *right):val(x),left(left),right(right){}
};
class Solution{
public:
    void preOrder(TreeNode *root, vector<int> &curPath, vector<vector<int>> &result, int &curSum, int target){
        if(root == nullptr) return;
        int curVal = root->val;
        //if(curVal + curSum > target) return;//这里默认都是正数，忽略target可能是负数的情况
        if(curVal + curSum == target && root->left == nullptr && root->right == nullptr){
            curPath.push_back(curVal);
            result.push_back(curPath);
            curPath.pop_back();
            return;
        }
        curPath.push_back(curVal);
        curSum += curVal;
        preOrder(root->left,curPath,result,curSum,target);
        preOrder(root->right,curPath,result,curSum,target);
        curSum -= curVal;
        curPath.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int target){
        if(root == nullptr)return {};
        vector<vector<int>> result;
        vector<int> curPath;
        int curSum = 0;
        preOrder(root,curPath,result,curSum,target);
        return result;
    }
};