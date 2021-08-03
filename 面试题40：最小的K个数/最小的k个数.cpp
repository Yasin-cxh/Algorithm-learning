//题目
//输入整数数组arr,找出期中最小的K个数。
//例如，输入4，5，1，6，2，7，3，8这8给数字，最小的4个数字时1，2，3，4
//解法1：partition
#include<vector>
using namespace std;
class Solution{
public:
 int partition(vector<int> &arr,int begin, int end){
     int index = begin;
     swap(arr[index],arr[end]);
     int small = begin-1;
     for(;index < end; index ++){
         if(arr[index] < arr[end]){
             ++small;
             if(small != index){
                 swap(arr[small], arr[index]);
             }
         }
     }
     ++small;
     swap(arr[small],arr[end]);
     return small;
 }
 vector<int> getLeastNumbers(vector<int> &arr, int k){
     vector<int> result;
     if(arr.empty() || k == 0)return result;
     int left = 0, right = arr.size()-1;
     int curpos = partition(arr,left,right);
     while(curpos!=k-1){
         if(curpos < k-1){
             left = curpos + 1;
             curpos = partition(arr,left,right);
         }else{
             right = curpos -1;
             curpos = partition(arr,left,right);
         }
     } 
     for(int i = 0; i < k;i ++ ){
         result.push_back(arr[i]);
     }
     return result;
 }
};
//算法2，维护一个大小为k的大顶堆
//大顶堆的实例类，priority_queue
#include<queue>
class Solution{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k){
        if(arr.empty() ||k == 0) return {};
        if(arr.size() <= k) return arr;
        vector<int> result;
        priority_queue<int> heap;
        for(int i = 0 ; i < k; i++){
            heap.push(arr[i]);
        }
        for(int j = k; j< arr.size(); j++){
            if(arr[j] < heap.top()){
                heap.pop();
                heap.push(arr[j]);
            }
        }
        while(!heap.empty()){
            result.push_back(heap.top());
            heap.pop();
        }
        return result;
    }
};