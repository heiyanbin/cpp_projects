﻿//有一个整型偶数n(2<= n <=10000),你要做的是：先把1到n中的所有奇数从小到大输出，再把所有的偶数从小到大输出。
//输入
//第一行有一个整数i（2<=i<30)表示有 i 组测试数据；
//每组有一个整型偶数n。
//输出
//第一行输出所有的奇数
//第二行输出所有的偶数
//样例输入
//2
//10
//14
//样例输出
//1 3 5 7 9 
//2 4 6 8 10 
//
//1 3 5 7 9 11 13 
//2 4 6 8 10 12 14 

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