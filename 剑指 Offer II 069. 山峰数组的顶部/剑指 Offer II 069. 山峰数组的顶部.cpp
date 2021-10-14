/*

符合下列属性的数组 arr 称为 山峰数组（山脉数组） ：
arr.length >= 3
存在 i（0 < i < arr.length - 1）使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
给定由整数组成的山峰数组 arr ，返回任何满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i ，即山峰顶部。

*/
//二分法
#include<vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int begin = 1, end = arr.size()-2;//妙啊，山峰不可能出现在两端，这么写还能避免数组越界
        while(begin <= end){
            int mid = (begin + end) >> 1;
            if(arr[mid] > arr[mid -1]) begin = mid + 1;
            else if(arr[mid] < arr[mid -1]) end = mid -1;
        }
        return begin - 1;
    }
};

//双指针法，很low
class Solution1 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //双指针法
        int begin = 0, end = arr.size()-1;
        while(begin < end){
            if(arr[begin + 1] > arr[begin]) begin++;
            else return begin;
            if (arr[end - 1] > arr[end]) end --;
            else return end;
        }
        return begin;
        
    }
};