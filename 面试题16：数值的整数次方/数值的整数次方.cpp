//题目
//实现函数double Power(double base,int exponent),求base的exponent次方。
//不得使用库函数，同时不需要考虑大数问题

//注意要点
//base = 0 return 0.0
//exponent = 0 return 1
//exponent < 0 return 1/(base * |exponent|)
//快速幂方法 O(lgN)

//书本版本
#define DBL_EPSILON      2.2204460492503131E-16 
double myPow(double base, int n)
{
    //if(base == 0) return 0.0;//double 判断为0 的方式
    if(base >= -DBL_EPSILON && base <= DBL_EPSILON ) return 0.0;;//DBL_EPSILON 是 1.0 + DBL_EPSILON  不等于 1.0 最小的正数
    if(n == 0) return 1.0;
    double result = 1.0;
    int x = base;
    unsigned int absn  =(unsigned int) n; 
    if(n < 0) absn = (unsigned int)-n;
    while(absn > 0)
    {
        if(absn %2) result = result * x;
        x = x * x;
        absn /= 2;
    }

    if(n < 0) result = 1/result;
    return result;

}

//LeetCode 版本
class Solution{
public:
double myPow(double x, int n){
    if(x >= -DBL_EPSILON && x <= DBL_EPSILON) return 0.0;
    if(n == 0) return 1.0;
    double  result = 1.0;
    unsigned int absn = (unsigned int)n;
    if(n < 0) absn = (unsigned int)(-absn);//absn 必须为unsigned int或更大的数类型，防止int最小值变为最大值时的溢出
    while(absn > 0)
    {
        if(absn % 2) result = x * result;
        x = x * x;
        absn /= 2;
    }
    if(n < 0) result = 1/result;
    return result;
}
};