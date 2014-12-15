/*
Multiples of 3 and 5
Problem 1
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.*/
#include<vector>
#include<iostream>
using namespace std;
int pe1()
{
    int sum =0;
    for(int i=1;i*3<1000;++i)
        sum += i*3;
    for(int i=1;i*5<1000;++i)
        if((i*5)%3!=0)
            sum += i*5;
    return sum;
}
