//题目
//写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
//思路：使用二进制
//步骤：1.不考虑进位相加(相 或)
//2.计算进位(相与)
//3.相加以上两个结果
//4.重复上述计算，直到进位==0
class Solution {
public:
    int add(int a, int b) {
        unsigned int num1 =a, num2 = b;
        unsigned int sum,carry =0;
        do{
            sum = num1^num2;
            carry = (num1&num2)<<1;
            num1 = sum;
            num2 = carry;
        }while(carry != 0);
        return sum;
    }
};