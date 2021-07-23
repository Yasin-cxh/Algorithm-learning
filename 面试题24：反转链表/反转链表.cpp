//题目
//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后的头节点
//算法1：使用栈
#include<stack>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
};
class Solution{
public:
ListNode* reverseList(ListNode* head){
    stack<ListNode*> stk;
    ListNode *pNode = head;
    ListNode *pReverseHead = head;
    ListNode *pPre = head;
    while(pNode != nullptr){
        stk.push(pNode);
        pNode = pNode->next;
    }
    if(stk.size() >0){
        pReverseHead = stk.top();
        pPre = pReverseHead;
        stk.pop();
    }
    while(stk.size()>0){
        pNode = stk.top();
        pPre->next = pNode;
        pPre = pNode;
        stk.pop();
    }
    if(pPre != nullptr)
        pPre->next = nullptr;
    return pReverseHead;
}
};
//算法2：三指针法
class Soluton1{
public:
ListNode* reverseList(ListNode *head)
{
    if(head == nullptr) return head;
    ListNode *pPre = nullptr , *pCur = head, *pNext;
    ListNode *pReverseHead;
    while(pCur != nullptr){
        pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }
    pReverseHead = pPre;
    return pReverseHead;
}
};