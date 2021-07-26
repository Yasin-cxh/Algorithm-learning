//题目
//输入一个矩阵，按照从外向里以顺时针的顺序一次打印出每个数字。例如，如果输入以下矩阵
//1     2       3       4
//5     6       7       8
//9     10      11      12
//13    14      15      16
//则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10

//书本版本
//每次走完一个圈,圈的起点是(start,start) start E[0,min(rows-1,columns-1)/2];
//第一步必须有
//第二步至少二行一列
//第三步至少二行二列
//第四步至少三行二列
#include<stdio.h>
void spiralOrder(int **matrix, int rows, int columns)
{
    if(matrix == nullptr || rows <= 0 || columns <= 0) return;
    int min = rows<columns? (rows-1)/2:(columns-1)/2;
    for(int start = 0; start <= min;start++){
        int endX = columns-1-start;
        int endY = rows-1-start;
        //从左到右
        for(int i = start; i<= endX; i++){
            printf("%d ",matrix[start][i]);
        }
        //从上到下
        if(endY>start){
            for(int i = start+1; i<= endY; i++){
                printf("%d ",matrix[i][endX]);
            }
        }
        //从右到左
        if(endX>start && endY > start){
            for(int i = endX-1;i>=start; i--){
                printf("%d ",matrix[endY][i]);
            }
        }
        //从上到下
        if(endX > start && endY > start + 1){
            for(int i = endX-1; i >start; i--){
                printf("%d ",matrix[i][start]);
            }
        }
    }
    return;
}

//LeetCode版本
//绕圈法
#include<vector>
using namespace std;
class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix){
        vector<int> result;
        int rows = matrix.size();
        if(rows == 0) return result;
        int cols = matrix[0].size();
        if(cols == 0) return result;
        int min = rows<cols? (rows-1)/2:(cols-1)/2;
        for(int start = 0; start <= min; start ++){
            int endX = cols-1-start;
            int endY = rows-1-start;
            //从左到右
            for(int j = start; j <= endX; j++){
                result.push_back(matrix[start][j]);
            }
            //从上到下
            if(endY > start){
                for(int i = start+1; i<= endY; i++){
                    result.push_back(matrix[i][endX]);
                }
            }
            //从右到左
            if(endY > start && endX > start){
                for(int j = endX-1;j>=start;j--){
                    result.push_back(matrix[endY][j]);
                }
            }
            //从下到上
            if(endY > start + 1 && endX > start){
                for(int i = endY-1; i > start; i--){
                    result.push_back(matrix[i][start]);
                }
            }
        } 
        return result;
    }
};

//边界收缩
class Solution1{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix){
        vector<int> result;
        if(matrix.size() == 0 || matrix[0].size() == 0) return result;
        int top = 0, left = 0, bottom = matrix.size()-1, right = matrix[0].size()-1;

        while(true){
            for(int i = left; i<=right; i++) result.push_back(matrix[top][i]);
            if(++top > bottom) break;
            for(int i = top; i <= bottom; i++) result.push_back(matrix[i][right]);
            if(--right < left) break;
            for(int i = right; i >= left; i--) result.push_back(matrix[bottom][i]);
            if(--bottom < top) break;
            for(int i = bottom; i >= top; i--) result.push_back(matrix[i][left]);
            if(++left > right) break;
        }
        return result;
    }
};