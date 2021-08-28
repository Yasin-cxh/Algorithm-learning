//题目
//数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
//请写一个函数，求任意第n位对应的数字。
//输入：n = 3
//输出：3
//输入：n = 11
//输出：0
#include<stdio.h>
#include<algorithm>
using namespace std;
class Solution{
public:
    int findNthDigit(int n){
        if(n < 0)return -1;
        if(n < 10) return n;
        int base = 10, bitnums = 2;
        long long totalNums = 10, preTotalNums;
        int ans;
        while(true){
            preTotalNums = totalNums;
            totalNums += (bitnums*(pow(10,bitnums) - base));
            if(totalNums < n){
                base = pow(10,bitnums);
                bitnums++;
            }
            else{
                int num = (n - preTotalNums )/bitnums + base;
                int bitIdx = (n - preTotalNums )%bitnums;
                char str[50];
                snprintf(str, sizeof(str)-1,"%d",num);
                ans = *(str + bitIdx) - '0';
                break;
            }
        }
        return ans;
    }
};