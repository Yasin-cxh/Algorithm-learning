//题目
//如果一个链表中包含环，如何找出环的入口节点？
//算法：
//判断有环：双指针，一块一慢，如果有环，则两个指针一定会相遇
//判断环的长度：找到相遇的指针，直到下一次回到原地，循环计数
//判断环入口：双指针，前面的指针先走环长步，两个指针再同步前进，当两个指针相等时，当前指针即为环的入口
struct ListNode
{
    int val;
    ListNode *next;
};

ListNode* FindMeeting(ListNode *head)
{
    if(head->next == nullptr) return nullptr;
    ListNode *pSlow = head;
    ListNode *pFast = head->next;
    while(1){
        if(pSlow == pFast) return pSlow;
        if(pSlow == nullptr || pSlow->next == nullptr) return nullptr;
        else pSlow = pSlow->next;
        if(pFast == nullptr || pFast->next == nullptr || pFast->next->next == nullptr ) return nullptr;
        else pFast = pFast->next->next;
    }
}

ListNode* FindEntryNode(ListNode *head)
{
    if(head == nullptr) return nullptr;
    ListNode *meetingNode = FindMeeting(head);
    if(meetingNode == nullptr) return nullptr;
    ListNode *temp = meetingNode->next;
    int ringCount = 1;
    while(temp != meetingNode){
        ++ringCount;
        temp = temp->next;
    }
    ListNode *pAhead = head, *pBehind = head;
    for(int i = 0 ; i< ringCount; ++i){
        pAhead = pAhead->next;
    }

    while(pAhead != pBehind){
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }
    return pBehind;   
}