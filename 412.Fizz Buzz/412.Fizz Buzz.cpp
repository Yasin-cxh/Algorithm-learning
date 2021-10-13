/*

给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组 answer（下标从 1 开始）返回结果，其中：

answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
answer[i] == "Fizz" 如果 i 是 3 的倍数。
answer[i] == "Buzz" 如果 i 是 5 的倍数。
answer[i] == i 如果上述条件全不满足。
 

*/
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1; i <= n; i++){
            if(i%3 == 0 && i%5 ==0) ans.push_back("FizzBuzz");
            else if( i%3 == 0) ans.push_back("Fizz");
            else if( i%5 == 0) ans.push_back("Buzz");
            else ans.push_back(to_string(i));
        }
        return ans;
    }
};