/*
    题目
    统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
    请注意，你可以假定字符串里不包括任何不可打印的字符。
*/
#include<string>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
        //统计字符串中空格段的数量
        //单词个数为字符段空格段个数+1
        if(s.empty()) return 0;
        int begin = 0, end = s.size();
        while(s[begin] == ' ') ++begin;
        if(begin == end) return 0;
        int blankNum = 0;
        while(begin != end){
            while(begin != end && s[begin] != ' ') ++begin;
            int temp = begin;
            while(begin != end && s[begin] == ' ') ++begin;
            if(begin != end && temp != begin) blankNum ++;
        }
        return blankNum+1;
    }
};

class Solution1 {
public:
    int countSegments(string s) {
    //统计单词首字母数量
    //单词首字母定义：(下标0||下标-1字母为空格)&&下标字母不为空格
        int ans{0};
        for(int i = 0; i < s.size(); i++){
            if((i == 0 || s[i-1] == ' ') && s[i] != ' ')
                ans++;
        }
        return ans;
    }
};