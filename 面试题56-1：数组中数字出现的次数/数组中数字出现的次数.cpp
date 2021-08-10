//题目
//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
//请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
//出现两次->使用异或
//一个数异或他本身是0，因为只有两个出现一次的数字，且这两个数字不相同，
//整个数组异或的结果就是两个只出现过一次的异或结果
//因为这两个数字不同，异或结果一定有一位是1，根据这位数将数组分成两份
//因为这位是1，所以两个只出现一次的数一定会分配在两个小组里。
//重新异或操作，两个部分小组的异或结果就是只出现一次的数
#include<vector>
using namespace std;

class Solution{
public:
int findBit1Pos(int num){
    int pos = 0;
    while(((num>>pos) & 0x1) != 1){
        pos++;
    }
    return pos;
}
vector<int> singleNumbers(vector<int> &nums){
    int xorresult = 0;
    vector<int> res;
    for(int i=0; i <nums.size(); i++){
        xorresult ^= nums[i];
    }
    int bit1Pos = findBit1Pos(xorresult);
    int num1 = 0, num2 = 0;

    for(int i= 0; i< nums.size();i++){
        if(((nums[i]>>bit1Pos) & 0x1) != 1){
            num1 ^= nums[i];
        } 
        else{
            num2 ^= nums[i];
        }
    }
    res.push_back(num1);
    res.push_back(num2);
    return res;
}
};