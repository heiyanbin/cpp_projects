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
                {    //when go to next level, remember 2 things:
                    s[t]=i+1; //move the current level's candidates  to next
                    t++;
                    s[t]=i+1; //set the new level's first candidate 
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
        subset(a,n,t+1,i+1,x);
    }
}

void combine_of_parentheses(int n, int t, char x[], int curLeftCount, int curRightCount, int & result)
{
    if(t>2*n-1)
    {
        for(int i=0;i<t;i++)
            cout<<x[i];
        cout<<endl;
        result++;
    }
    else
    {
        if(curLeftCount<n)
        {
            x[t]='(';
            combine_of_parentheses(n,t+1, x, curLeftCount+1, curRightCount, result);
        }
        if(curRightCount<curLeftCount) 
        {
            x[t] = ')';
            combine_of_parentheses(n,t+1, x, curLeftCount, curRightCount+1, result);
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
    int a[] = {1,2,3,4,5};
    int x[5];
    subset(a, 5, 0, 0, x);
}

void test_combine_of_parentheses()
{
    char x[100];
    int result =0;
    int leftCount = 0;
    int rightCount = 0;
    combine_of_parentheses(4,0,x,leftCount, rightCount, result);
    cout<<result<<endl;
}