//题目
//给定一个数字，我们按照如下规则把它翻译成字符串：
//0翻译成"a",1翻译成"b",......,11翻译成"1",.....,25翻译成"z"
//一个数字能有多个翻译。例如，12258有5种不同的翻译，分别是"bccfi","bwfi","bczi","mcfi"和"mzi"
//请编写实现一个函数，用来计算一个数字有多少种不同的翻译方法

//这道题从高位向低位递归会存在重复子问题,如1，2258 和 12，258,所以从低位向高位处理
//递归表达式为f(i) = f(i+1) + g(i,i+1)*f(i+2)
//LeetCode版本
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
public:
    int count(string str){
        int num = atoi(str.c_str());
        if(num>=10 && num <= 25) return 1;
        else return 0;
    }
    int translateNum(int num){//从前往后
        string str = to_string(num);
        int len = str.size();
        if(len < 2) return len;
        vector<int> dp(0,len + 1);
        dp[0]=1;
        dp[1]=1;
        for(int i = 2; i<=len; i++){
            dp[i] = dp[i-1] + count(str.substr(i-2,2)) * dp[i-2];
        }
        return dp[len];

    }
    int translateNum1(int num){//从后往前
    string str = to_string(num);
    int len = str.size();
    if(len < 2) return len;
    vector<int> dp(len+1,0);
    dp[len] = 1;
    dp[len-1] = 1;
    for(int i = len-2; i>=0; i--){
        dp[i] = dp[i+1] * count(str.substr(i,2)) * dp[i+2];
    }
    return dp[0];

    }
};