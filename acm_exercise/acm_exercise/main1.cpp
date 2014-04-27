#include<iostream>
using namespace std;
void main1()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=a[i];j=j+2)
            cout<<j<<' ';
        cout<<endl;
        for(int j=2;j<=a[i];j=j+2)
            cout<<j<<' ';
        cout<<endl;
    }
    delete[] a;
}