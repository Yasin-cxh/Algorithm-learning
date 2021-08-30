//题目
//输入两个链表，找出它们的第一个公共节点
//1.遍历两遍
//第一遍获取两个链表的长度
//长的链表先走len1-len2距离
//如果遇到非空节点相同，就是第一个公共节点
#include<vector>
#include<string>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    int getListLength(ListNode *head){
        int len = 0;
        ListNode *pNode = head;
        while(pNode != nullptr){
            pNode = pNode->next;
            len++;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA= getListLength(headA);
        int lenB= getListLength(headB);
        int distance;
        ListNode *pShortHead, *pLongHead;
        if(lenA < lenB){
            pShortHead = headA;
            pLongHead = headB;
            distance  = lenB-lenA;
        }else{
            pShortHead = headB;
            pLongHead = headA;
            distance = lenA-lenB;
        }
        for(int i =0; i <distance; i++ ){
            pLongHead = pLongHead->next;
        }
        while(pLongHead != nullptr && pShortHead != nullptr && pLongHead != pShortHead){
            pLongHead = pLongHead->next;
            pShortHead = pShortHead->next;
        }
        return pLongHead;

    }
};
//简单写法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if(headA == nullptr || headB == nullptr) return nullptr;
            ListNode *n1 = headA, *n2 = headB;
            while(n1 != n2){
                n1 = n1==nullptr?headB:n1->next;
                n2 = n2==nullptr?headA:n2->next;
            }
            return n1;
    }
};