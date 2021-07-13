//题目
//用两个栈实现队列。队列的声明如下：请实现它的两个函数 appendTail he deleteHead
//分别完成在队列尾部插入节点和队列头部删除节点的功能
template<typename T>class CQueue
{
public:
CQueue(void);
~CQueue(void);
void appendTail(const T& node);
T deleteHead();
private:
stack<T> stack1;
stack<T> stack2;
};

//思路 尾部插入 stack1直接插入
// 头部删除 stack2有数据就pop，没数据就将stack1的全部弹出再插入到stack2中
//书本内容
void CQueue::appendTail(const T& node)
{
    stack1.push(node);
}

T CQueue::deleteHead()
{
    T result;
    if(!stack2.empty())
    {
        result = stack2.top();
        stack2.pop();
    }
    else{
        T temp;

        while(stack1.size()>0){
            temp = stack1.top();
            stack2.push(temp);
            stack2.pop();
        }
        //如果添加玩数据还为空，就报错
        if(stack2.empty()) throw new exception("queue is empty");
        result = stack2.top();
        stack2.pop();
    }
    return result;
}

//LeetCode 版本
class CQueue{
public:
    CQueue(){
    }
    void appendTail(int value){
        stack1.push(value);
    }
    int deleteHead(){
        int result = -1;
        if(!stack2.empty()){
            result = stack2.top();
            stack2.pop();
        } else{
            int temp;
            while(stac1.size()>0){//栈的pop导致栈的stack1.size()是变化的，使用固定的len or while stack1.size()>0
                temp = stack1.top();
                stack2.push(temp);
                stack1.pop();
            }
            if(stack2.empty())
                return result;
            result = stack2.top();
            stack2.pop();
        } 
        return result;
    }
private:
 stack<int> stack1;
 stack<int> stack2;
};