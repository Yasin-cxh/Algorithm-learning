//题目 删除链表中重复的节点
//在一个排序的链表中，如何删除重复的节点？
//算法：双节点法
//时间：O(n) 空间：O(1)
struct ListNode
{
    int val;
    ListNode* next;
};

ListNode *DeleteDuplication(ListNode *head)
{
    if(head == nullptr) return nullptr;
    ListNode *pPre = head;
    ListNode *pCur = head->next;
    ListNode *pNode = nullptr;
    while(pCur != nullptr){
        if(pCur->val == pPre->val){
            pNode = pCur;
            pCur = pNode->next;
            delete pNode;
            pNode = nullptr;
        } else{
            pPre->next = pCur;
            pPre = pCur;
            pCur = pCur->next;
        }
    }
    pPre->next = nullptr;
    return head;   
}