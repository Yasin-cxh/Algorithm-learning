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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        ostringstream output;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            TreeNode *node = que.front();
            que.pop();
            if(node == nullptr){
                output<<"$,";
            }else{
                output<<node->val<<",";
                que.push(node->left);
                que.push(node->right);
            }
        }
        return output.str();

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")return nullptr;
        size_t beginidx = 0;
        size_t findidx =0;
        queue<TreeNode**> que;//这里用**的原因是为了方便找到root
        TreeNode* root;
        que.push(&root);
        findidx = data.find(",",beginidx);
        while(findidx != string::npos){
            string temp = data.substr(beginidx,findidx-beginidx);
            if(temp == "$"){
                que.pop();
            }else{
                TreeNode** node = que.front();
                que.pop();
                *node = new TreeNode(stoi(temp));//这里要使用stoi而不是atoi,因为参数不同
                que.push(&(*node)->left);
                que.push(&(*node)->right);
            }
            beginidx = findidx + 1;
            findidx = data.find(",",beginidx);
        }
        return root;
    }
};