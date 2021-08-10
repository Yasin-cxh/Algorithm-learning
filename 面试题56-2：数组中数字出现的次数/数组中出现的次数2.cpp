//题目
//在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。
//请找出那个只出现一次的数字。
//思路，位运算，将所有数的每位各自加起来，保存在一个32位的数组中
//遍历这个32位数组，如果该位能被3整除，则目标数字的该位为0，否则，目标数字的该位为1
#include<vector>
using namespace std;
class Solution{
public:
    int singleNumber(vector<int> &nums){
        vector<int>bits(32,0);
        for(int i = 0; i < nums.size(); i++){
            int bitpos = 0;
            for(int j = 31; j>=0; j--){
                bits[j] += ((nums[i]>>bitpos)& 0x1);
                bitpos ++;
            }
        }
        int res = 0;
        for(int i =0; i< 32;i++){
            res = res<<1;
            res += bits[i]%3;
        }
        return res;
    }
};