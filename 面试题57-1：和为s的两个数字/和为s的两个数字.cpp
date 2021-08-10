//题目
//输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
//如果有多对数字的和等于s，则输出任意一对即可。
#include<vector>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        vector<int> res;
        if(nums[0]>target) return res;
        int leftpos = 0 ,rightpos;
        int i = 0, j = nums.size()-1;
        while(i < j){//找到最后一个小于target的位置
            int mid = (i+j)>>1;
            if(nums[mid] >= target) j = mid -1;
            else i = mid + 1;
        }
        rightpos = j;
        while(leftpos < rightpos){
            if(nums[leftpos] + nums[rightpos] > target){
                rightpos--;
            }
            else if(nums[leftpos] + nums[rightpos] < target){
                leftpos++;
            }
            else{
                res.push_back(nums[leftpos]);
                res.push_back(nums[rightpos]);
                break;
            }
        }
        return res;
    }
};