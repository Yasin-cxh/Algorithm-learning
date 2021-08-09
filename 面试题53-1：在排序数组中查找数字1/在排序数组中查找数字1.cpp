//题目
//统计一个数字在排序数组中出现的次数。

#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int findFirstTarget(vector<int> &nums, int begin, int end, int target){
        if(begin > end ) return -1;
        int mid = (begin + end)>>1;
        if(nums[mid] == target){
            if(mid == 0 || nums[mid-1] != target){
                return mid;
            }else{
                end = mid -1;
            }
        }
        else if (nums[mid] > target){
            end  = mid - 1;
        }
        else {
            begin = mid + 1;
        }
        return findFirstTarget(nums,begin,end,target);
    }
    int findLastTarget(vector<int> &nums, int begin, int end, int target){
        if(begin>end)return -1;
        int mid = (begin+end)>>1;
        if(nums[mid] == target){
            if(mid == nums.size()-1 || nums[mid+1] != target){
                return mid;
            }else{
                begin = mid + 1;
            }
        }
        else if(nums[mid] > target){
            end = mid -1;
        }
        else {
            begin = mid + 1;
        }
        return findLastTarget(nums,begin,end,target);
    }
    int search(vector<int>& nums, int target) {
        int res = 0;
        if(nums.empty()) return res;
        int end = nums.size()-1;
        int firstidx = findFirstTarget(nums,0,end,target);
        int lastidx = findLastTarget(nums,0,end,target);
        if(firstidx != -1 && lastidx != -1){
            res = lastidx - firstidx + 1;
        }
        return res;
    }
};

//看看别人的二分怎么写的
class Solution1{
public:
    int findRight(vector<int> &nums, int target){
        int i = 0, j = nums.size()-1;
        while(i <= j){
            int mid = (i+j)>>1;
            if(nums[mid] <= target) i = mid + 1;
            else j = mid - 1;
        }
        return i;
    }
    int search(vector<int> &nums, int target){
        return findRight(nums,target) - findRight(nums, target-1);
    }
};