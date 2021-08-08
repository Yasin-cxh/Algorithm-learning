//题目
//在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
//你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
//给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
//dp方程 dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j]
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
    public:
    int maxValue(vector<vector<int>> &grid){
        if(grid.empty()) return 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j< cols; j++){
                int left= 0, up = 0;
                if(i>0)up = dp[i-1][j];
                if(j>0)left = dp[i][j-1];
                
                dp[i][j] = max(left,up) + grid[i][j]; 
            }
        }
        return dp[rows-1][cols-1];
    }
};