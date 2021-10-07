//题目
/*
有一个密钥字符串 S ，只包含字母，数字以及 '-'（破折号）。其中， N 个 '-' 将字符串分成了 N+1 组。
给你一个数字 K，请你重新格式化字符串，使每个分组恰好包含 K 个字符。特别地，第一个分组包含的字符个数必须小于等于 K，
但至少要包含 1 个字符。
两个分组之间需要用 '-'（破折号）隔开，并且将所有的小写字母转换为大写字母。
给定非空字符串 S 和数字 K，按照上面描述的规则进行格式化。
*/
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        //1.先删除原字串中的破折号 string erease 和 algorithm remove 混合使用
        //2.计算字符串的长度len
        //3.求len/k, len%k。
        //4.如果余数不为0，则余数为第一段长度，其余段长度为k，len/k 为破折号的数量。
        //  如果余数为0，说明能整除，每段长度都是k，len/k-1为破折号的数量。 
        string ans;
        s.erase(remove(s.begin(),s.end(),'-'),s.end());
        if(s.empty()) return ans;
        for(auto &c:s){
            c = toupper(c);
        }
        long long len = s.size();
        long long mod = len%k;
        long long partNum = len/k;
        long long idx = 0;
        if(mod == 0){
            partNum --;
            ans = s.substr(idx,k);
            while(partNum != 0){
                ans += '-';
                idx += k;
                ans += s.substr(idx,k);
                partNum --;
            }
        }
        else{
            ans = s.substr(idx,mod);
            idx += mod;
            while(partNum != 0){
                ans += '-';
                ans += s.substr(idx, k);
                idx += k;
                partNum --;
            }
            
        }
        return ans;
    }
};