//题目
//输入一个整型数组，数组中的一个或多个整数组成一个子数组。求所有子数组的和的最大值。
//要求时间复杂度为 O(n)
//算法1：顺序遍历
//维护一个max，temp变量
//temp += 当前值
//如果temp值变为正数，比较temp 和 max ，如果temp > max 更新max
//如果temp值为负数， temp = cur[i]
#include<vector>
using namespace std;
class Solution{
public:
    int maxSubArray(vector<int> &nums){
        int temp = 0;
        int max = 0x80000000;
        for(int i = 0; i< nums.size(); i++){
            if(temp <= 0){
                temp = nums[i];
            }
            else{
                temp += nums[i];
            }
            if(temp > max) max = temp;
        }
        return max;
    }

};
//动态规划
//动态规划方程
//fx = cur[i] f(x-1) <=0
//fx = f(x-1) + cur[i] f(x-1)>0
//跟上面的写法是一样的
