//题目
//数组中有一个数字出现的次数远超过数组长度的一半，请找出
//这个数字。例如，输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}.由于
//数字2在数组中出现了5次，超过数组长度的一半，因此输出2
#include<string>
#include<stdio.h>
#include<vector>
using namespace std;
//LeetCode 版本
//解法1：快排思路
//因为数字出现次数超过数组的一半，所以经过排序的后的数组，其中位数就是所求数字

class Solution {
public:
int partition(vector<int> &nums, int left, int right){
    if(left == right) return left;
    int index = left;
    swap(nums[index],nums[right]);
    int small = left -1;
    for(;index <right;++index){
        if(nums[index] < nums[right]){
            ++small;
            if(small != index){
                swap(nums[small],nums[index]);
            }
        }
    }
    ++small;
    swap(nums[small],nums[right]);
    return small;
}
void quicksort(vector<int> &nums, int left, int right){
    if(left == right) return;
    int curpos = partition(nums,left,right);
    if(curpos>left)quicksort(nums,left,curpos-1);
    if(curpos<right)quicksort(nums,curpos+1,right);
}
int majorityElement(vector<int> &nums){
    int left = 0, right = nums.size()-1;
    int mid = left + ((right-left)>>1);
    quicksort(nums,left,right);
    return nums[mid];
}

};

//解法2：计数法
//因为该数字出现次数超过数组的一半，维护一个当前数，以及该数出现的次数
//下个数数等于该数，次数加1，不等于次数减一，次数为0时，更新当前数
class Solution1{
public:
    int majorityElement(vector<int> &nums){
        int temp = nums[0], count = 1;
        for(int i = 1;i < nums.size(); i++){
            if(nums[i] == temp){
                count ++;
            } 
            else{
                if(--count == 0){
                    temp = nums[i];
                    count = 1;
                }
            }
        }
        return temp;
    }
};