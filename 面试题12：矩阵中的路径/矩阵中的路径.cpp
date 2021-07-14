#include<vector>
using namespace std;
//题目
//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串的所有字符的路径。路径可以从
//矩阵中的任意一格开始，每一步可以在矩阵中 向左，右，上，下移动一格。如果一条路径经过了矩阵
//的某一格，那么该路径不能再次进入该格子

//算法1：回溯法
//二维图找路径的常用算法

//书上版本
bool hasPath(char* matrix, int rows, int cols, char*str)
{
     if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr) return false;
     bool *visited = new bool[rows * cols];
     memset(visited,0,rows * cols);

    int pathLength = 0;
    for(int row = 0; row <rows; ++row){
        for(int col = 0; col < cols; ++col){
            if(hasPathCore(matrix,row,col,rows,cols,pathLength,str,visited)){
                delete[] visited;
                return true;
            }
        }
    }    
    delete[] visited;
    return false;
}

bool hasPathCore(char *matrix,int row, int col, int rows, int cols, int pathLength, char *str, bool *visited)
{
    if(str[pathLength] == '\0') return true;
    if(row >= 0 && row < rows && col > 0 && col < cols 
      && matrix[row * cols + col] == str[pathLength] 
      && visited[row * cols + col] != false){
          visited[row * cols + cols] = true;
          if(hasPathCore(matrix,row+1,col,rows,cols,pathLength + 1,str,visited) ||
             hasPathCore(matrix,row-1,col,row,cols,pathLength + 1,str,visited) ||
             hasPathCore(matrix,row,col+1,rows,cols,pathLength + 1,str,visited) ||
             hasPathCore(matrix,row,col-1,rows,cols,pathLength + 1,str,visited)){
                 return true;
             }
             visited[row * cols + cols] = false;
      }
      return false;
}

//LeetCode 版本
class Solution{
public:
bool existCore(vector<vector<char>> &board, int row, int col, int pathLength, string& word){
    if(word[pathLength] == '\0') return true;
    
    if(row>= 0 && row <rows && col >= 0 && col < cols
      &&board[row][col] == word[pathLength]
      &&visited[row*cols+ col] == false){
          visited[row * cols + col] = true;
          if(existCore(board, row - 1, col, pathLength + 1, word)
           ||existCore(board, row + 1, col, pathLength + 1, word)
           ||existCore(board, row, col + 1, pathLength + 1, word)
           ||existCore(board, row, col - 1, pathLength + 1, word)){
               return true;
           }
           visited[row * cols + col] = false;
      }
      return false;
}
bool exist(vector<vector<char>> &board, string word){
    if(word.empty()) return false;
    rows = board.size();
    cols = board[0].size();
    visited = new bool[rows * cols];
    memset(visited,0,rows*cols);
    int pathLength = 0;
    for(int row = 0; row < rows; ++ row){
        for(int col = 0; col < cols; ++ col){
            if(existCore(board,row,col,pathLength,word)){
                delete[] visited;
                visited = nullptr;
                return true;
            }
        }
    }
    delete[] visited;
    visited = nullptr;
    return false;
}
private:
int rows;
int cols;
bool *visited;
};