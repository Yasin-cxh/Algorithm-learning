//题目
//请定义一个队列并实现函数 max_value 得到队列里的最大值，
//要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
//若队列为空，pop_front 和 max_value 需要返回 -1

//使用两个双端队列实现

#include<queue>
using namespace std;
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(data.empty()) return -1;
        return maxque.front();
    }
    
    void push_back(int value) {
        data.push_back(value);
        while(!maxque.empty() && value > maxque.back()){
            maxque.pop_back();
        }
        maxque.push_back(value);
    }
    
    int pop_front() {
        if(data.empty())return -1;
        if(maxque.front() == data.front()){
            maxque.pop_front();
        }
        int res = data.front();
        data.pop_front();
        return res;
    }
private:
    deque<int> data;
    deque<int> maxque;
};
