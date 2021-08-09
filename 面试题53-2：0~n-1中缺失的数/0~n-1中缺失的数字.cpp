//题目
//一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
//在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != i) return i;
        }
        return nums.size();
    }
};
//对有序的数组，都要用二分进行处理
//和上一题找右边界的很像
class Solution1{
public:
int missingNumber(vector<int> &nums){
    int i = 0, j = nums.size()-1;
    int mid;
    while(i <= j){
        mid = (i+j)>>1;
        if(nums[mid] == mid) i = mid +1;
        else j = mid -1;
    }    
    return i;
}
};
