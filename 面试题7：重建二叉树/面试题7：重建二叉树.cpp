//题目
//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如，输入前序遍历序列{1,2,4,7,3,5,6,8} 和中序遍历序列{4,7,2,1,5,3,8,6}
//则重建如图2.6所示的二叉树并输出它的头节点。二叉树节点的定义如下:
struct BinaryTreeNode
{
    int  m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

//书本版本
//递归,递归遍历的终结条件是什么？
//输入 preorder 前序遍历数组指针， inorder 中序遍历数组指针， length 数组长度
//返回 根节点指针
BinaryTreeNode *Construct(int *preorder, int *inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0)
    return nullptr;

    return ConstructCore(preorder,preorder + length -1 ,inorder, inorder + length -1);
}

BinaryTreeNode *ConstructCore(int *startPreorder, int *endPreorder,
                              int *startInoder, int *endInorder)
{
    //前序遍历的第一个数字是根节点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft  = root->m_pRight = nullptr;

    if(startPreorder == endPreorder)//找到叶节点返回
    {
        if(startInorder == endInorder && *startPreorder == *startInorder)//叶节点的值应该是一样的
            return root;
        else
            throw std::exception("Invalid input");
    }
    //在中序遍历中找到根节点的值
    int *rootInorder = startInoder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++ rootInorder;
    if(rootInorder == endInoder && *rootInorder != rootValue)//这个条件是多余的
        throw std::exception("Invalid input");

    int leftLength = rootInorder - startInorder;
    int rightLength = endInorder - rootInorder;
    if(leftLength > 0)//构建左子树
    {
        root->m_pLeft = ConstructCore(startPreorder + 1,startPreorder + leftLength, startInorder, rootInorder -1);
    }
    if(rightLength > 0)//构建右子树
    {
        root->m_pRight = ConstructCore(startPreorder + leftLength + 1, endPreorder, rootInorder + 1, endInorder);
    }

    return root;//***重点，递归完左子树和右子树记得返回父节点
}



//LeetCode版本
class Solution
{
public:
    TreeNode* Construct(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd){
        TreeNode *root = new TreeNode();
        int rootVal = preorder[preStart];
        root->val = rootVal;
        root->left = root->right = nullptr;

        if(preStart == preEnd && inStart == inEnd && preorder[preStart] == inorder[inStart])
            return root;
        int inRoot = 0;
        while(inRoot <= inEnd && inorder[inRoot] != rootVal)
            ++inRoot;
        int leftLen = inRoot - inStart;
        int rightLen = inEnd - inRoot;
        if(leftLen > 0)
            root->left = Construct(preorder,preStart+1,preStart+leftLen,inorder,inStart,inRoot-1);
        if(rightLen > 0)
            root->right = Construct(preorder,preStart+leftLen+1,preEnd,inorder,inRoot+1,inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){
        int lengthPreorder = preorder.size();
        int lengthInorder = inorder.size();
        if(lengthPreorder == 0 || lengthInorder ==0 || lengthPreorder != lengthInorder)
            return nullptr;

        int preStart = 0, preEnd = lengthPreorder - 1;
        int inStart = 0, inEnd = lengthPreorder - 1;
        return Construct(preorder, preStart, preEnd, inorder, inStart, inEnd);
    }
};