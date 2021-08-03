//题目
//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值
//如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值
//算法1
//使用最小堆和最大堆
//1.最小堆和最大堆大小不相差1
//2.奇数时插入最大堆，偶数时插入最大堆
//3.保证最大堆的任何值都小于最小堆
//书本版本
#include<vector>
#include<algorithm>
using namespace std;
template<typename T> class DynamicArray{
public:
void Insert(T num){
    if(((max.size() + min.size()) & 1) == 0){//偶数，插入到最小堆
        if(max.size() > 0 && num < max[0]){//当前值小于max堆最大值
            max.push_back(num);
            push_heap(max.begin(),max.end(),less<T>());//将最后一个数加入到heap中
            num = max[0];
            
            pop_heap(max.begin(),max.end(),less<T>());//less就是大顶堆，弹出最大值，置于尾部
            max.pop_back();
        }
        min.push_back(num);
        push_heap(min.begin(),min.end(),greater<T>());
    }
    else{//插入到大顶堆
        if(min.size() >0 && num > min[0] ){
            min.push_back(num);
            push_heap(min.begin(),min.end(),greater<T>());
            num = min[0];
            pop_heap(min.begin(),min.end(),greater<T>());
            min.pop_back();
        }
        max.push_back(num);
        push_heap(max.begin(),max.end(),less<T>());
    }
    
}
T GetMedian(){
    int size = min.size() + max.size();
    if(size == 0) throw exception("No numbers are availiable");
    if((size & 1) == 0) return (max[0] + min[0])/2;
    else return min[0];
}
private:
vector<T>max;
vector<T>min;
};



//LeetCode版本
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(((minh.size() + maxh.size()) & 1) == 0){
            if(maxh.size() > 0 && num < maxh[0]){
                maxh.push_back(num);
                push_heap(maxh.begin(),maxh.end(),less<int>());

                num = maxh[0];

                pop_heap(maxh.begin(),maxh.end(),less<int>());
                maxh.pop_back();
            }
            minh.push_back(num);
            push_heap(minh.begin(),minh.end(),greater<int>());
        }    
        else{
            if(minh.size() > 0 && num > minh[0]){
                minh.push_back(num);
                push_heap(minh.begin(),minh.end(),greater<int>());
                num = minh[0];

                pop_heap(minh.begin(),minh.end(),greater<int>());
                minh.pop_back();
            }
            maxh.push_back(num);
            push_heap(maxh.begin(),maxh.end(),less<int>());
        }
    
    
    }
    
    double findMedian() {
        int size = minh.size() + maxh.size();
        if(size == 0) return 0.0;
        double median;
        if((size & 1) == 0) median = (maxh[0] + minh[0])/2.0;//这边要除以2.0
        else median = minh[0];
        return median;
    }
private:
 vector<int> minh;
 vector<int> maxh;
};