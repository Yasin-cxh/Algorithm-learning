#include<math.h>
#include<limits.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        //(被除数 - 余数) / 除数 = 商
        //采用 位运算方法
        //如果被除数为0，直接返回0
        //判断结果是否为负数
        //求出被除数的位数
        //被除数从左边第一位开始向右边遍历 (变量1 当前的被减数)
        //变量2 当前位数1，初始为1，和被除数的位数一起算，最终结果比被除数多一位。每次右移一位。
        //变量3 当前商， 每次循环，左移一位模拟除法。如果当前被减数大于除数，商 |= 当前位数1。
        if(dividend == 0) return 0;
        bool sign = false;
        long long first = dividend, second = divisor;
        if((first < 0 && second > 0) || (first > 0 && second < 0)) sign = true;
        first = abs(first);
        second = abs(second);
        //if(first < second) return 0;
        long long bit_num = 0;
        long long curMinute =0; 
        long long temp = 1;
        long long ans = 0;
        while(temp <= first){
             bit_num++;
             temp <<= 1;
        }
        while(bit_num--){
            temp >>= 1;
            curMinute <<= 1;
            curMinute |= (first >> bit_num) &0x1;
            if(curMinute >= second){
                curMinute -= second;
                ans |= temp;
            }
        }
        ans = sign?-ans:ans;
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        return ans;
        
    }
};