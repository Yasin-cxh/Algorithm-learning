/*
*题目
*你总共有 n 枚硬币，并计划将它们按阶梯状排列。对于一个由 k 行组成的阶梯，其第 i 行必须正好有 i 枚硬币。阶梯的最后一行 可能 是不完整的。
*给你一个数字 n ，计算并返回可形成 完整阶梯行 的总行数。
*/
#include<math.h>
using namespace std;
//求根公式法
class Solution {
public:
    int arrangeCoins(int n) {
        //高斯公式 n(n+1)/2 = s
        //n2+n-2s=0 ,求一元二次方程的解
        // ans = [sqrt(1+8n) - 1] /2;
        // 注意越界问题， 用long long 替代 int
        long long derta = n;
        return (sqrt(8*derta + 1) - 1)/2;
    }
};

//二分法
class Solution {
public:
    int arrangeCoins(int n) {
    //n枚硬币最多n行，当且仅当n=1时取到
    //二分法，如果当前行大于n，在左侧找。如果当前行小于n，在在右侧找。等于n直接返回当前行号
        long long begin = 1, end = n;
        while(begin <= end){//二分法的边界看这里
            long long mid = (begin + end) >> 1;
            if(mid * (mid + 1) / 2 > n) end = mid - 1;
            else if(mid * (mid + 1) / 2 < n ) begin = mid+1;
            else return mid;
        } 
        return end;
    }
};