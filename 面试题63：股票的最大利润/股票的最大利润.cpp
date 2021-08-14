//题目
//假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
//维护一个最小值和最大值
//遍历到第i个数字时，先比较最小值，更新最小值，再减去最小值，就是第i个数字的利润,如果利润大于max，更新max
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int min = prices[0], max = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < min) min = prices[i];
            int temp = prices[i] - min;
            if(temp > max) max = temp;
        }
        return max;
    }
};