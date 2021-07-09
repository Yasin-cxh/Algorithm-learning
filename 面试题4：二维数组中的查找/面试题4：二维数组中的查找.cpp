//题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个
//二维数组和一个整数，判断数组中是否含有该函数

//关键在于 从行，列中找到“异或最值”，找到行最大，列最小(即从右上角往左下角缩小范围)
//或者找到 行最小，列最大(即从左下角往右上角缩小范围)
//从右上角往左下角 缩小
#include <vector>
bool Find_top_right_to_bottom_left(const int *matrix, int rows, int columns, int number)
{
    bool result = false;
    if(matrix == nullptr || rows <= 0 || columns <= 0)
    {
        return result;
    }

    int row = 0;
    int column = columns-1;
    while(row<rows && column>=0)
    {
        if(*(matrix + row*columns + column) == number){
            result = true;
            break;
        }

        if(*(matrix + row*columns + column) > number)
            -- column;
        else 
            ++ row;

    }
    return result;
}

//从左下角去右上角
bool Find_bottom_left_to_top_right(const int* matrix,int rows, int columns, int number)
{
    bool result = false;
    if(matrix == nullptr || rows <=0 || columns <= 0)
    {
        return result;
    }

    int row = rows - 1;
    int column = 0;
    
    while(column<columns && row>=0)
    {
        if(matrix[row*columns + column] == number)
        {
            result = true;
            break;
        }

        if(matrix[row*columns + column] > number)//二维数组是按行存放的
            --row;
        else
            ++column;
    }
    return result;
}

// leetcode C++
// 从右上角到左下角
class Solution{
public:
    bool findNumberIn2DArray(std::vector<std::vector<int> >& matrix, int target){
    if(matrix.empty())//审题，不管有没有要求都要做异常处理
    {
        return false;
    }
    
    int row = 0;
    int column = matrix[0].size() - 1;
    while(row < matrix.size() && column >= 0)
    {
        if(matrix[row][column] > target) column --;
        else if(matrix[row][column] < target) row ++;
        else return true;
    }
    }
};

//从左下角到右上角
class Solution
{
public:
bool findNumberIn2DArray(std::vector<std::vector<int> > &matrix,int target){
    if(matrix.empty())
        return false;
    int row = matrix.size() - 1;
    int column = 0;
    bool result = false;
    while(row >= 0 && column < matrix[0].size()){
        if(matrix[row][column] == target){
            result = true;
            break;
        }
        if(matrix[row][column] > target) 
            -- row;   //最小的比它大就找更小的
        else
            ++ column;//最大的比它小就找更大的
    }
    return result;
}

};