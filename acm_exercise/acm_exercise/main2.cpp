//
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


