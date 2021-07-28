//题目
//输入一个整数数组，判断该数组是不是某二叉搜索树的后续遍历结果。结果是则返回true,否则返回false;
//假设输入的数组的任意两个数字都不相同。例如，输入数组{5,7,6,9,11,10,8},则返回true,因为这个整数数列
//是图中的后序遍历结果。如果输入的是{7,4,6,5},则由于没有哪棵二叉搜索树的后序遍历结果是这个序列，因此返回false。
//搜索二叉树的特性，左节点比根节点小，右节点比根节点大

//书本版本
bool VerifySquenceOfBST(int sequence[], int length){
    if(sequence == nullptr || length <= 0) return false;
    int root = sequence[length-1];
    int i = 0;
    for(;i<length-1;i++){
        if(sequence[i] > root)break;
    }
    int j = i;
    for(;j<length-1;j++){
        if(sequence[j] < root) return false;
    }
    bool left = true;
    if(i>0) left = VerifySquenceOfBST(sequence,i);
    bool right = true;
    if(i<length -1) VerifySquenceOfBST(sequence+i,length-1-i);
    return left && right;
}