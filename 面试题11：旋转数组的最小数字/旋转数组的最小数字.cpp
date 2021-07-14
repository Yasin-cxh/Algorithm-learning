//题目
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个递增排序的数组的一个旋钮，输出旋转数组的最小元素。例如
//数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1

//算法1：朴素的思想
//遍历一遍，o(n)时间，属于通解，没有利用到旋转数组的性质

//算法2：二分思想
//时间 O(lgn)
//旋转：区域划分，有分区性质都可以使用二分
//思路：维护两个指针，start指针始终指向第一个分区，end指针始终指向第二个分区
//mid元素大于start元素，说明mid在第一个分区，且最小的元素在中间元素后面，有start = mid
//同样的，mid元素小于end元素，说明mid指针在第二个分区，且最小元素为当前元素，或者在当前元素之前，有end = mid
//二分结束条件 end = start + 1,此时 end 指向的元素即为最小的元素
//存在bug 如果中间元素 = start 元素 = end 元素，此时不知道中间元素属于哪个区间，只能按朴素思想遍历[start,end]区间

//书本版本
int Main(int *nums, int len)
{
    if(nums == nullptr || len <= 0)
        return -1;
    int start = 0;
    int end = len - 1;
    int mid = 0;
    int target = 0;
    while(nums[start] > nums[end]){
        if(end == start + 1){
            target = end;
            break;
        }
        mid = (end-start) >> 1 + start;
        if(nums[mid] > nums[start]) start = mid;
        else if( nums[mid] < nums[end]) end = mid;
        else if (nums[start] = nums[mid] && nums[end] == nums[mid]){
            for(int i = start; i < end; ++i){
                if(nums[i+1] < nums[i]){
                    target = i + 1;
                    break;
                }
            }
        }
    }
    return nums[target];
}

//LeetCode 版本
//写了这么多的特例属实不是一个好解答
class Solution{
public:
    int minArray(vector<int> &numbers){
        if(numbers.empty()) return -1;
        int start = 0;
        int end = numbers.size() - 1;
        int mid = 0;
        int target = 0;
        while(numbers[start] > numbers[end]){
            if(end == start + 1){
                target = end;
                break;
            }
            mid = ((end - start)>>1) + start;

            if(numbers[start] == numbers[mid] && numbers[end] == numbers[mid]){
                for(int i = start; i <end; ++i){
                    if(numbers[i+1] == numbers[i]){
                        target = i+1;
                        break;
                    }
                }
                 break;
            }
            if(numbers[mid] >= numbers[start]) start = mid;
            else if (numbers[mid] <= numbers[end]) end = mid;
            
        }
        return numbers[target];
    }
};



//LeetCode K神的题解真不错
//思路：
//二分法
//start = 0,end = len -1, mid = (start + end)/2 ① (or start + (end -start)>>1)
//因为mid算式①所以有start <= mid < end
//二分步骤(本质是缩小范围)
// if numbers[mid] > numbers[end] ,则mid在左半区，旋转点在mid后， start = mid + 1;
// if numbers[mid] < numbers[end], 则mid在右半区，旋转点在mid前或者就是mid， end = mid；
// if numbers[mid] == numbers[end], 无法判断mid在左半区还是右半区，可以使用end--缩小范围，或者使用线性遍历方法
// 当 numbers[mid] == numbers[end]时，如果mid在左半区，有 numbers[mid] >= numbers[start] 又有 numbers[start] >= numbers[end] == numbers[mid],
// 所以numbers[start] = numbers[mid],且[start,mid]区间内所有元素相等。同理，如果mid在右半区，则有[mid,end]区间内所有元素相等
// 二分法结束条件 start == end return numbers[start]
class Solution{
public:
int minArray(vector<int> &numbers){
    if(numbers.empty()) return -1;
    int start = 0;
    int end = numbers.size() - 1;
    int mid;
    while(start < end){
        mid = (start + end) / 2;//((end - start)>>1) + start;//mid = (start + end)/2 更快
        // >>1 比 / 快， 但是后者的运算量多
        if(numbers[mid] < numbers[end]) end = mid;
        else if (numbers[mid] > numbers[end]) start = mid + 1;
        else end --;
    }
    return numbers[start];
}
};