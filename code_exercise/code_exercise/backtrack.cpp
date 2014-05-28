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
void combine_backtrack_iterative(int a[], int n, int m)
{
    assert(a && n>0 );
    int *x = new int[m];
    int *s = new int[n];
    s[0]=0;
    int t =0;
    while(t>=0)
    {
        if(s[t]<n)
        {
            for(int i=s[t];i<n;i++)
            {
                x[t]=a[i];
                if(t==m-1)
                {
                    printArray(x, m);
                }
                if(t<m-1)
                {
                    s[t]=i+1;
                    t++;
                    s[t]=i+1;
                    break;
                }
                s[t]=i+1;
            }
        }
        else
        {
            s[t]=t;
            t--;
        }
        
    }
    delete[] x;
}

void subset(int a[], int n, int t, int s, int x[])
{
    assert(a && x && n>=0 && t>=0);
    for(int i=s;i<n;i++)
    {
        x[t]=a[i];
        printArray(x, t+1);
        if(t<n-1)
        {
            subset(a,n,t+1,i+1,x);
        }
    }
}

void test_combine_backtrack()
{
    int a[] = {1,2,3,4};
    int m= 3;
    int *x = new int[m];
    combine_backtrack(a, 4, m, 0, 0, x);
    delete[] x;
    cout<<"------"<<endl;
    combine_backtrack_iterative(a,4,m);
}

void test_subset()
{
    int a[] = {1,2,3,4};
    int x[4];
    subset(a, 3, 0, 0, x);
}