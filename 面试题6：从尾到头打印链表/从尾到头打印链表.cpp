//题目：输入一个链表的头节点，从尾到头反过来打印出每个节点的值。链表节点定义如下：
struct ListNode
{
 int m_nKey;
 ListNode* m_pNext;
};

#include <stack>
//算法一：采用stack
//时间：O(n) 空间：O(n)
//书本版本
void reverseList( ListNode *pHead)
{
    if(pHead == nullptr) return;
    std::stack<ListNode *> nodes;
    ListNode *pNode =pHead;
    while(pNode != nullptr)
    {
        stack.push(pNode);
        pNode = pNode->next;
    }

    while(!stack.empty())
    {
        pNode = nodes.top();
        printf("%d\t",pNode->m_nKey);
        nodes.pop();
    }
}
//LeetCode版本
class Solution{
public:
    vector<int> reversePrint(ListNode *head){
        vector<int> result;
        if(head == nullptr)
            return result;
        std::stack<ListNode*> nodes;
        ListNode* node = head;
        while(node != nullptr){
            nodes.push(node);
            node = node->next;
        }

        while(!nodes.empty()){
            node = nodes.top();
            result.push_back(node->val);
            nodes.pop();
        }
        return result;
    }
};

//算法二：使用递归
//时间：O(n),空间:O(n)?
//书本版本
void reverseList_recursion(ListNode *pHead)
{
    if(pHead == nullptr)
        return;
    ListNode *pNode = pHead;
    PrintRecursion(pNode);
}

void PrintRecursion(ListNode *pNode)
{
    if(pNode->next == nullptr){
        print("%d\t",pNode->m_nKey);
    } else {
        PrintRecursion(pNode->next);
        print("%d\t",pNode->m_nKey);
    }
}

//LeetCode版本
class Solution{
public:
void PrintRecursion(vector<int> &vec, ListNode *pNode){
    if(pNode->next == nullptr){
        vec.push_back(pNode->val);
    } else {
        PrintRecursion(vec, pNode->next);
        vec.push_back(pNode->val);
    }
}
vector<int> reversePrint(ListNode* head){
    vector<int> result;
    if(head == nullptr)
        return result;
    ListNode *pNode = head;
    PrintRecursion(result, pNode);
    return result;
}

};