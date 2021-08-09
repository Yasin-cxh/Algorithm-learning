//题目
//在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
//扫描两次，第一次统计次数，第二次检查次数
#include<string>
#include<map>
#include<vector>
using namespace std;
class Solution{
public:
 char firstUniqChar(string s){
     char res = ' ';
     if(s.empty()) return res;
     map<char,int> countMap;
     for(int i = 0; i< s.size(); i++){
         if(countMap.find(s[i]) != countMap.end()){
             countMap[s[i]]++;
         }
         else{
             countMap.insert(pair<char,int>(s[i],1));
         }
     }
     for(int i = 0; i < s.size(); i++){
         if(countMap[s[i]] == 1){
             res = s[i];
             break;
         }
     }
     return res;

 }
};