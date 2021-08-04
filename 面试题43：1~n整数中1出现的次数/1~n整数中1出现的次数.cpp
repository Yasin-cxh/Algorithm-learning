//输入一个整数n，求1~n这n个整数的十进制表示中1出现的次数。
//例如，输入12，1~12这些整数中包含1的数字有1，10，11和12,1一共出现了5次
//统计1的个数
//先计算最高位的数字，比1大就次数+ 10^n (n是最高位)
//再计算除最高位剩余位数1的个数，排列组合
//最后计算尾数
#include<stdio.h>
#include<string>
using namespace std;
class Solution{
public:
    int dealString( const char *str){
        if(str == nullptr)return 0;
        int first = *str - '0';
        int length = strlen(str);
        if(length == 0)return 0;
        if(first == 0 && length == 1)return 0;
        if(first > 0 && length == 1)return 1;
        int highestNums(0), otherNums(0), tailNums(0);
        if(first > 1){
            highestNums = pow(10,length-1);
        }
        else if(first == 1){
            highestNums = atoi(str+1) + 1;
        }

        otherNums = first * (length  -1) * pow(10,length-2);

        tailNums = dealString(str + 1);
        return highestNums + otherNums +  tailNums;
    
    }
    int countDigitOne(int n){
        if(n <= 0) return 0;
        char str[50];
        snprintf(str,sizeof(str)-1,"%d",n);
        return dealString(str);
    }
};