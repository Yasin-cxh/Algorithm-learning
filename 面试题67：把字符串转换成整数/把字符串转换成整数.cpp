//题目
//写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。
#include<string>
using namespace std;
class Solution {
public:
    int getNum(string str, int idx , int flag){
        long long num = 0;
        for(int i = idx; i < str.size(); i++){
            if(str[i] >= '0' && str[i] <= '9'){
            num = num*10 + flag * (str[i]-'0');
            if(num > INT_MAX) return INT_MAX;
            if(num < INT_MIN) return INT_MIN;
            }
            else{
                break;
            }
        }
        return num;
    }
    int strToInt(string str) {
        if(str.empty())return 0;
        int flag = 1;
        int i =0;
        int res = 0;
        while(i<str.size() && str[i] == ' '){
            i++;
        }
        if(i<str.size()){
            if(str[i] == '+'){
                res = getNum(str,i+1,flag);    
            }
            else if (str[i] == '-'){
                flag = -1;
                res = getNum(str,i+1,flag);
            }
            else if(str[i]>='0' && str[i] <= '9'){
                res = getNum(str,i,flag);
            }
        }
        return res;
    }
};

