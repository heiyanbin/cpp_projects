#include "lib.h"


void combine_backtrack(int a[], int n, int m, int t, int s, int x[])
{
    assert(a && x && n>0);
    if(t>m-1)
    {
        printArray(x,m);
    }
    else
    {
        for(int i=s;i<n;i++)
        {
            x[t]=a[i];
            combine_backtrack(a,n,m,t+1, i+1, x);
        }
    }
}

void test_combine_backtrack()
{
    int a[] = {1,2,3,4};
    int m= 3;
    int *x = new int[3];
    memset(x,0, sizeof(int)*m);
    combine_backtrack(a, 4, m, 0, 0, x);
}