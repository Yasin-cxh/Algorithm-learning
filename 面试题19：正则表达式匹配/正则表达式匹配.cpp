//题目
//请实现一个函数用来匹配包含'. '和'*'的正则表达式。
//模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
//在本题中，匹配是指字符串的所有字符匹配整个模式。
//例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配

//书本版本
//递归
bool IsMatchCore(char *pattern, char *str)
{
    if(*pattern == '\0' && *str == '\0') return true;
    if(*pattern == '\0' && *str != '\0') return false;
    //if(*str == '\0' && *pattern != '\0') return false;//这种情况不合理，例如aaa* 和aa

    if(*(pattern+1) == '*'){
        if(*pattern == *str || (*pattern =='.' && *str !='\0')){
            return IsMatchCore(pattern+2,str+1)||IsMatchCore(pattern,str+1)||IsMatchCore(pattern+2,str);
        }
        else{
            return IsMatchCore(pattern+2,str);
        }
    }
    
    if(*pattern == *str || (*pattern == '.' && *str != '\0')){
        return IsMatchCore(pattern+1,str+1); 
    }
    return false;
}
bool IsMatch(char *pattern, char *str)
{
    if(pattern == nullptr || str == nullptr) return false;

    return IsMatchCore(pattern,str);
}

//LeetCode版本
//时间要求达不到 
#include<string>
using namespace std;
class Solution {
public:
    bool isMatchCore(string s, int ids, string p, int idp)
    {
        if(s[ids] == '\0' && p[idp] == '\0') return true;
        if(s[ids] != '\0' && p[idp] == '\0') return false;
        if(p[idp + 1] == '*'){
            if(p[idp] == s[ids] || (p[idp] == '.' && s[ids] != '\0')){
                return isMatchCore(s,ids+1,p,idp+2) || isMatchCore(s,ids+1,p,idp) || isMatchCore(s,ids,p,idp+2);
            }else{
                return isMatchCore(s,ids,p,idp+2);
            }
        }
        if(p[idp] == s[ids] || (p[idp] == '.' && s[ids] != '\0')){
            return isMatchCore(s,ids+1,p,idp+1);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        if(!s.empty() && p.empty()) return false;//(s.empty() && !p.empty()) 不合理 例如""和".*"
        return isMatchCore(s,0,p,0);
    }
};

//算法2：dp
//时间O(MN) 空间O(MN)
//LeetCode 版本(K神nb！！！)
#include<vector>
class Solution{
public:
    bool isMatch(string s,string p){
        if(!s.empty() && p.empty()) return false;
        int lenR = s.size() + 1;
        int lenC = p.size() + 1;
        vector<vector<bool>> dp(lenR,vector( lenC,false));
        dp[0][0] = true;
        for(int j = 2; j< lenC; j+=2){
            dp[0][j] = dp[0][j-2] && (p[j-1] == '*');
        }
    }
};