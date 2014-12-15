/*首尾相连数组的最大子数组和
时间限制：1000 ms  |  内存限制：65535 KB
难度：4
描述
给定一个由N个整数元素组成的数组arr，数组中有正数也有负数，这个数组不是一般的数组，其首尾是相连的。数组中一个或多个连续元素可以组成一个子数组，其中存在这样的子数组arr[i],…arr[n-1],arr[0],…,arr[j]，现在请你这个ACM_Lover用一个最高效的方法帮忙找出所有连续子数组和的最大值（如果数组中的元素全部为负数，则最大和为0，即一个也没有选）。
输入
输入包含多个测试用例，每个测试用例共有两行，第一行是一个整数n（1=<n<=100000），表示数组的长度，第二行依次输入n个整数（整数绝对值不大于1000）。
输出
对于每个测试用例，请输出子数组和的最大值。
样例输入
6
1 -2 3 5 -1 2
5
6 -1 5 4 -7
样例输出
10
14*/
#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> &A)
{
    int total=0, maxSum=0, curMaxSum=0, minSum=0, curMinSum=0;
    for(int i=0;i<A.size();++i)
    {
        total+=A[i];
        curMaxSum = max(curMaxSum+A[i],A[i]);
        maxSum = max(maxSum,curMaxSum);
        curMinSum = min(curMinSum+A[i],A[i]);
        minSum = min(minSum, curMinSum);
    }
    cout<<max(max(maxSum,total-minSum),0)<<endl;
}
int main()
{
    for(int n;!cin.eof();)
    {
        cin>>n;
        vector<int> A(n);
        for(int i=0;i<n;++i)
            cin>>A[i];
        solve(A);
    }
}