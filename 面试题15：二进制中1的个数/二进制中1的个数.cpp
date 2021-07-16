//题目
//请实现一个函数，输入一个整数，输出该二进制表示中1的个数。
//例如，把9表示成二进制是1001，有2位是1。因此，如果输入9，则该函数输出2.

//算法1：循环左移
//使用左移可以避免由右移引起的死循环
int Numberof1(int n)
{
    int count = 0;
    int flag = 1;
    while(flag){
        if(flag & n) count ++;
        flag << 1;
    }
    return count;
}
//算法2：减1的奥秘
//减1可以让最右边的1变成0，且该位右边都取反
int Numberof1(int n)
{
    int count =0;
    while(n){
        count ++;
        n = n & n-1;
    }
    return count;
}

