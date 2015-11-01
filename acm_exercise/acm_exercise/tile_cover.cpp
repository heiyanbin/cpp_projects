#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    
}

void sortB1(int A[], int m, int B[],int n)
{
    unordered_set<int> bSet;
    for(int i=0;i<n;i++)
        bSet.insert(B[i]);
    for(int i=0,j=0;i<m;i++)
        if(bSet.find(A[i])!=bSet.end())
            B[j++]=A[i];
}

void sortB(int A[], int m, int B[], int n)
{
    unordered_map<int,int> pos;
    for(int i=0;i<m;i++)
        pos[A[i]]==i;
    sort(B,B+n, [&](int a, int b){return pos[a]<pos[b];});
}