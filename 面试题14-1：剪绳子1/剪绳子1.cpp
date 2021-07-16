#include<math.h>
//题目
//给你一段长度为n的绳子，请把绳子剪成m段(m、n都是整数，n>1并且m>1)(至少两段)
//每段绳子的长度记为k[0],k[1],...,k[m-1].请问k[0]*k[1]*...*k[m-1]可能的最大乘积是多少？
//例如，当绳子的长度为8时，我们把它剪成长度分别为2、3、3的三段，此时得到最大乘积是18

//算法1：动态规划
//时间：O(n2) 空间:O(n)
//书本版本
int maxProductAfterCutting_solution1(int length)
{
   if(length < 2) return -1;
   if(length == 2) return 1;
   if(length == 3) return 2;
   int *dp = new int[length + 1];
   dp[0] = 0;
   dp[1] = 1;
   dp[2] = 2;
   dp[3] = 3;
   int max ;
   for(int i = 4; i < length + 1; i ++){
       max = 0;
       for(int j = 1; j <= i/2; j++){
           int temp = dp[i-j] * dp[j];
           if(temp > max) max = temp; 
       }
       dp[i] = max;
   }
   max = dp[length];
   delete[] dp;
   return max;
}

//LeetCode版本
class Solution{
public:
int cuttingRope(int n){
if(n == 2) return 1;
if(n == 3) return 2;
int *dp = new int[n + 1];
dp[0] = 0;
dp[1] = 1;
dp[2] = 2;
dp[3] = 3;
int max;
for(int i = 4 ; i < n + 1; i ++ ){
    max = 0;
    for(int j = 1; j<= i/2; j++){
        int temp = dp[i-j] * dp[j];
        if(temp > max) max = temp;
    }
    dp[i] = max;
}
max = dp[n];
delete[] dp;
return max;
}
};

//算法2：贪心算法
//书本版本
int maxProductAfterCutting_solution2(int length)
{
    if(length < 2) return 0;
    if(length == 2) return 1;
    if(length == 3) return 2;
    int timeof3 = length/3;
    if((length - 3 * timeof3) == 1) timeof3--;
    int timeof2 = (length - 3* timeof3)/2;
    return (int)(pow(3,timeof3)) *((int)pow(2,timeof2)); 
}
//LeetCode 版本
//两个推论
//1.将绳子以相等的长度等分为多段，得到的乘积最大(由算术几何不等式导出)
//2.尽可能将绳子以长度3等分为多段时，乘积最大
class Solution{
public:
    int cuttingRope(int n){
        return n<4?n-1:pow(3,n/3)*4/(4-n%3);//妙哇
    }
};
