//题目
//输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个
//lambda表达式的应用，以及string x+y < y + x

#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
public:
    string minNumber(vector<int>& nums){
        vector<string> array;
        string res;
        for(auto num:nums){
            array.push_back(to_string(num));
        }
        sort(array.begin(),array.end(),[](string &x, string &y){return x+y < y+x;});
        for(auto str:array){
            res.append(str);
        }
        return res;
    }
};