//
//  string.cpp
//  code_exercise
//
//  Created by Hei Yanbin on 14-5-2.
//  Copyright (c) 2014年 Hei Yanbin. All rights reserved.
//
#include<iostream>
using namespace std;
char*  LCS(char * a, char * b)
{
    if(!a||!b) return NULL;
    int maxLen=0,maxPostion=0;
    for(int i=0;a[i];i++)
    {
        for(int j=0;b[j];j++)
        {
            int len =0;
            while(a[i+len] && b[i+len] && a[i+len]==b[j+len])
            {
                len++;
            }
            if(maxLen<len)
            {
                maxLen=len;
                maxPostion=i;
            }
        }
    }
    char* LCS = new char[maxLen+1];
    for(int i=0;i<maxLen;i++)
    {
        LCS[i]=a[maxPostion+i];
    }
    LCS[maxLen]='\0';
    return LCS;
}
void testLCS()
{
    cout<<LCS("abcdxyz", "xyuuuabbcd")<<endl;
}

char * LRS (char * a)
{
    if(!a) return NULL;
    int maxLen=0, maxPostion=0;
    for(int i=0;a[i];i++)
    {
        for(int j=i+1;a[j];j++)
        {
            int t = 0;
            while(i+t < j && a[i+t] && a[j+t] && a[i+t] == a[j+t])
            {
                t++;
            }
            if(t>maxLen)
            {
                maxLen = t;
                maxPostion = i;
            }
        }
    }
    char * s = new char[maxLen];
    for(int i=0; i<maxLen;i++)
        s[i]=a[maxPostion+i];
    s[maxLen]='\0';
    return s;
}
void testLRS()
{
    cout<<LRS("abc111abc1abc1aabcd")<<endl;
}
char * maxHuiwen(char *a)
{
    if(!a) return NULL;
    if(!(a+1)) return a;
    
    int maxLen = 0, maxPostion = 0;
    for(int i=0;a[i];i++)
    {
        int t=0;
        while(i-t>=0 && a[i+1+t] && a[i-t]==a[i+1+t])
            t++;
        int len = 2*t;
        if(len>maxLen)
        {
            maxLen = len;
            if(a[i-t]==a[i+1+t])
                maxPostion = i-t;
            else
                maxPostion = i-t+1;
        }
        
        t=0;
        while(i-t>=0 && a[i+t] && a[i-t]==a[i+t])
            t++;
        len = 1+t*2;
        if(len>maxLen)
        {
            maxLen = len;
            if(a[i-t]==a[i+t])
                maxPostion = i-t;
            else
                maxPostion = i-t+1;
        }
    }
    char * s = new char[maxLen];
    for(int i=0;i<maxLen;i++)
        s[i]=a[maxPostion+i];
    s[maxLen]='\0';
    return s;
}
void testMaxHuiwen()
{
    maxHuiwen("");
    cout<<maxHuiwen("xaabbbbaaabbbb")<<endl;
}