#include<string>
#include<vector>
using namespace std;

class SummaryRanges {
public:
    SummaryRanges() {

    }
    /*
    *模拟法
    *1.数组为空，直接插入
    *2.插入分为五 种情况
    *(1)数值落在某区间内，不处理
    *(2)数值比当前区间开始值小1，扩大当前区间，考虑是否合并前区间
    *(3)数值比当前区间结束值大1，扩大当前区间，考虑是否合并后区间
    *(4)数值处于当前区间和前区间之中，新增区间
    *(5)数值处于当前区间和后区间之中，新增区间
    
    */
    void addNum(int val) {
        if(ans.empty()){
            vector<int> temp(2,0);
            temp[0] = val;
            temp[1] = val;
            ans.push_back(temp);
        }
        else{
            for(int i = 0; i < ans.size(); i++){
                if(val >= ans[i][0] && val <= ans[i][1]) break;
                else if (val == ans[i][0] - 1){
                    ans[i][0] = val;
                    if(i>0 && ans[i-1][1] == ans[i][0]){
                        ans[i-1][1] = ans[i][1];
                        ans.erase(ans.begin() + i);
                        break;
                    }
                }
                else if (val == ans[i][1] + 1){
                    ans[i][1] = val;
                    if(i < ans.size() - 1 && ans[i + 1][0] == ans[i][1] ){
                        ans[i+1][0] = ans[i][0];
                        ans.erase(ans.begin() + i);
                        break;
                    }
                }
                else if( val < ans[i][0] -1 && (i == 0 || (i > 0 && val > ans[i-1][1] + 1))){
                    vector<int> temp(2,0);
                    temp[0] = val;
                    temp[1] = val;
                    ans.insert(ans.begin() + i, temp);
                    break;
                }
                else if( val > ans[i][1] + 1 && (i == ans.size() -1 || (i < ans.size() - 1 && val < ans[i + 1][0]-1))){
                    vector<int> temp(2,0);
                    temp[0] = val;
                    temp[1] = val;
                    ans.insert(ans.begin()+i+1, temp);
                    break;
                }
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        return ans;
    }
private:
    vector<vector<int>> ans;
};