//题目
//给定一棵二叉树和其中的一个节点，如何找出中序遍历的下一个节点？
//树中的节点除了有两个分别指向左、右节点的指针，还有一个指向父节点的指针

/*
* 考察中序遍历的特点 分三种情况
* 1.该节点有右子树，则返回右子树的最左节点
* 2.该节点没有右子树，且是其父节点的左节点，则返回其父节点
* 3.该节点没有右子树，且是其父节点的右节点，找到祖先节点，该祖先节点是其父节点的左节点，返回该祖先节点的父节点
* 2，3 的情况其实是一样的
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent
};
//树的中序遍历怎么实现？
void inorder(TreeNode *node)
{
    if(TreeNode == nullptr) return;
    inorder(node->left);
    //dosomething
    inorder(noder->right);
}

TreeNode * findNext(TreeNode *node)
{
    if(node == nullptr || node->parent == nullptr) return nullptr;
    TreeNode *result = nullptr;
    if(node->right != nullptr){
        TreeNode *temp = node->right;
        if(temp->left != nullptr)
            temp = temp->left;
        result = temp;
    }
    else{
        TreeNode *pCurrent = node;
        TreeNode *pParent = node->parent;
        while(pParent != nullptr && pCurrent == pParent->right){
            pCurrent = pParent;
            pParent = pParent->parent;
        }
        result = pParent;
    }
    return result;
}