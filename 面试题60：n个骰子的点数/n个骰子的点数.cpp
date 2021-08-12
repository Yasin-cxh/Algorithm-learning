//题目
//把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
//你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
//动态规划法
//dp方程，n个骰子掷总和为s的次数为 n-1个骰子掷s-1,s-2,s-3,s-4,s-5,s-6的总和

#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    vector<double> dicesProbability(int n){
        if(n<1) return {};
        int maxnums = 6*n+1;
        vector<vector<int>> dp(2,vector<int>(maxnums,0));
        int flag = 0;
        for(int i = 1; i <= 6; i ++ ){
            dp[flag][i] = 1;
        }
        for(int i = 2; i <= n; i ++){
            for(int k =1; k<i;k++){
                dp[1-flag][k] = 0;
            }
            for(int k = i; k <= i*6; k++){
                dp[1-flag][k] =0;
                for(int j = 1; j<k && j<=6; j++){
                    dp[1-flag][k] += dp[flag][k-j];
                }
            }
            flag = 1-flag;
        }
        double allcount = pow(6.0,n);
        vector<double>res;
        for(int i = n; i<maxnums;i++){
            double p = dp[flag][i]/allcount;
            res.push_back(p);
        }
        return res;
    }
};

//逆向
class Solution1 {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<double>> dp(2,vector<double>(6*n+1,0.0));
        int flag = 0;
        for(int i = 1; i<=6; i++){
            dp[flag][i] = 1.0/6.0;
        }
        for(int i = 2; i <= n; i++){
            for(int k = 1; k < i;k++){
                dp[1-flag][k] = 0;
            }
            for(int k = i; k<= i*6; k ++){
                dp[1-flag][k] = 0;
                for(int j = 1; j<k && j<=6; j++){
                    dp[1-flag][k] += dp[flag][k-j]/6.0;
                }
            }
            flag = 1 - flag;
        }
        vector<double> res;
        for(int i = n; i<= 6*n; i++){
            res.push_back(dp[flag][i]);
        }
        return res;
    }
};

//K神版,正向
class Solution2 {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6,1.0/6.0);
        for(int i = 2; i <=n; i++){
            vector<double> temp(5*i+1,0);
            for(int j = 0; j < dp.size(); j++){
                for(int k = 0; k<6; k++){
                    temp[j+k] += dp[j]/6.0;
                }
            }
            dp = temp;
        }
        return dp;
    }
};