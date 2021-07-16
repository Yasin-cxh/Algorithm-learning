//求余关系式
//(xy)⊙p=[(x⊙p)(y⊙p)]⊙p

//求余算法
//算法1：循环取余
//时间：O(n) 空间:O(1)
//x 底数， y 指数， p 模
int mod(int x, int y, int p)
{
 int res = 1;
 for(int i = 0; i<y; i++){
     res = (res * x) % p;
 }
 return res;
}
//算法2:快速幂求余
//时间：O(logn) 空间O(1)
int mod1(int x, int y, int p)
{
    int res = 1;
    while(y>0){
        if(y%2) res = (res * x) %p;//妙啊
        x = (x**2)%p;
    }
    return res;
}
//贪心算法
class Solution{
public:
int cuttingRope(int n){
        if(n <= 3) return n-1;
        int y = n/3 -1, b = n%3, mod = 1e9+7;
        long long x = 3, res = 1;
        while(y > 0){
            if(y%2) res = (res * x) %mod;
            x = (x *x)%mod;
            y /= 2;
        }
        if(b == 0) res = (res * 3)%mod;
        if(b == 1) res = (res * 4)%mod;
        if(b == 2) res = (res * 6)%mod;
        return (int)res;
}
};