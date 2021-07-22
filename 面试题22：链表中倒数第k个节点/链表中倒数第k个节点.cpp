
//题目
//输入一个链表，输出该链表中倒数第K个节点。为了符合大多数人的习惯，本题从1开始计数，
//即链表的尾节点使倒数第一个节点

//算法：双指针
//考虑特殊情况：
//输入指针为nullptr
//k = 0
//k 大于节点数
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
};
class Solution{
public:
    ListNode* getKthFromEnd(ListNode* head,int k){
        if(head == nullptr || k == 0) return nullptr;
        ListNode *pahead = head, *pbehind = head;
        for(int i = 0; i < k; ++i){
            if(pahead == nullptr) return nullptr;
            pahead = pahead->next;
        }
        while(pahead != nullptr){
            pahead = pahead->next;
            pbehind = pbehind->next;
        }
        return pbehind;
    }
};