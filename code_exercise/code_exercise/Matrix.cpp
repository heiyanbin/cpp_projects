//
//  Matrix.cpp
//  code_exercise
//
//  Created by Hei Yanbin on 14-4-23.
//  Copyright (c) 2014年 Hei Yanbin. All rights reserved.
//
#include "lib.h"
void rotate(int a[][4], int n)
{
    if(!a||n<2)
        return;
    
    int layer =0;
    while(layer<n/2)
    {
        int k=layer;
        while(k<n-layer-1)
        {
            int temp = a[layer][k];
            a[layer][k] = a[k][n-layer-1];
            a[k][n-layer-1] = a[n-layer-1][n-k-1];
            a[n-layer-1][n-k-1] = a[n-k-1][layer];
            a[n-k-1][layer]=temp;
            k++;
        }
        layer++;
    }
}

void testRotateMatrix()
{
    int a[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    for(int i=3;i>=0;i--)
    {
        for (int j=0; j<4; j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    rotate(a, 4);
    cout<<"------"<<endl;
    for(int i=3;i>=0;i--)
    {
        for (int j=0; j<4; j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    
}
