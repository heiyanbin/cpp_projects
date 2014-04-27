//
//  main3.cpp
//  acm_exercise
//
//  Created by Hei Yanbin on 14-4-27.
//  Copyright (c) 2014年 Hei Yanbin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char (*a)[300] = new char[n][300];
    vector<char> op;
    vector<char> value;
	for(int i=0;i<n;i++)
	{
		gets(a[i]);
	}
	for(int i=0;i<n;i++)
	{
		char *p=a[i];
        if(*p<'9' && *p>'0')
        {
            cout<<atoi(p);
            continue;
        }
		while(*p)
		{
			if(*p=='a')
			{
				p++;
                if(*p!='d') return -1;
				p++;
                if(*p!='d') return -1;
                op.push_back('+');
                p++;
			}
            if(*p=='(')
            {
                op.push_back('(');
            }
            if(*p<'9' && *p>'0')
            {
                char*q =p;
                
            }
			
        }
                
    }
}