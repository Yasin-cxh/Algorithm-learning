//题目删除链表的节点
//给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内删除该节点。链表节点与函数的定义如下：
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
//思路
//算法1：顺序遍历前序节点
//时间O(n)

//算法2：将待删除节点下一个节点赋值给删除节点，删除下一个节点
//时间:((n-1)O(1)+O(n))/n -> O(1)
//书本内容
void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
    if(pListHead == nullptr || pToBeDeleted == nullptr) return;
    if(pToBeDeleted->m_pNext != nullptr){
        ListNode *pNode = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNode->m_nValue;
        pToBeDeleted->m_pNext = pNode->m_pNext;
        delete pNode;
        pNode = nullptr;
    }
    else if(pToBeDeleted == *pListHead){
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;//是*pListHead 不是pListHead
    }
    else{
        ListNode *preNode = *pListHead;
        while(preNode->m_pNext != pToBeDeleted){
            preNode = preNode->m_pNext;
        }
        preNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
    return ;
}

//LeetCode版本
//LeetCode版本变简单了，双指针可以解决
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(val == head->val) return head->next;
        ListNode *preNode = head;
        ListNode *pNode = head->next; 
        while(pNode->val != val){
            preNode = preNode->next;
            pNode = pNode->next;
        }
        preNode->next = pNode->next;
        delete pNode;
        return head;
    }
};