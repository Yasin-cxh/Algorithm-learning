/*
* 题目一：找出数组中重复的数字
* 在一个长度为n的数组里的所有数字都在0~n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
* 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组
* {2，3，1，0，2，5，3}，那么对应输出的重复的数字2或者3.
*/

//算法1：直接排序 
//时间O(nlgn) 空间O(1)
//排序专题后面专门练


//算法2：鸽巢原理，原地置换
//时间O(n),空间O(1)
//鸽巢原理简述：
//若有n个笼子和kn+1只鸽子，那么至少有一个笼子有至少k+1只鸽子
//数字范围数组长度内，又有重复的数字，则必然有一个位置存在两个以上的数字
#include<vector>
bool duplicate(int numbers[],int length,int *duplication)
{
    if(numbers == nullptr || length <= 0)//特殊条件判断
    {
        return false;
    }

    for(int i = 0; i< length;++i)
    {
        if(numbers[i]<0 || numbers[i] >= length)
        {
            return false;
        }
    }

    //原地交换
    for(int i = 0; i < length; ++i)
    {
        while(i != numbers[i])
        {
            if(numbers[numbers[i]] == numbers[i] )
            {
                *duplication = numbers[i];
                return true;
            }
            int temp = numbers[i];
            numbers[i] = numbers[temp];//这里不能写numbers[numbers[i]],因为numbers[i]的值已经变了
            numbers[temp] = temp;// 要写成numbers[temp] = temp; 
        }
    }
    return false; 
}

//C++实现，以leetcode为准
class Solution
{
public:
int findRepeatNumber(std::vector<int> &nums){
  int length = nums.size();
  for(int i = 0;i < length;++i){
    while(nums[i] != i){
        if(nums[i] == nums[nums[i]]){
            return nums[i];
        }
        int temp = nums[i];
        nums[i] = nums[temp];
        nums[temp] = temp;
    }
  }
}
};

//题目2：不修改数组找出重复的数字
//在一个长度为n+1的数组里的所有数字都在1~n的范围内，所以数组中至少有一个数字是重复的。
//请找出数组中任意一个重复的数字。但不能修改输入的数组。例如，如果输入长度为8的数组
//{2,3,5,4,3,2,6,7},那么对应的输出是重复的数字2或者3

//解法1：新建数组，再按题目1的方式去解
//时间：O(n),空间：O(n)

//解法2：二分查找(二分专题也要练)
//时间：O(nlogn),空间O(1)
//每次找分为两个区域，统计区域内的数字个数，如果数字个数大于区间长度，则一定有重复数字
//二分思路：
//1.start <= end? 是继续，不是推出
//2.确定中间值, mid = (end - start)>>2 + start;
//3.处理一个半区，如果是左半区符合条件，则end = mid，如果是右半区符合条件，则start = mid + 1
//4.start == end? 是返回start，不是重复1，2，3
int getDuplication(const int* numbers,int length)
{
    if(numbers == nullptr || length <= 0)
    {
        return -1;
    }
    for(int i =0; i < length; ++i)
    {
        if(numbers[i] < 1 || numbers[i] > length -1)
        {
            return -1;
        }
    }
    int start = 1;//这边是值
    int end = length -1;
    int mid;
    while(start <= end)
    {
        mid = (end - start) >> 1 + start;
        int count  = CountRange(numbers,length,start,mid);
        if(start == end){
            if(count > 1)
                return start;
            else 
                return -1;
        }

        if(count > mid - start + 1)//区间数量要加1，减法得到的是间隔
            end = mid;
        else 
            start = mid;
    }
    return -1;

}
int CountRange(const int* numbers, int length, int start, int end)
{
    int count = 0;
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i]>=start || numbers[i] <= end)
        {
            ++count;
        }
    }
    return count;
}

//二分法leetcode C++ 解法
//这题用二分法解不了
class Solution{
public:
    int findRepeatNumber(std::vector<int>& nums){
        int start = 0;
        int end = nums.size()-1;
        int mid;
        int count = 0;
        while(start <= end)
        {
            mid = (end -start)>>1 + start;
            count = 0;
            for(int i = 0; i < nums.size(); ++i)
            {
                if(nums[i] >= start && nums[i] <= mid)
                {
                    ++count;
                }
            }
            if(start == end)
            {
                if(count > 1)
                return start;
            }

            if(count > mid - start + 1)//只适合每个位置都有数字的情况，而且数字不适合从0开始
                end = mid;
            else 
                start = mid + 1;
        }
        return -1;
    }
};
