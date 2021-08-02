//题目
//输入一个字符串，打印出该字符串中字符的所有排列。例如，输入字符串abc
//则打印出由字符a、b、c所能排列出来的所有字符串abc,acb,bac,bca,cab,cba
//全排列的思想就是递归
//确定排列位置，该位置分别和后几位交换(交换完需要有一个换回的操作，这样才能保证每次交换都是同一个数)
//确定下一个位置
//递归终结条件 ，当前位置位于字符串尾部
#include<stdio.h>
//书本版本
void permutationcore(char *str, char *beginidx)
{
    if(*beginidx == '\0'){
        printf("%s\n",str);
    } 
    else {
        for(char *pos = beginidx; *pos != '\0'; ++pos){
            char temp = *pos;
            *pos = *beginidx;
            *beginidx = temp;
            permutationcore(str,str+1);
            temp = *pos;
            *pos = *beginidx;
            *beginidx = temp;
        }
    }
}
void permutation(char *str)
{
    if(str == nullptr) return;
    permutationcore(str, str);
}

//LeetCode版本
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    void permutationcore(string s, int beginidx){
        if(s[beginidx] == '\0'){
            result.push_back(s);
            return;
        }else{
            for(int i = beginidx; s[i] != '\0'; i++){
                char temp = s[i];
                s[i] = s[beginidx];
                s[beginidx] = temp;
                permutationcore(s,beginidx+1);
                temp = s[i];
                s[i] = s[beginidx];
                s[beginidx] = temp;
            }
        }
    }
    vector<string> permutation(string s) {
        if(s.empty()) return {};
        permutationcore(s,0);
        return result;
    }
private:
    vector<string> result;
};
//按照书本的解法，可以解决大部分的情况
//但是无法解决字符串中包含重复字符导致的重复输出字符串问题
//解法2：在添加时检查是否重复
#include<set>
class Solution1 {
public:
    void permutationcore(string s, int beginidx){
        if(s[beginidx] == '\0'){
            if(check.find(s) != check.end()){
                result.push_back(s);
                check.insert(s);
            }
            return;
        }else{
            for(int i = beginidx; s[i] != '\0'; i++){
                swap(s[i],s[beginidx]);
                permutationcore(s,beginidx+1);
                swap(s[i],s[beginidx]);
            }
        }
    }
    vector<string> permutation(string s) {
        if(s.empty()) return {};
        permutationcore(s,0);
        return result;
    }
private:
    vector<string> result;
    set<string> check;
};
//解法3：在过程中判断是否重复
class Solution {
public:
    void permutationcore(string s, int beginidx){
        if(s[beginidx] == '\0'){
            result.push_back(s);
            return;
        }else{
            set<int> check;
            for(int i = beginidx; s[i] != '\0'; i++){
                if(check.find(s[i]) != check.end()) continue;
                check.insert(s[i]);
                swap(s[i],s[beginidx]);
                permutationcore(s,beginidx+1);
                swap(s[i],s[beginidx]);
            }
        }
    }
    vector<string> permutation(string s) {
        if(s.empty()) return {};
        permutationcore(s,0);
        return result;
    }
private:
    vector<string> result;
};