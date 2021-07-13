//题目
//求斐波那契数列的第n项

//低效算法
//做了太多重复计算
long long Fibonacci(unsigned int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

//算法2：
//避免迭代导致的重复计算
//改用循环

//书本版本
long long Fibonacci(unsigend int n)
{
    if(n < 1) return -1;
    int result[2] = {0,1};
    if(n <= 2) return result[n-1];

    long long fib1 = 0;
    long long fib2 = 1;
    long long fibn = 0;
    for(int i = 2; i < n ; i ++)
    {
        
        fibn = fib1 + fib2;
        fib1 = fib2;
        fib2 = fibn;
    }
    return fibn;
}

//LeetCode版本
//该题答案需要取模 1e9 + 7
class Solution{
public:
    int fib(int n){
        int result[2] = {0,1};
        int mod = 1e9+7;
        if(n<= 1) return result[n];
        int fib1 = 0;
        int fib2 = 1;
        int fibn = 0;
        for(int i = 2; i < n+1; i++){ // 少用 <= 
            fibn = (fib1 + fib2) % mod;
            fib1 = fib2;//要替换的在等号右边
            fib2 = fibn;//要赋值变量紧跟上一条
        }
        return fibn;
    }
}

//动态规划算法
class Solution{
public:
    int fib(int n){
<<<<<<< HEAD
        if(n == 0) return 0;
        if(n == 1) return 1;
=======
>>>>>>> 64472964b4885ecbb8e7ebfba849a9ab48b77d6e
        int *dp = new int[n+1];
        int mod = 1e9+7;
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i < n + 1;++ i){
            dp[i] = (dp[i-1] + dp[i - 2]) % mod;
        }
        return dp[n];
    }
};