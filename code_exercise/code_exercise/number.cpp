#include <cmath>
#include "lib.h"

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
    if (num<0) return count_1(-num)+1;
    int count =0;
    while(num>0)
    {
        if((num&1)==1)
            count++;
        num=num>>1;
    }
    return count;
}

int reverseNum(int n)
{
    if(n<0) return -reverseNum(-n);
    if(n<10) return n;
    int result=0;
    while(n>0)
    {
        int d = n%10;
        result = result *10 +d;
        n=n/10;
    }
    return result;
}
void primeFactor(int n)
{
    if(n==0) throw invalid_argument(NULL);
    if(n<0) {primeFactor(-n);return;}
    int x= sqrt(n);
    for(int i=2;i<=x;i++)
    {
        while ((n%i)==0)
        {
            cout<<i<<" ";
            n=n/i;
        }
    }
    cout<<endl;
}
bool isHuiwenNum(int n)
{
    int m =0;
    int n1= n;
    while(n1>0)
    {
        m= m * 10 + n1%10;
        n1=n1/10;
    }
    return m==n;
}
int gcd(int a, int b)
{
    int r=0;
    while((r=a%b)!=0)
    {
        a=b;
        b=r;
    }
    return b;
}
int lcm(int a, int b)
{
    assert(a && b);
    return a*b/gcd(a,b);
}
void findSequentialSum(int n)
{
    assert(n>2);
    int i=1, j=2;
    int sum=i+j;
    while(j<(n+1)/2)
    {
        if(sum==n)
        {
            for(int k=i;k<=j;k++)
                cout<<k<<" ";
            cout<<endl;
        }
        if(sum<n)
        {
            j++;
            sum = sum +j;
        }
        else
        {
            i++;
            sum= sum-i;
        }
    }
}

void testReverseNum()
{
    assert(reverseNum(123)==321);
    assert(reverseNum(-123)==-321);
}
void testPrimeFactor()
{
    primeFactor(36);
    primeFactor(-40);
}
void testIsHuiwenNum()
{
    assert(isHuiwenNum(1234321));
    assert(isHuiwenNum(0));
    assert(isHuiwenNum(1));
    assert(isHuiwenNum(123)==false);
}
void testGcd()
{
    assert(gcd(64,48)==16);
    assert(gcd(12,20)==4);
    assert(gcd(4,8)==4);
    assert(gcd(7,9)==1);
}
void testLcm()
{
    assert(lcm(6,8)==24);
    assert(lcm(4,10)==20);
    assert(lcm(3,5)==15);
}
void testSequentialSum()
{
    findSequentialSum(15);
    findSequentialSum(25);
}