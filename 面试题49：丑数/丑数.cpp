//题目
//我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
//一个丑数可以由另一个丑数乘2，3，5得到
//存在一个丑数，该丑数之前的丑数*2小于当前最大的丑数，该丑数之后*2大于当前最大的丑数。*3，*5同理
//下一个丑数就是上述三个位置丑数乘以对应基数的最小者
#include<vector>
#include<string>
using namespace std;
class Solution{
public:
    int min(int a, int b, int c){
        int res = a<b?a:b;
        res = res<c?res:c;
        return res;
    }
    int nthUglyNumber(int n){
        if(n<0)return 0;
        vector<int> uglyNumber(n,0);
        uglyNumber[0] = 1;
        int curidx = 1;
        int t2 = 0,t3 = 0, t5 =0; 
        while(curidx < n){
            int temp = min(uglyNumber[t2]*2, uglyNumber[t3]*3, uglyNumber[t5]*5);
            while(uglyNumber[t2] != 0 && uglyNumber[t2]*2 <= temp){
                ++t2;
            }
            while(uglyNumber[t3] != 0 && uglyNumber[t3]*3 <= temp){
                ++t3;
            }
            while(uglyNumber[t3] != 0 && uglyNumber[t5]*5 <= temp){
                ++t5;
            }
            uglyNumber[curidx]= temp;
            ++curidx;
        }
        return uglyNumber[n-1];
    }
};

//优化一下
class Solution{
public:
    int min(int a, int b, int c){
        int res = a<b?a:b;
        res = res<c?res:c;
        return res;
    }
    int nthUglyNumber(int n){
        if(n<0)return 0;
        vector<int> uglyNumber(n,0);
        uglyNumber[0] = 1;
        int t2 = 0,t3 = 0, t5 =0; 
        for(int curidx=1; curidx< n;++curidx){
            int a = uglyNumber[t2]*2, b = uglyNumber[t3]*3, c = uglyNumber[t5]*5;
            int temp = min(a,b,c);
            uglyNumber[curidx]= temp;
            if(temp == a) ++t2;
            if(temp == b) ++t3;
            if(temp == c) ++t5;
        }
        return uglyNumber[n-1];
    }
};