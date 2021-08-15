//题目
//求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
//n(n+1)/2
//求bool t[n][n+1] 的size /2
using namespace std;
class Solution {
public:
    int sumNums(int n) {
        bool arr[n][n+1];
        return sizeof(arr)>>1;
    }
};

//使用虚函数
class A;
A *arr[2];
class A{
    public:
    virtual int Sum(int n){
        return 0;
    }
};

class B:public A{
    public:
    virtual int Sum(int n){
        return arr[!!n]->Sum(n-1) + n;  
    }
};

class Solution1 {
public:
    int sumNums(int n) {
         A a;
         B b;
         arr[0] = &a;
         arr[1] = &b;
         return b.Sum(n);
    }
};