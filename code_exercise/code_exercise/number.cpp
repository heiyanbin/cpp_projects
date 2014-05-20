#include "lib.h"
using namespace std;

unsigned int fabonacci(unsigned int n)
{
    
    if(n==0) return 0;
    if(n==1) return 1;
    return fabonacci(n-1)+fabonacci(n-2);
}

unsigned int fabonacci2(unsigned int n)
{
    if(n==0)return 0;
    if(n==1) return 1;
    int f0=0,f1=1, fn;
    for(int i=2;i<=n;i++)
    {
        fn=f1+f0;
        f0=f1;
        f1=fn;
    }
    return fn;
}

int count_1(int num)
{
    int count =0;
    while(num>0)
    {
        if((num&1)==1)
            count++;
        num=num>>1;
    }
    return count;
}

int reverse(int n, int &result)
{
    if(n<0) 
    {
        reverse(-n, result);
        result = -result;
    }
    else if(n<10) result = n;
    else
    {
        while(n>0)
        {
            int d = n%10;
            result = result *10 +d;
            n=n/10;
        }
    }
}