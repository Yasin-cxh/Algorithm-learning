//题目
//输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
//例如输入字符串"I am a student. "，则输出"student. a am I"。

//还要去除多余的空格
//使用双指针法
#include<string>
using namespace std;
class Solution{
public:
string reverseWords(string s){
    int begin,end;
    begin = end = s.size()-1;
    string res;
    while(begin >= 0){
        while(begin >=0 && s[begin] == ' '){
            begin --;
        }
        end = begin;
        while(begin >=0 && s[begin] != ' '){
            begin --;
        }
        if(end == begin)break;
        res.append(s.substr(begin+1,end-begin));
        res.append(" ");
        
    }
    if(!res.empty()){
        res.pop_back();
    }
    return res;
}
    
};