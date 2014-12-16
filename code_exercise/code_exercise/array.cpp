//
//  array.cpp
//  code_exercise
//
//  Created by Hei Yanbin on 14-4-20.
//  Copyright (c) 2014年 Hei Yanbin. All rights reserved.
//
#include <vector>
#include "lib.h"

using namespace std;
void relocateOddAndEven(int a[], int n)
{
    if (!a || n<=2) {
        return;
    }
    int i = 0, j = n -1;
    while (i<j)
    {
        while ((a[i]&1)==1 && i < j)
        {
            i++;
        }
        while ((a[j]&1)==0 && i< j)
        {
            j--;
        }
        if (i<j) {
            swap(a[i],a[j]);
        }
    }
}
void relocateOddAndEven2(int a[], int n)
{
    if(!a || n<=2)
        return;
    int i= 0, j=0;
    while (j<n)
    {
        if ((a[j]&1)==1) {
            swap(a[i],a[j]);
            i++;
        }
        j++;
    }
    
}

void findSumInSortedArray(int a[], int n, int sum)
{
    if(!a || n<2) return;
    int i = 0, j= n-1;
    while (i < j)
    {
        int x =a[i]+a[j];
        if(x==sum)
        {
            std::cout<<a[i]<<','<<a[j]<<std::endl;
            i++;
            j--;
        }
        else if(x > sum)
            j--;
        else
            i++;
    }
}

int findTopKIn2SortedArray(int a[],int b[], int m, int n, int k)
{
    if(!a ||!b||n<1||k<1||k>n+m) return -1;
    int i=0, j=0, x=a[0],num=0;
    
    while(i<m&&j<n&&num<k)
    {
        if(a[i]<b[j])
        {
            x=a[i];
            i++;
        }
        else
        {
            x=b[j];
            j++;
        }
        num++;
    }
    if(num==k)
        return x;
    else if(i<m)
        return a[i+k-num-1];
    else
        return b[j+k-num-1];
}

int binarySearchInShiftedSortedArray(int a[], int n, int x)
{
    if(!a||n<1) throw std::invalid_argument("invalid arguement.");
    int begin = 0, end = n-1;
    while(begin<=end)
    {
        int mid = (begin+end)/2;
        if(a[mid]>a[begin])
        {
            if(x<a[mid])
            {
               if(x>a[begin])
                   end = mid -1;
               else if(x<a[begin])
                   begin=mid+1;
               else
                   return begin;
            }
            else if (x>a[mid])
                begin= mid + 1;
            else
                return mid;
        }
        else
        {
            if(x<a[mid])
                end = mid -1;
            else if (x>a[mid])
            {
                if (x<a[end])
                    begin = mid +1;
                else if (x> a[end])
                    end = mid -1;
                else
                    return end;
            }
            else
                return mid;
        }
    }
    return -1;
}
int findMidIn2SortedArray(int a[], int b[], int n)
{
    if(!a||!b||n<1) throw std::invalid_argument("Array is NULL.");
    if (n==1) {
        return a[0];
    }
    if(n==2)
    {
        if(a[0]<b[0])
            return min(a[1],b[0]);
        else if(a[0]>b[0])
            return min(b[1],a[0]);
        else
            return min(b[1],a[1]);
    }
    int mid =(n-1)/2;
    if(a[mid]==b[mid])
        return a[mid];
    else if(a[mid]<b[mid])
        return findMidIn2SortedArray(&a[mid], b, n-mid);
    else
        return findMidIn2SortedArray(a, &b[mid], n-mid);
    
}
int findMidIn2SortedArray2(int a[],int m, int b[], int n)
{
    if(!a||!b||m<1||n<1) throw new std::invalid_argument("invalid argument.");
    if(m==1 && n==1) return min(a[0],b[0]);
    if(m>n)
        return findMidIn2SortedArray2(b, n, a, m);
    
    int x = b[(n-1)/2];
    if(m==1)
    {
        if((n&1)==1)
        {
            if (a[0]<=x)
                return a[0];
            else
                return x;
        }
        else
        {
            if(a[0]<=x)
                return x;
            else
                return a[0];
        }
    }
    if(m==2)
    {
        if(a[0]<=x && x<=a[1])
            return x;
        if(x< a[0])
            return min(a[0],b[(n-1)/2+1]);
        else
            return max(a[1],b[(n-1)/2-1]);
    }
    int mida = (m-1)/2;
    int midb = (n-1)/2;
    if(a[mida]==b[midb])
        return a[mida];
    else if(a[mida]<b[midb])
    {
        return findMidIn2SortedArray2(&a[mida], m-mida, b, n-mida);
    }
    else
    {
        return findMidIn2SortedArray2(a, mida+1, b+(m-mida-1), n-(m-mida-1));
    }
    
}

int findMaxSubArraySum(int a[],int n)
{
    if(!a||n<1) throw std::invalid_argument("invalid argument.");
    int sum = 0, maxSum = 0;
    for(int i= 0;i<n;i++)
    {
        if(sum<0) sum = 0;
        sum += a[i];
        if(maxSum<sum) maxSum = sum;
    }
    return maxSum;
}
int findMaxSubArraySumDP(int a[], int n)
{
    if(!a||n<1)throw std::invalid_argument("invalid argument");
    int maxSum = a[0], maxSumEndwithPreviousItem= a[0];
    for(int i = 1; i<n; i++)
    {
        maxSumEndwithPreviousItem= max(maxSumEndwithPreviousItem+a[i],a[i]);
        maxSum = max(maxSum,maxSumEndwithPreviousItem);
    }
    return maxSum;
        
}
static vector<int> v;
void perm(int a[],int begin, int end,int n)
{
    if(begin>end)
    {
       // printVector(v);
        printArray(a, n);
        return;
    }
    for(int i=begin;i<=end;i++)
    {
        int j=begin;
        while(a[i]!=a[j]&&j<i)
            j++;
        if(j<i) //has duplicate value before, and has been select as the first one, pass
            return;
        
        swap(a[begin],a[i]);
       // v.push_back(a[begin]);
        perm(a,begin+1,end,n);
        swap(a[begin],a[i]);
       // v.pop_back();
    }
}
void combine(int a[],int m, int begin, int end)
{
    if(!a) throw invalid_argument("array is null");
    if(m<1)
    {
        printVector(v);
        return;
    }
    
    v.push_back(a[begin]);
    combine(a, m-1, begin+1, end);
    v.pop_back();
    if(end-begin+1>m)
        combine(a, m, begin+1, end);
}

 void MSQuestions_6(int a[], int b[], int n)
{
    if(!a ||!b|| n<1) throw invalid_argument("invalid argument");
    int test =1;
    bool changed = true;
    while(changed)
    {
        changed =false;
        for(int i=0;i<n;i++)
        {
            if(a[i]>n||a[i]<0)
            {
                b[i]=0;
            }
            else
            {
                int count =0;
                for(int j=0;j<n;j++)
                {
                    if(b[j]==a[i]) 
                        count++;
                }
                if(b[i]!=count)
                {
                    b[i]=count;
                    changed = true;
                }
            }
        }
    }
    
}
int partition3(int a[], int begin, int end)
{
    if(end-begin<1) return end - begin;
    int i=begin+1;
    for(int j=begin+1;j<end;j++)
    {
        if(a[j]<a[begin])
        {
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[begin],a[i-1]);
    return i-1;
}
int partition2(int a[], int begin, int end)
{
    if(begin>end) return -1;
    if(begin==end) return 0;
    int x=a[begin];
    while(begin<end)
    {
        while(begin<end && a[end]>=x)
            end--;
        if(begin<end)
            a[begin]=a[end];
        while(begin<end && a[begin]<x)
            begin++;
        if(begin<end)
            a[end]=a[begin];
    }
    a[begin]=x;
    return begin;
}
int partition1(int a[], int begin, int end)
{
	if(begin>end) return -1;
    if(begin==end) return 0;
    int i= begin+1,j=end;
    while(i<j)
    {
        while(i<j && a[i]<a[begin])
            i++;
        while(i<j && a[j]>=a[begin])
            j--;
        if(i<j)
            swap(a[i],a[j]);
    }
    if(a[i]<a[begin])
        i++;
    swap(a[i-1],a[begin]);
    return i-1;
}
void testCombine()
{
    int a[] = {1,2,3,4};
    combine(a,2,0,3);
}
void testPerm()
{
    int a[]={1,2,3,3};
    perm(a,0,3,4);
}
void testFindMaxSubArraySum()
{
    int a[] = {-2,-1,-3,-1,-7,-4,-5};
    std::cout<<findMaxSubArraySum(a,7)<<std::endl;
    std::cout<<findMaxSubArraySumDP(a,7)<<std::endl;
}
void testFindMidIn2SortedArray()
{
    int a[] = {1,3,5,7,9,11};
    int b[] = {2,4,6,8,10};
    std::cout<<findMidIn2SortedArray2(a,6,b,5)<<std::endl;
}

void testBinarySearchInShiftedSortedArray()
{
    int a[] = {5,6,7,7,8,1,2,3,4};
    int i = binarySearchInShiftedSortedArray(a, 9, 6);
    std::cout<<(i<0?i:a[i])<<std::endl;
    
}

void testFindTopKIn2SortedArray()
{
    int a[] = {0,2,4,6,7};
    int b[] = {0,1,3,8};
    std::cout<<findTopKIn2SortedArray(a,b,5,4,7)<<std::endl;
}
void testFindSumInSortedArray()
{
    int a[] = {1,3,4,8,9,5,6,11};
    findSumInSortedArray(a, 8, 15);
}
void testRelocateOddAndEven()
{
    int a[] = {1,2,3,4,5,6,7,8};
   // relocateOddAndEven(a, 8);
    printArray(a, 8);
    relocateOddAndEven2(a,8);
    printArray(a, 8);
}

void testMSQuestions_6()
{
    int a[] = {0,1,2,3,4,5};
    int b[6] ={0};
    MSQuestions_6(a,b,6);
    printArray(a,6);
    printArray(b,6);
}
