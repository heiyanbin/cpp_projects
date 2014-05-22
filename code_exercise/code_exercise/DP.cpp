#include "lib.h"

int min_number_of_coin(int coin[], int coin_num, int value)
{
    assert(coin && coin_num >0 && value >=0);
    int *d = new  int[value+1];
    d[0]=0;

    for(int v = 1;v<=value;v++)
    {
        d[v]= 65536;
        for(int j=0;j<coin_num;j++)
        {
            if(coin[j]<=v && d[v-coin[j]]+1<d[v])
            {
                d[v] = d[v-coin[j]]+1;
            }
        }
    }
    
    int ret = d[value];
    delete [] d;
    return ret;
}
int min_number_of_coin_recursive(int coin[], int coin_num, int value)
{
    assert(coin && (coin_num>0 || value == 0));
    if(value==0) return 0;
    int min=65536;
    for(int i=0;i<coin_num;i++)
    {
        if(coin[i]<=value)
        {
            int c = min_number_of_coin_recursive(coin, coin_num, value-coin[i])+1;
            if(c<min)
                min= c;
        }
    }
    return min;
}
int LIS(int a[], int n)
{
    assert(a && n>0);
    int maxLen=0;
    int *d = new int[n];
    for(int i=0;i<n;i++)
    {
        d[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[i]>=a[j] && d[j]+1 >d[i])
                d[i]=d[j]+1;
        }
        if(d[i]>maxLen) maxLen = d[i];
    }
    delete [] d;
    return maxLen;
}
int LISRecursive(int a[], int n)
{
    assert( a && n>0);
    if(n==1) return 1;
    int maxLen =1;
    for(int i=0;i<n-1;i++)
    {
        if(a[n-1]>=a[i])
        {
            int len = LISRecursive(a, i+1)+1;
            if(len>maxLen)
                maxLen=len;
        }
    }
    return maxLen;
}
int LSIS(int a[], int n)
{
    assert(a && n>0);
    int maxLen=1;
    int maxLenEndWithPre =1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=a[i-1] )
        {   
            maxLenEndWithPre++;
            if(maxLenEndWithPre>maxLen)
                maxLen = maxLenEndWithPre;
        }
        else
            maxLenEndWithPre=1;
    }
    return maxLen;
}
int LSISEndWithLastRecursive(int a[], int n)
{
    if(!a||n==0) return 0;
    if(n==1) return 1;
    if(a[n-1]>=a[n-2])
        return LSISEndWithLastRecursive(a, n-1)+1;
    return 1;
}
int LSIS3(int a[], int n)
{
    if(!a||n<0) return 0;
    if(n==1) return 1;
    int maxLen=0;
    for(int i=0;i<=n;i++)
    {
        int len = LSISEndWithLastRecursive(a, i);
        if(len>maxLen)
            maxLen = len;
    }
    return maxLen;
}
int LSISRecursive(int a[], int n)
{
    if(!a||n<0) return 0;
    if(n==1) return 1;
    if(a[n-1]>=a[n-2])
        return max(LSISRecursive(a, n-1), LSISEndWithLastRecursive(a, n-1)+1);
    return LSISRecursive(a, n-1);
}
int LSIS2(int a[], int n)
{
    assert(a && n>0);
    int *maxLen= new int[n];
    int *maxLenEndWithPre = new int[n];
    maxLen[0]=1;
    maxLenEndWithPre[0]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=a[i-1] )
        {   
            maxLenEndWithPre[i]=maxLenEndWithPre[i-1]+1;
            maxLen[i]= max(maxLenEndWithPre[i],maxLen[i-1]);
        }
        else
        {
            maxLenEndWithPre[i]=1;
            maxLen[i]=maxLen[i-1];
        }
    }
    return maxLen[n-1];
}


void testMin_number_of_coin()
{
    int coin[] = {1,2,5};
    for(int i=0;i<20;i++)
    {
        cout<<min_number_of_coin(coin, 3, i)<<"  ";
        cout<<min_number_of_coin_recursive(coin, 3, i)<<endl;
        assert(min_number_of_coin(coin, 3, i) ==min_number_of_coin_recursive(coin, 3, i));
    }
}

void testLIS()
{
    int A[] = {5, 3, 4, 8, 6, 7};
    cout<<LIS(A, 6)<<endl;
    cout<<LISRecursive(A, 6)<<endl;
    cout<<LSIS(A, 6)<<endl;
    cout<<LSIS2(A, 6)<<endl;
    cout<<LSIS3(A, 6)<<endl;
    cout<<LSISRecursive(A, 6)<<endl;
    
}