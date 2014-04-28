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
    vector<int> operand;
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
        bool lastPushNumber= false;
		while(*p)
		{
			if(*p=='a')
			{
				p++;
                if(*p!='d') throw invalid_argument("unknown op.");
				p++;
                if(*p!='d') throw invalid_argument("unknown op.");
                op.push_back('+');
                lastPushNumber = false;
                p++;
			}
            else if(*p=='('||*p==')')
            {
                p++;
                //op.push_back('(');
            }
            else if(*p<'9' && *p>'0')
            {
                int v =0;
                while(*p<'9'&&*p>'0')
                {
                    v=v*10+*p-'0';
                    p++;
                }
                if(!lastPushNumber)
                {
                    operand.push_back(v);
                    lastPushNumber =true;
                }
                else{
                    int tmp =  operand.back();
                    operand.pop_back();
                    char oper = op.back();
                    op.pop_back();
                    if(oper=='+')
                        operand.push_back(tmp+v);
                }
            }
			
        }
        cout<<
    }
}