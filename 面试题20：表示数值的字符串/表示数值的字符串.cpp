//题目
//请实现一个函数用来判断是否表示数值(包括整数和小数)
//例如，字符串"+100", "5e2""-123""3.1416"及"-1E-16"都表示数值
//但是"12e" "1a3.14" "1.2.3" "-+5"以及"12e+5.4" 都不是

//思路：
//(SA)(.)(UB)(E|e)(SC)
//SA:有符号数 UB:无符号数 SC:有符号数
bool scanInteger(const char ** pstr)
{
    if(**pstr == '+' || **pstr == '-')
        ++(*pstr);
    return scanUninteger(pstr);
}

bool scanUninteger(const char **pstr)
{
    const char* before = *pstr;
    while((**pstr) >='0'  &&(**pstr) <= '9'){
        ++(*pstr);
    }
    return (*pstr)>before;
}

bool isNum(const char *str)
{
    if(str == nullptr) return false;
    bool result = scanInteger(&str);//为什么这里要用引用呢?
    //result 表示当前字符串是不是数字
    if(*str == '.'){
        ++str;
        result = scanUninteger(&str) || result;
    }
    if(*str == 'e' || *str == 'E'){
        ++str;
        result = scanInteger(&str) && result;
    }
    return result && (*str == '\0');
}
//Leetcode版本
#include <string>
using namespace std;
class Solution {
public:
    bool scanUnteger(string s, int &index)
    {
        bool result = false;
        while(index != s.size() && s[index] >= '0' && s[index] <= '9'){
            ++index;
            result = true;
        }
        return result;
    }
    bool scanInteger(string s, int &index)
    {
        if(s[index] == '+' || s[index] == '-')
            ++index;
        return scanUnteger(s,index); 
    }
    bool isNumber(string s) {
        if(s.empty()) return false;
        int index = 0;
        while(index != s.size() && s[index] == ' ')
            ++index;
        bool result = scanInteger(s,index);
        if(s[index] == '.')
        {
            ++index;
            result = scanUnteger(s,index) || result;
        }
        if(s[index] == 'E' || s[index] == 'e')
        {
            ++index ;
            result = scanInteger(s,index) && result;          
        }
        while(index!= s.size() &&s[index] == ' ')
            index ++;
        return result && (s[index] == '\0');
    }
};

//这道题是不是能用动态规划做啊？
