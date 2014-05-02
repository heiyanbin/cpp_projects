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
    int maxLen=0, len=0, maxPostion=0;
    for(int i=0;a[i];i++)
    {
        for(int j=0;b[j];j++)
        {
            len =0;
            while(a[i+len]==b[j+len])
            {
                len++;
                if(maxLen<len)
                {
                    maxLen=len;
                    maxPostion=i;
                }
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