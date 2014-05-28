#include "lib.h"

int min_number_of_coin_DP(int coin[], int n, int value)
{
    assert(coin && n >0 && value >=0);
    int *d = new  int[value+1];
    d[0]=0;

    for(int v = 1;v<=value;v++)
    {
        d[v]= 65536;
        for(int j=0;j<n;j++)
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
//assuming the coin value is already sorted descendingly
int min_number_of_coin_Greedy(int coin[],int coin_num,int value, vector<int> &vector)
{
    assert(coin && value>=0);
    if(value==0) return 0;
    int num=0;
    int i=0;
    while(value>0 && i< coin_num )
    {
        while(coin[i]<=value)
        {
            vector.push_back(coin[i]);
            num++;
            value -= coin[i];
        }
        i++;
    }
    return num;
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
int combine_of_coin(int coin[], int n, int value)
{
    assert(coin && n>=0 );
    if(value<0) return 0;
    if(value==0) return 1;
    if(n==0) return 0;
    return combine_of_coin(coin, n, value-coin[0]) + combine_of_coin(coin+1,n-1,value);
}
int combine_of_coin_TrackBack(int coin[], int n, int value)
{
    assert (coin && n>=0);
    if(value<=0 || n==0) return 0;  
    int *coin_count = new int[n];
    int sum =0;
    int i=0;
    while(sum<value)
    {
        
    }
    throw exception();
}
int combine_of_coin_DP(int coin[], int n, int value)
{
    assert(coin && n>=0 && value>=0);
    int **dp = new int*[value+1];
    for(int i=0;i<=n;i++)
        dp[i] = new int[n+1];
    for(int i=0;i<=value;i++)
    {
        for(int j= 0;j<=n;j++)
        {
            if(j==0 && i==0) return 1;
            else if(j==0) dp[i][j] =0;
            else if(i==0) dp[i][j] =1;
            else 
            {   
                dp[i][j]=dp[i][j-1] + dp[i-coin[j-1]][j];
            }
        }
    }
    return dp[value][n];
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

int max_value_in_bag(int c[], int v[], int n, int C)
{
    assert(c && v );
    int *d = new int[C+1];
    d[0]=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=C;j>0;j--)
        {
            if(i==0) 
                d[j]=0;
            else 
            {
                if(c[i-1]<=j )
                    d[j]  =  max(d[j], d[j-c[i-1]] + v[i-1]);
                else
                    d[j] = d[j];
            }
        }
    }
    return d[C];
}
int max_value_in_bag_recursive(int c[], int v[], int n, int C)
{
    assert(c && v);
    if(n==0 ||C==0) return 0;
    if(c[0]<=C)
    {
        return max(max_value_in_bag_recursive(c+1, v+1,n-1,C-c[0])+v[0], max_value_in_bag_recursive(c+1,v+1,n-1,C));
    }
    else
        return max_value_in_bag_recursive(c+1,v+1,n-1,C);
}

int max_value_in_bag_backtrack(int c[], int v[], int n, int C)
{
    assert(c && v);
    if(n==0 ||C==0) return 0;
    int* pick = new int[n];
    int *f = new int[n];
    for(int i=0;i<n;i++) 
        f[i]=0;
    int g =1;
    int t=0;
    int grab = 0;
    int maxValue = 0;
    
    while( t>=0)
    {
        if(f[t]<=g)
        {
            for(int i=f[t];i<=g;i++)
            {
                pick[t]=i;
                if(t<n && grab+pick[t]*c[t]<C) //bound & constrant
                {
                    grab = grab + pick[t];
                    f[t]=i+1;
                    if(t==n-1) //isSolution ?
                    {
                        int sumValue =0;
                        for(int k=0;k<n;k++)
                        {
                            if(pick[k])
                                sumValue+= v[k];
                        }
                        if(sumValue>maxValue)
                            maxValue =sumValue;
                    }
                    t++;
                }
                else
                    f[t]=i+1;
            }
        }
        else
            t--;
       
    }
    return maxValue;
}
void testMin_number_of_coin()
{
    int coin[] = {1,2,5};
    reverseArray(coin,3);
    vector<int> v;

    for(int i=0;i<=10;i++)
    {
      //  cout<<min_number_of_coin(coin, 3, i)<<"  ";
      //  cout<<min_number_of_coin_recursive(coin, 3, i)<<endl;
        assert(min_number_of_coin_DP(coin, 3, i) ==min_number_of_coin_recursive(coin, 3, i));
        assert(min_number_of_coin_DP(coin, 3, i) == min_number_of_coin_Greedy(coin, 3, i,v));
        printVector(v);
        v.clear();
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

void test_max_value_in_bag()
{
    int c[] ={5,4,3,2};
    int v[] ={10,10,12,5};
    cout<<max_value_in_bag(c,v,4, 13)<<endl;
    cout<<max_value_in_bag_recursive(c,v,4,13)<<endl;
    for(int i=0;i<20;i++)
        assert(max_value_in_bag(c,v,4, i) == max_value_in_bag_recursive(c,v,4,i));

    cout<<max_value_in_bag_backtrack(c,v,4,13)<<endl;
}

void testCombine_of_coin()
{
    int coin[] = {1,2,5};
    int i =combine_of_coin(coin, 3, 6);
    int j =combine_of_coin_DP(coin, 3, 6);
}