//题目
//请实现函数complexListNode* Clone(ComplexListNode *pHead),复制一个复杂链表。
//在复杂链表中，每个节点除了有一个m_pNext指针指向下一个节点，还有一个m_pSibling指针指向链表中的任意
//节点或者nullptr。节点的C++定义如下：
struct ComplexListNode
{
    int m_nValue;
    ComplexListNode *m_pNext;
    ComplexListNode *m_pSibling;
    ComplexListNode (int x): m_nValue(x),m_pNext(nullptr),m_pSibling(nullptr){}
};
//算法1(我的想法)
//时间O(n),空间O(n)
//使用map记录指针和下标位置，不是最优解

//算法2
//时间O(n),空间O(1)
//1.先复制原节点，更新next,将新节点串接在原节点后面
//2.更新subling
//3.还原next,复原两个链表
//书本版本
void dupList(ComplexListNode *head)
{
    ComplexListNode *pNode = head;
    while(pNode != nullptr){
        ComplexListNode *pNewNode = new ComplexListNode(pNode->m_nValue);
        pNewNode->m_pNext = pNode->m_pNext;
        pNode->m_pNext = pNewNode;
        pNode = pNewNode->m_pNext; 
    }
}

void updateSibling(ComplexListNode *head)
{
    ComplexListNode *pNode = head;
    ComplexListNode *pAfter = pNode->m_pNext;
    while(pNode != nullptr){
        pAfter->m_pSibling = pNode->m_pSibling->m_pNext;
        pNode = pAfter->m_pNext;
        if(pNode !=nullptr) pAfter = pNode->m_pNext;
    }
}

ComplexListNode* resumeList(ComplexListNode *head)
{
    ComplexListNode* pNode = head;
    ComplexListNode* pCloneHead = head->m_pNext;
    ComplexListNode* pCloneNode = pCloneHead;
    while(pNode != nullptr){
        pNode->m_pNext = pCloneNode->m_pNext;
        pNode = pCloneNode->m_pNext;
        if(pNode != nullptr) pCloneNode = pNode->m_pNext;
    }   
    return pCloneHead;
}
ComplexListNode* clone( ComplexListNode *head)
{
    if(head == nullptr) return nullptr;
    dupList(head);
    updateSibling(head);
    return resumeList(head);
}

//LeetCode版本
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val){
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution{
public:
    void dupList(Node *head){
        Node *pNode = head;
        while(pNode != nullptr){
            Node *pNewNode = new Node(pNode->val);
            pNewNode->next = pNode->next;
            pNode->next = pNewNode;
            pNode = pNewNode->next;
        }
    }
    void updateRandom(Node *head){
        Node *pNode = head;
        Node *pBackNode = pNode->next;
        while(pNode != nullptr){
            if(pNode->random == nullptr){
                pBackNode->random = nullptr;
            }else{
                pBackNode->random = pNode->random->next;
            }
            pNode = pBackNode->next;
            if(pNode != nullptr) pBackNode = pNode->next;
        }
    }
    Node* resumeList(Node *head){
        Node *pNode = head;
        Node *pCloneHead = pNode->next;
        Node *pCloneNode = pCloneHead;
        while(pNode != nullptr){
            pNode->next = pCloneNode->next;
            pNode = pCloneNode->next;
            if(pNode != nullptr){
                pCloneNode->next = pNode->next;
                pCloneNode = pNode->next;
            }
        }
        return pCloneHead;
    }
    Node* copyRandomList(Node *head){
        if(head == nullptr ) return nullptr;
        dupList(head);
        updateRandom(head);
        return resumeList(head);
    }
};