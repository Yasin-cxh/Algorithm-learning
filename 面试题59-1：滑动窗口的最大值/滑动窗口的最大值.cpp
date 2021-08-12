//题目
//给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
//使用双端队列
//每次插入时删除比当前插入元素小的元素
//插入的值为下标，维护窗口大小
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()) return {};
        deque<int> maxque;
        vector<int> res;
        for(int i = 0 ; i< k; i++){
            while(!maxque.empty() && nums[i] >= nums[maxque.back()]){
                maxque.pop_back();
            }
            maxque.push_back(i);
        }
        for(int i = k; i <nums.size();i++){
            res.push_back(nums[maxque.front()]);
            while(!maxque.empty() && nums[i] >= nums[maxque.back()]){
                maxque.pop_back();
            }
            if(!maxque.empty() && maxque.front() <= i-k){
                maxque.pop_front();
            }
            maxque.push_back(i);
        }
        res.push_back(nums[maxque.front()]);
        return res;
    }
};
