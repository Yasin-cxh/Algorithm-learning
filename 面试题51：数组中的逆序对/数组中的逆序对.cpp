//题目
//数组中的逆序对
//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//输入一个数组，求出这个数组中的逆序对的总数。
//法1：O(n2) 超时

//法2：归并排序
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int merge_sort(vector<int> &nums, vector<int> &temp, int begin, int end){
        if(begin >= end) return 0;
        int mid = ((end-begin)>>1)+begin;//(end-begin)>>1 + begin;//绝>>的优先级比 + 弱 所以先算了 1+begin
        int left = merge_sort(nums,temp,begin,mid);
        int right = merge_sort(nums,temp,mid+1,end);
        int count = 0, i = begin, j = mid+1,idxn = begin;
        for(int k = begin; k <= end; k++){
            temp[k] = nums[k];
        }
        while(i <= mid && j<= end){
            if(temp[i] > temp[j]){
                count += mid - i + 1;
                nums[idxn++] = temp[j++];
            }else{
                nums[idxn++] = temp[i++];
            }
        }
        while(i<=mid){
            nums[idxn++] = temp[i++];
        }
        while(j<=end){
            nums[idxn++] = temp[j++];
        }
        return left + right + count;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        int res = merge_sort(nums,temp,0,nums.size()-1);
        return res;
    }
};