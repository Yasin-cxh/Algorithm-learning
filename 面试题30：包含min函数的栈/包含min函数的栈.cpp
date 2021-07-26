//题目
//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数在该栈中，
//调用min,push以及pop的时间复杂度都是O(1)
//使用辅助stack记录当前最小值，每次push是压入当前最小值，每次pop时，若pop的是最小值，将辅助数组也pop一次
#include<stack>
using namespace std;
class MinStack{
public:
    MinStack(){}
    void push(int x){
        m_stk.push(x);
        if(m_minstk.empty()){
            m_minstk.push(x);
        }else{
            int curmin = m_minstk.top();
            if(x <= curmin) m_minstk.push(x);
        }
    }
    void pop(){
        if(m_stk.top() == m_minstk.top()) m_minstk.pop();
        m_stk.pop();
    }
    int top(){
        return m_stk.top();
    }
    int min(){
        return m_minstk.top();
    }
private:
    stack<int> m_stk;
    stack<int> m_minstk;
};