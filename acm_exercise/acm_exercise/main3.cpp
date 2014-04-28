//Dr.Kong设计的机器人卡多掌握了加减法运算以后，最近又学会了一些简单的函数求值，比如，它知道函数min(20,23)的值是20 ，add(10,98) 的值是108等等。经过训练，Dr.Kong设计的机器人卡多甚至会计算一种嵌套的更复杂的表达式。
//假设表达式可以简单定义为:
//1. 一个正的十进制数 x 是一个表达式。
//2. 如果 x 和 y 是 表达式，则 函数min(x,y )也是表达式,其值为x,y 中的最小数。
//3. 如果 x 和 y 是 表达式，则 函数max(x,y )也是表达式,其值为x,y 中的最大数。
//4．如果 x 和 y 是 表达式，则 函数add(x,y )也是表达式,其值为x,y 之和。
//例如， 表达式 max(add(1,2),7) 的值为 7。
//请你编写程序，对于给定的一组表达式，帮助 Dr.Kong 算出正确答案，以便校对卡多计算的正误。
//输入
//第一行： N 表示要计算的表达式个数 （1≤ N ≤ 10） 
//接下来有N行， 每行是一个字符串，表示待求值的表达式
//（表达式中不会有多余的空格，每行不超过300个字符，表达式中出现的十进制数都不
//超过1000。）
//输出
//输出有N行，每一行对应一个表达式的值。
//样例输入
//3
//add(1,2) 
//max(1,999) 
//add(min(1,1000),add(100,99)) 
//样例输出
//3
//999
//200
//  main3.cpp
//  acm_exercise
//
//  Created by Hei Yanbin on 14-4-27.
//  Copyright (c) 2014年 Hei Yanbin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main3()
{
	int n;
	cin>>n;
	char (*a)[300] = new char[n][300];
    
    char b[100];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
    vector<int> operand;
	for(int i=0;i<n;i++)
	{
		int len= strlen(a[i]);
        int j =len-1;
        while(j>=0)
        {
            if(a[i][j]<='9' && a[i][j]>='0')
            {
                int v=0,f=1;
                while(j>=0 && a[i][j]<='9' && a[i][j]>='0')
                {
                    v=v+ f*(a[i][j]-'0');
                    f=f*10; 
                    j--;
                }
                operand.push_back(v);
            }		   
			else if(a[i][j]=='d')
			{
				j--;
                if(a[i][j]!='d') throw invalid_argument("unknown op.");
				j--;
                if(a[i][j]!='a') throw invalid_argument("unknown op.");
                int x = operand.back();
                operand.pop_back();
                int y = operand.back();
                operand.pop_back();
                operand.push_back(x+y);
                j--;
			}
            else if(a[i][j]=='x')
            {
                j--;
                if(a[i][j]!='a') throw invalid_argument("unkonw op");
                j--;
                if(a[i][j]!='m') throw invalid_argument("unknow op");
                int x = operand.back();
                operand.pop_back();
                int y = operand.back();
                operand.pop_back();
                operand.push_back(max(x,y));
                j--;
            }
            else if(a[i][j]=='n')
            {
                j--;
                if(a[i][j]!='i') throw invalid_argument("unkonw op");
                j--;
                if(a[i][j]!='m') throw invalid_argument("unknow op");
                int x = operand.back();
                operand.pop_back();
                int y = operand.back();
                operand.pop_back();
                operand.push_back(min(x,y));
                j--;
            }
            else// if(a[i][j]=='('||a[i][j]==')'||a[i][j]==',')
            {
                j--;
            }          	
        }
        cout<<operand.back()<<endl;
        operand.pop_back();
    }
    delete[] a;
}