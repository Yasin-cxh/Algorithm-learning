//题目
//请实现两个函数，分别用来序列化和反序列化二叉树
//你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列/反序列化算法执行逻辑
//你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
//书本版本
#include<iostream>
using namespace std;
void serialize(TreeNode *root, ostream &output)
{
    if(root == nullptr){
        output<<"$,";
        return;
    }
    output<<root->val<<",";
    serialize(root->left, output);
    serialize(root->right,output);
}
void Deserialize(TreeNode **pRoot,istream &input)
{
    int number;
    if(ReadStream(input,&number)){
        *pRoot = new TreeNode(number);
        Deserialize(&((*pRoot)->left),input);
        Deserialize(&((*pRoot)->right),input);//不该省括号的地方不要省，(*pRoot->left) != ((*pRoot)->left)
    }
}

//LeetCode 版本
//LeetCode 使用的是层序遍历
#include<queue>
#include<string>
using namespace std;
class Codec{
public:
    string serialize(TreeNode *root){
        if(root == nullptr) return "";
        TreeNode *pNode;
        string result;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            pNode = que.front();
            que.pop();
            result += to_string(pNode->val);
            result +=',';
            if(pNode->left != nullptr){ 
                que.push(pNode->left);
            } else{
                result += "$,";
            }
            if(pNode->right != nullptr){ 
                que.push(pNode->right);
            } else {
                result += "$,";
            }
        }
        return result;
    }

    TreeNode* Deserialize(string data){
        if(data.empty()){
            return nullptr;
        }
        queue<TreeNode *>que;
        TreeNode *pNode = new TreeNode(1);
        que.push(pNode);
        string::size_type findIdx = data.find(",");
        string::size_type beginIdx = 0;
        while(findIdx != string::npos){
            string temp = data.substr(beginIdx,findIdx-beginIdx);
            if(temp == "$"){
                que.pop();
                continue;
            }
            TreeNode *ptemp = que.front();
            que.pop();
           if(ptemp != nullptr) ptemp->val = std::stoi(temp);
            que.push(ptemp->left);
            que.push(ptemp->right);
            beginIdx = findIdx + 1;
            findIdx = data.find(",",beginIdx);

        }

        return pNode;
    }
};

//修改版
#include<sstream>
class Solution1
{
public:
string serialize(TreeNode *root){
    if(root == nullptr) return "";
    queue<TreeNode *> que;
    que.push(root);
    ostringstream output;
    while(!que.empty()){
        TreeNode *pNode = que.front();
        que.pop();
        if(pNode == nullptr){
            output<<"$,";
        }
        else {
        output<<pNode->val<<',';
        que.push(pNode->left);
        que.push(pNode->right);
        }
    }
    return output.str();
}
TreeNode* Deserialize(string data){
    if(data.empty()) return nullptr;
    queue<TreeNode **>que;
    TreeNode *pNode = nullptr;
    que.push(&pNode);
    string::size_type beginIdx = 0;
    string::size_type findIdx = data.find(",",beginIdx);
    while(findIdx != string::npos){
        string temp = data.substr(beginIdx,findIdx-beginIdx);
        if(temp == "$"){
            que.pop();
        } else{
            TreeNode **pTemp = que.front();
            que.pop();
            *pTemp = new TreeNode(stoi(temp));
            (*pTemp)->left = nullptr;
            (*pTemp)->right = nullptr;
            que.push(&((*pTemp)->left));
            que.push(&((*pTemp)->right));
        }
        beginIdx = findIdx + 1;
        findIdx = data.find(",",beginIdx);
    }
        return pNode;
}
};