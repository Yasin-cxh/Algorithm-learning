//题目
//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

//算法1：递归
class Solution{
public:
ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
    ListNode *pHead;
    if(l1->val <= l2->val){
        pHead = l1;
        pHead->next = mergeTwoLists(l1->next,l2);
    }else{
        pHead = l2;
        pHead->next = mergeTwoLists(l1,l2->next);
    }
    return pHead;
}
};

//算法2：双指针
class Solution1{
public:
    ListNode* mergerTwoLists(ListNode *l1, ListNode *l2){
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode *pNode = new ListNode(1);
        ListNode *pHead = pNode;
        ListNode *pL1Cur = l1, *pL2Cur = l2;
        while(pL1Cur != nullptr && pL2Cur != nullptr){
            if(pL1Cur->val <= pL2Cur->val){
                pNode->next = pL1Cur;
                pNode = pL1Cur;
                pL1Cur = pL1Cur->next;
            }else{
                pNode->next =pL2Cur;
                pNode = pL2Cur;
                pL2Cur = pL2Cur->next;
            }
        }
        if(pL1Cur == nullptr){
            pNode->next = pL2Cur;
        }
        if(pL2Cur == nullptr){
            pNode->next = pL1Cur;
        }
        return pHead->next;
    }
};