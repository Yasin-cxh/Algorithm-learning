//题目
//从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
//2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
//排序，计算空缺数，空缺数小于等于count[0]的个数
#include<vector>
using namespace std;
class Solution{
    bool isStraight(vector<int> &nums){
        vector<int> count(14,0);
        for(int i = 0; i<nums.size(); i++){
            count[nums[i]]++;
        }
        int l = 0 ,res = 0;
        for(int i= 1; i<14;i++){
            if(count[i] > 1) return false;
            else if(count[i] == 1){
                if(l!=0) res += i-l-1;
                l = i;
            }
        }
        return res <= count[0];
    }
};