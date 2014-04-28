//描述
//题目很简单，给你一棵二叉树的后序和中序序列，求出它的前序序列（So easy!）。
//输入
//输入有多组数据（少于100组），以文件结尾结束。
//每组数据仅一行，包括两个字符串，中间用空格隔开，分别表示二叉树的后序和中序序列（字符串长度小于26，输入数据保证合法）。
//输出
//每组输出数据单独占一行，输出对应得先序序列。
//样例输入
//ACBFGED ABCDEFG
//CDAB CBAD
//样例输出
//DBACEGF
//BCAD
//  main2.cpp
//  acm_exercise
//
//  Created by Hei Yanbin on 14-4-27.
//  Copyright (c) 2014年 Hei Yanbin. All rights reserved.
//

#include <iostream>
//include <cstdio>
using namespace std;
struct Node
{
    char data;
    Node * left;
    Node* right;
    Node(char c) {data = c;}
};

Node* buildTree(char post[],int s1,int e1, char in[], int s2, int e2)
{
    if(!post||!in) throw invalid_argument("invald arguent.");
    if (s1>e1||s2>e2) return NULL;
    Node* root = new Node(post[e1]);
    int i=s2;
    while(in[i]!=root->data &&i<=e2)
        i++;
    int numOfleft = i-s2;
    if(i>e2) throw invalid_argument("invalid arguement.");
    root->left = buildTree(post, s1, s1+numOfleft-1, in, s2, i-1);
    root->right = buildTree(post, s1+numOfleft,e1-1, in, i+1, e2);
    return root;
}

void preOrder(Node* root)
{
    if (root==NULL) return;
    cout<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}
void main2()
{
    
    char a[100][52];
    int n =0;
    while(n<1 && gets(a[n])!=NULL)
    {
        n++;
    }
    
    for(int i=0;i<n;i++)
    {
        int len = 0;
        while(a[i][len]!=' ')
            len++;
        preOrder(buildTree(a[i], 0, len-1, a[i], len+1, len+len));
        cout<<endl;
    }
    
}


