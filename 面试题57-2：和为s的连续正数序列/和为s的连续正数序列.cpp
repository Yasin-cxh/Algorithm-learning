//题目
//输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
//序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
//算法：双指针，small，big
//small到big的序列和小于target 增加big， 大于target 增加small
//small 增长到 (1+target)/2为止
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if(target < 3) return {};
        vector<vector<int>> res;
        int small = 1,big =2;
        int curSum = 3;
        int end = (1+target)>>1;
        while(small < end){
            if(curSum < target){
                big++;
                curSum += big;
            }
            else if(curSum > target){
                curSum -= small;
                small ++;
            }
            else{
                vector<int> temp;
                for(int i = small; i <= big; i++){
                    temp.push_back(i);
                }
                res.push_back(temp);
                big ++;
                curSum += big;
            }
        }
        return res;
    }
};