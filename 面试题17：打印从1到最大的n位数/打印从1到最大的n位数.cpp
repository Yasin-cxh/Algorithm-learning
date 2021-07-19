//题目
//输入数字n，按顺序打印出从1到最大的n位十进制数。
//比如输入3，则打印出1、2、3一直到最大的3位数999

//考察要点：大数问题下的打印
//算法1：字符串模拟加法
bool IncreNum(char *number)
{   
    bool isOverFlow = false;
    int sum = 0, carry = 0;
    int len = strlen(number);
    for(int i = len -1 ; i >= 0; --i)
    {
        sum = number[i] - '0' + carry;
        if(i == len - 1){
            sum ++;
        }
        if(sum == 10){
            if(i == 0){
                isOverFlow = true;
                break;
            }
        carry = 1;
        sum -= 10;
        }else{
            carry = 0;
        }
        
        number[i] = '0' + sum; 
    }
    return isOverFlow;

}

void PrintNum(char *number)
{
    bool isStartZero = true;
    int len = strlen(number);
    for(int i = 0;i < len; i++){
        if(number[i] != '0' && isStartZero){
            isStartZero = false;
        } 
        if(!isStartZero){
            printf("%c",number[i]);
        }
    }
    printf("\t");

}
void PrintMaxN(int n)
{
    if(n <= 0) return ;
    char *number  = new char[n+1];
    memset(number,'0',n);
    number[n] = '\0';
    while(IncreNum(number)){
        PrintNum(number);
    }
    delete[] number;
}

//算法2：递归全排列
void Recursion(char *number, int len, int index)
{
    if(index = len -1){
        PrintNum(number);
        return;
    }
    for(int i = 0; i < 10; i++){
        number[i + 1] = '0' + i;
        Recursion(number, len, index + 1);
    }
    
}

void PrintMaxNRecursily(int n)
{
    if(n <= 0) return;
    char *number = new char[n+1];
    memset(number,'0',n);
    number[n] = '\n';
    for(int i = 0; i < n;i++){
        number[0] = i;
        Recursion(number,0,n); 
    }
}

#include<vector>
using namespace std;
//LeetCode 版本实在是太拉了
class Solution{
public:
    vector<int> printNumber(int n){
        int max = 1;
        int x = 10;
        vector<int> result;
        while(n>0){
            if(n % 2) max = x * max;
            x = x * x;
            n /= 2;
        }
        for(int i = 1; i < max ;i++){
            result.push_back(i);
        }
        return result;
    }
};