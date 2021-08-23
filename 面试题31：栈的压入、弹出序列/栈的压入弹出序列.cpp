//题目
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是不是该栈的弹出序列。
//假设压入栈的数字均不相等。例如，序列{1,2,3,4,5}是某栈的压栈序列，
//序列{4,5,3,2,1}是该压栈序列对应的一个弹出序列
//但{4,3,5,1,2}就不可能是该压栈序列的弹出序列。

//使用辅助栈
//若辅助栈为空，找到弹出序列的第一个数字，其在压入序列之前的数字，全部压栈
//若辅助栈不为空，且栈首和弹出栈栈首相同，两个栈首都弹出
//若辅助栈不为空，且栈首和弹出栈栈首不相同，在压入栈找到对应数字，将其之前的数字压入栈，若找不到，返回false
//若辅助栈为空，弹出栈也为空，返回true

//书本版本
//纯指针版本
#include<stdio.h>
#include<string.h>
#define ERRCODE 0
bool IsPopOrder(const int *pPush, const int *pPop, int length)
{
    if(pPush == nullptr || pPop == nullptr || length <= 0) return false;
    int *temp = new int[length];
    memset(temp,ERRCODE,length);
    int tempIdx = 0, pushIdx = 0, popIdx = 0;
    
    while (true)
    {
        if(tempIdx == 0){
            while(pPush[pushIdx] != pPop[popIdx]){
                temp[tempIdx++] = pPush[pushIdx++];
                if(pushIdx == length) return false; 
            }
            temp[tempIdx] = pPush[pushIdx];
        }
        if(temp[tempIdx] == pPop[popIdx]){
            temp[tempIdx] = ERRCODE;
            tempIdx --;
            popIdx ++;
            if(tempIdx == -1 && popIdx == length) return true;
            continue;
        }
        if(temp[tempIdx] != pPop[popIdx]){
            if(++pushIdx == length) return false;
            while(pPush[pushIdx] != pPop[popIdx]){
                temp[++tempIdx] = pPush[pushIdx++];
                if(pushIdx == length) return false;
            }
        }

    }
}

//LeetCode 版本
#include<vector>
#include<stack>
using namespace std;
class Solution{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped){
        if(pushed.empty() && popped.empty()) return true;
        if(pushed.empty() || popped.empty()) return false;
        stack<int> stk;
        int pushlen = pushed.size(), poplen = popped.size();
        int pushidx = 0, popidx = 0;
        while(true){
            if(stk.empty()){
                while(pushed[pushidx] != popped[popidx]){
                    stk.push(pushed[pushidx ++]);
                    if(pushidx == pushlen)return false;
                }
                stk.push(pushed[pushidx++]);
            }
            if(stk.top() == popped[popidx]){
                stk.pop();
                popidx++;
                if(stk.empty() && popidx == poplen) return true;
            }
            else {
                if(pushidx == pushlen) return false;
                while(pushed[pushidx] != popped[popidx]){
                    stk.push(pushed[pushidx++]);
                    if(pushidx == pushlen) return false;
                }
                stk.push(pushed[pushidx ++]);
            }
        }  
    }
};

//LeetCode简化版本
class Solution1{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped){
        stack<int> stk;
        int popidx = 0;
        for(int num:pushed){
            stk.push(num);
            while(!stk.empty() && stk.top() == popped[popidx]){
                stk.pop();
                popidx ++;
            }
        }
        return stk.empty();
    }
}
