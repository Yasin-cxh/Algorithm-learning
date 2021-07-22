//题目
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组
//的前半部分，所有偶数位于数组的后半部分

//双指针法
//书本版本
void Reorder(int *array, int length)
{
    if(array == nullptr || length == 0) return;
    int begin = 0, end = length-1;
    while(begin < end){
        while(array[end]&0x1==0 ){
            -- end;
        }
        while(array[begin] &0x1 ==1){
            ++ begin;
        }
        if(begin < end){
            int temp = array[end];
            array[end] = array[begin];
            array[begin] = temp;
        }
    }
}

//LeetCode版本
#include<vector>
using namespace std;
class Solution{
public:
    vector<int> exchange(vector<int> &nums){
        vector<int> result(nums.begin(),nums.end());
        if(nums.empty()) return result;
        int begin = 0, end = result.size()-1;
        while(begin < end){
            while(begin < end && (result[end] & 0x1) == 0) --end;
            while((begin < end && result[begin] & 0x1) != 0) ++begin;
            if(begin < end){
                int temp = result[end];
                result[end] = result[begin];
                result[begin] = temp;
            }
        }
        return result;
    }

};

//机试的话用双指针
//手撕的话用函数指针