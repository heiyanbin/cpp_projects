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

int myAtoi(char *a)
{
    if(!a||!(*a)) throw invalid_argument("invalid argument");
    bool negtive = false;
    if(*a=='-')
    {
        negtive = true;
        a++;
    }
    int value = 0;
    while(*a)
    {
        if(*a<'0'||*a>'9') throw invalid_argument("invalid number format");
        value = value*10 + *a -'0';
        a++;
    }
    return negtive ? -value : value;
}
void testMyAtoi()
{
    cout<<myAtoi("-123")<<endl<<myAtoi("789")<<endl<<myAtoi("-0")<<endl;
    cout<<myAtoi("")<<endl;
}

char* myItoa(int x)
{
    bool negtive = false;
    if(x==0) return "0";
    if(x<0)
    {
        negtive = true;
        x=-x;
    }
    int n = 0;
    int y = x;
    while(y>0)
    {
        y=y/10;
        n++;
    }
    char * a, *p;
    if(!negtive)
    {
        a= new char[n+1];
        p=a;
    }
    else
    {
        a = new char[n+2];
        *a='-';
        p=a;
        p++;
    }
    
    int t = 1;
    while(n>1)
    {
        t=t*10;
        n--;
    }
    int i=0;
    while(x>0)
    {
        p[i]=x/t+'0';
        x=x%t;
        t=t/10;
        i++;
    }
    p[i]='\0';
    return a;
}

void testMyItoa()
{
    cout<<myItoa(0)<<endl<<myItoa(-123)<<endl<<myItoa(456)<<endl;
}

int myStrstr(const char* a, const char* b)
{
    if(!a||!(*a)) return -1;
    if(!b||!(*b)) return 0;
    for(int i=0;a[i];i++)
    {
        int j=0;
        while( b[j] && a[i+j] && a[i+j]== b[j])
        {
            j++;
        }
        if(!b[j]) return i;
        if(!a[i+j]) return -1;
    }
    return -1;
}
int myStrstr2(const char*a, const char* b)
{
    if(!a||!(*a)) return -1;
    if(!b||!(*b)) return 0;
    int i=0,j=0;
    while(a[i])
    {
        while(a[i] && b[j] && a[i]==b[j])
        {
            i++;
            j++;
        }
        if(!b[j]) return i-j;
        if(!a[i]) return  -1;
        i=i-j+1;
        j=0;
    }
    return -1;
}
char* myStrstr3 ( char* a,  char *b)
{
    if(!a||!(*a) ) return NULL;
    if(!b || !(*b)) return a;
    while(*a)
    {
        int i=0;
        while(a[i] && b[i] && a[i]==b[i])
        {
           i++;
        }
        if(!(b[i])) return a;
        if(!(a[i])) return NULL;
        a++;
    }
}
void testMyStrstr()
{
    cout<<myStrstr("abcde","de")<<endl;
    cout<<myStrstr("abcde", "ab")<<endl;
    cout<<myStrstr("abcde", "bc")<<endl;
    cout<<myStrstr("abcde", "xx")<<endl;
    cout<<myStrstr("abcde", "")<<endl;
    cout<<myStrstr("abcde", NULL)<<endl;

    cout<<myStrstr2("abcde","de")<<endl;
    cout<<myStrstr2("abcde", "ab")<<endl;
    cout<<myStrstr2("abcde", "bc")<<endl;
    cout<<myStrstr2("abcde", "xx")<<endl;
    cout<<myStrstr2("abcde", "")<<endl;
    cout<<myStrstr2("abcde", NULL)<<endl;

    cout<<myStrstr3("abcde","de")<<endl;
    cout<<myStrstr3("abcde", "ab")<<endl;
    cout<<myStrstr3("abcde", "bc")<<endl;
    cout<<myStrstr3("abcde", "xx")<<endl;
    cout<<myStrstr3("abcde", "")<<endl;
    cout<<myStrstr3("abcde", NULL)<<endl;
}

int myStrcmp(const char* a, const char* b)
{
    if(!a && !b) return 0;
    if(!a && b) return -1;
    if(a && !b) return 1;
    if(!(*a)&&!(*b)) return 0;
    if(*a==*b) return myStrcmp(a+1, b+1);
    return *a > *b ? 1 : -1;
}
int myStrcmp2(const char* a, const char* b)
{
    if(!a&&b) return -1;
    if(!a&&!b) return 0;
    if(a&&!b) return 1;
    while(*a && *b && *a==*b)
    {
        a++;
        b++;
    }
    if(!(*a)&&!(*b)) return 0;
    if(*a && !(*b)) return 1;
    if(!(*a) && *b) return -1;
    return *a>*b? 1: -1;
}

void testMyStrcmp()
{
    cout<<myStrcmp("abc", "abcd")<<' '<<myStrcmp2("abc", "abcd")<<endl;
    cout<<myStrcmp("abc", "abc")<<' '<<myStrcmp2("abc", "abc")<<endl;
    cout<<myStrcmp("abc", "aaa")<<' '<<myStrcmp2("abc", "aaa")<<endl;
}
