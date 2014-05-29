//
//  lib.h
//  code_exercise
//
//  Created by Hei Yanbin on 14-4-19.
//  Copyright (c) 2014年 Hei Yanbin. All rights reserved.
//

#ifndef code_exercise_lib_h
#define code_exercise_lib_h

#include <iostream>
#include <vector>
#include <cassert>

#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b
using namespace std;

void mySort(int[], int);
void testFindK();
void testFast_sort();
void testRelocateOddAndEven();
void testFindSumInSortedArray();
void testFindTopKIn2SortedArray();
void testBinarySearchInShiftedSortedArray();
void testFindMidIn2SortedArray();
void testFindMaxSubArraySum();
void testPerm();
void testCombine();
void testRotateMatrix();
void testEvalSubfix();
void testMidfixToSubfix();
void testEvalMidfix();
void testNormalizePath();
void testLCS();
void testLRS();
void testMaxHuiwen();
void testMyAtoi();
void testMyItoa();
void testHeapSort();
void testSort();
void testMSQuestions_6();
void testMyStrstr();
void testMyStrcmp();
void testReverseNum();
void testPrimeFactor();
void testIsHuiwenNum();
void testGcd();
void testLcm();
void testSequentialSum();
void testMin_number_of_coin();
void testLIS();
void test_max_value_in_bag();
void testCombine_of_coin();
void test_combine_backtrack();
void test_subset();
void test_combine_of_parentheses();
/*template <typename T>
void swap(T &a, T &b)
{d
    T temp = a;
    a=b;
    b=temp;
}*/
template <typename T>
void printArray(T a[],int n)
{
    if(!a||n<1) return;
    for (int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<std::endl;
}
template <typename T>
void printVector(vector<T> v)
{
    for(int i=0;i< v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
template <typename T> void reverseArray(T a[], int n)
{
    assert(a && n>0);
    int i= 0, j=n-1;
    while(i<j)
    {
        swap(a[i],a[j]);
        i++;
        j--;
    }
}
#endif
