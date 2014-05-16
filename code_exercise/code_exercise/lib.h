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

#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b
using namespace std;
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
void testMerge_sort();
void testMSQuestions_6();
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
#endif
