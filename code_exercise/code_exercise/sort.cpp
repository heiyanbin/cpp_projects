//
//  sort.cpp
//  code_exercise
//
//  Created by Hei Yanbin on 14-4-19.
//  Copyright (c) 2014年 Hei Yanbin. All rights reserved.
//


#include "lib.h"

template <typename T>
void fast_sort(T a[], int begin, int end)
{
    //recursion exit
    //when not a valid array, or begin > end or only 1 element (begin==end), we don't do anything, just return
    if (!a || begin >= end) {
        return;
    }
    
    //select the first item as axis, partition the array
    T x = a[begin];
    int i = begin, j= end;
    while (i<j)
    {
        while(i<j && a[j]>=x)
            j--;
        if(i<j)
        {
            a[i]=a[j];
            i++;
        }
        while (i<j && a[i]<x) {
            i++;
        }
        if(i<j)
        {
            a[j]=a[i];
            j--;
        }
    }
    a[i]=x;
    fast_sort(a, begin, i-1);
    fast_sort(a, i+1, end);
}
template <typename T>
void merge_array(T a[], int begin,int mid,int end)
{
    if(!a||begin>mid||mid>end) return;
    int k=0,i=begin,j=mid+1;
    T *c = new T[end-begin+1];
    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=end)
        c[k++]=a[j++];
    for(int i=0;begin+i<=end;i++)
        a[begin+i]=c[i];
    delete[] c;
}
template <typename T>
void merge_sort(T a[],int begin, int end)
{
    if(!a||begin>=end) return;
    int mid = (begin+end)/2;
    merge_sort(a, begin, mid);
    merge_sort(a, mid+1, end);
    merge_array(a,begin,mid,end);
}
template <typename T>
void bubble_sort(T a[], int n)
{
    if(!a || n<2) return;
    int m = n-1;
    bool changed = true;
    while(m>=0 && changed)
    {
        changed = false;
        for(int i=0;i<m;i++)
        {
            if(a[i]>a[i+1]) 
            {
                swap(a[i],a[i+1]);
                changed = true;
            }
        }
        m--;
    }
}
template <typename T>
void select_sort(T a[], int n)
{
    if(!a || n<2) return;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i]) 
                swap(a[i],a[j]);
        }
    }
}
template <typename T>
void insert_sort(T a[], int n)
{
    if(!a || n<2) return;
    for(int i=1;i<n;i++)
    {
        int x = a[i];
        int j=i-1;
        while(j>=0 && x<a[j])
        {    
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

template <typename T>
void count_sort(T a[], int n)
{
    if(!a||n<2) return;
    int min=a[0], max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<min) min= a[i];
        if(a[i]>max) max= a[i];
    }
    int range = max-min+1;
    int *c = new int[range];
    for(int i=0;i<range;i++)
        c[i]=0;

    for(int i=0;i<n;i++)
    {
        c[a[i]-min]++;
    }
    int j=0;
    for(int i=0;i<range;i++)
    {
        
        while(c[i]>0)
        {
            a[j]=min+i;
            j++;
            c[i]--;
        }
    }
    delete[] c;
}

template <typename T>
void bucket_sort(T a[], int n)
{

}
template <typename T>
void base_sort(T a[],int n)
{
    int b[10];

}
void testFast_sort()
{
    int a[] = {7,3,4,8,8,5,1,2,4};
    fast_sort(a, 0, 8);
    printArray(a, 9);
}
void testSort()
{
    int x[] = {7,3,4,8,8,5,1,2,4};
    int a[9];
    printArray(x,9);
    
    memcpy(a,x,sizeof(int)*9);
    cout<<"merge sort:"<<endl;
    merge_sort(a, 0, 8);
    printArray(a, 9);

    memcpy(a,x,sizeof(int)*9);
    cout<<"fast sort:"<<endl;
    fast_sort(a, 0, 8);
    printArray(a, 9);

    memcpy(a,x,sizeof(int)*9);
    cout<<"bubble sort:"<<endl;
    bubble_sort(a, 9);
    printArray(a, 9);

    memcpy(a,x,sizeof(int)*9);
    cout<<"select sort:"<<endl;
    select_sort(a, 9);
    printArray(a, 9);

    memcpy(a,x,sizeof(int)*9);
    cout<<"insert sort:"<<endl;
    insert_sort(a, 9);
    printArray(a, 9);

    memcpy(a,x,sizeof(int)*9);
    cout<<"count sort:"<<endl;
    count_sort(a, 9);
    printArray(a, 9);
}
