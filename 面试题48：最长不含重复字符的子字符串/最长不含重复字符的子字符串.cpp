//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
//dp 方程
//fx = fx-1 + 1 第一次出现或者curpos - prepos > fx-1
//fx = curpos - prepos curpos-prepos <= fx-1
class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int len = s.size();
        vector<int> pos(128,-1);
        vector<int> dp(len,0);
        dp[0] = 1;
        pos[s[0]] = 0;
        int res = 1;
        for(int i = 1; i < len; i++){
            int prepos = pos[s[i]];
            if(prepos == -1 || i-prepos > dp[i-1]){
                dp[i] = dp[i-1] + 1;
                res =max(dp[i],res);
            }
            else{
                dp[i] = i- prepos;
                res = max(dp[i],res);
            }
            pos[s[i]] = i;
        }
        return res;
    }
};
//滑动窗口
class Solution1{
public:
    int lengthOfLongestSubstring(string s) {
        int res =0, len = s.size();
        string str = "";
        for(int i = 0 ; i < len; i++){
            size_t idx = str.find(s[i]);
            if(idx != string::npos){
                if(res < str.size()) res = str.size();
                str.erase(0,idx+1);
            }
            str += s[i];
        }
        if(res<str.size()) res = str.size();
        return res;
    }
};