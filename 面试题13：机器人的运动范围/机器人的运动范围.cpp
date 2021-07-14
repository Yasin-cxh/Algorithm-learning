#include<vector>
using namespace std;
//题目
//地上有一个m行n列的方格。一个机器人从坐标(0,0)的格子开始移动，它每次可以向左、右、上、下移动一格，
//但不能进入行坐标和列坐标的数位之和大于K的格子。例如，当k为18时，机器人能够进入方格(35,37),因为
//3+5+3+7 = 18。但它不能进入方格(35,38),因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

//和面试题12差不多

//书本版本
int movingCount(int threshold, int rows, int cols)
{
    if(threshold < 0 || rows < 1 || cols < 1) return 0;
    int row = 0;
    int col = 0;
    int count = rows * cols;
    bool* visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);

    movingCountCore(threshold,rows,cols,row,col,visited,count);
    return count;
    
}

int bitSum(int num1, int num2)
{
    int sum = 0;
    int temp = 0;
    while(num1 != 0){
        temp = num1 % 10;
        sum += temp;
        num1 /= 10;
    }
    while(num2 != 0){
        temp = num2 % 10;
        sum += temp;
        num2 /= 10;
    }
    return sum;
}

void movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited,int & count)
{
    //if(visited[row * cols + col] == true) return;

    if(row >= 0 && row < rows && col >= 0 && col < cols 
      && visited[row * cols + col] == false){
        if(bitSum(row,col) > threshold){
        visited[row * cols + col] = true;
        -- count;
        return ;
        }
        movingCountCore(threshold,rows,cols,row + 1, col ,visited,count);
        movingCountCore(threshold,rows,cols,row - 1, col ,visited,count);
        movingCountCore(threshold,rows,cols,row, col - 1, visited,count);
        movingCountCore(threshold,rows,cols,row, col - 1, visited,count);
    }
}

//LeetCode版本
//count 个数不能用减的， 要用加的，因为这题如果用减的，有的位置访问不到，是不能正确算出实际的数字
//采用 count = 1 + 四个方位的递归
class Solution{
public:
int bitSum(int m, int n){
    int sum = 0;
    int temp = 0;
    while(m != 0){
        temp = m % 10;
        sum += temp;
        m /= 10;
    }
    while(n != 0){
        temp = n % 10;
        sum += temp;
        n /= 10;
    }
    return sum;
}
int movingCountCore(int row ,int col, int m,int n, int k, bool * visited)
{
    int count = 0;
    if(row >=0 && row < m && col >= 0 && col < n 
      && bitSum(row,col) <= k && visited[row * n + col] == false){
          visited[row * n + col ] = true;
          count = 1 + movingCountCore(row + 1,col,m,n,k,visited) 
                    + movingCountCore(row - 1,col,m,n,k,visited)
                    + movingCountCore(row,col + 1,m,n,k,visited)
                    + movingCountCore(row,col - 1,m,n,k,visited);
    }
    return count;
}
int movingCount(int m, int n, int k){
    if(m < 1 || n < 1 || k < 0) return 0;
    bool *visited = new bool[m*n];
    memset(visited,0,m*n);
    int count = 0;
    count = movingCountCore(0,0,m,n,k,visited);
    delete[] visited;
    return count;
}
};