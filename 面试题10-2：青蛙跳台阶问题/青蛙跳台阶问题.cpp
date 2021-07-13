//和10-1没区别，更改下初始值就行
class Solution{
public:
int numWays(int n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    int *dp = new int[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    int mod = 1e9+7;
    for(int i = 2; i < n+1; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    return dp[n];
}
};