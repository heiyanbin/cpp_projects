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


void testFast_sort()
{
    int a[] = {7,3,4,8,8,5,1,2,4};
    fast_sort(a, 0, 8);
    printArray(a, 9);
}
