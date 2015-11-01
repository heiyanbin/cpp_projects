//#include <iostream>
#include "lib.h"
#include <map>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <set>
#include <unordered_map>
#include <stack>
#include <string>
#include <cctype>
#include <list>
  
int main(int argc, const char * argv[])
{
    //testFindK();
    //testFast_sort();
    //testRelocateOddAndEven();
    //testFindSumInSortedArray();
    //testFindTopKIn2SortedArray();
    //testBinarySearchInShiftedSortedArray();
    //testFindMidIn2SortedArray();
    //testFindMaxSubArraySum();
    //testPerm();
    //testCombine();
    //testRotateMatrix();
    //testEvalSubfix();
    //testMidfixToSubfix();
    //testEvalMidfix();
    //testNormalizePath();
    //testLCS();
    //testLRS();
    //testMaxHuiwen();
    //testMyAtoi();
    //testMyItoa();
    //testHeapSort();
    //testSort();
    //testMSQuestions_6();
    //testMyStrstr();
    //testMyStrcmp();
    //testReverseNum();
    //testPrimeFactor();
    //testIsHuiwenNum();
    //testGcd();
    //testLcm();
    //testSequentialSum();
    //testMin_number_of_coin();
    //testLIS();
    //test_max_value_in_bag();
    //testCombine_of_coin();
    //test_combine_backtrack();
    // test_subset();
    //test_combine_of_parentheses();
    test();
}


  /**
 * Definition for binary tree
 */ struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
      TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
  };

struct ListNode {
   int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
 



struct Interval {
        int start;
         int end;
         Interval() : start(0), end(0) {}
         Interval(int s, int e) : start(s), end(e) {}
     };
/**
 * Definition for binary tree with next pointer.*/
  struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
 
class Solution {
public:
     void popOrder(int A[],int n)
    {
        vector<int> stk(n), x(n);
        popOrder(A, n,stk,x, 0,0,0);
    }
    void popOrder(int A[],int n, vector<int> &stk, vector<int> &x, int index, int stackIndex, int popIndex)
    {
        if(popIndex>=n)
        {
            printVector(x);
        }
        else
        {
            if(index<n)
            {
                stk[stackIndex]=A[index];
                popOrder(A, n, stk, x, index+1,stackIndex+1,popIndex);
            }
            if(stackIndex>0)
            {
                x[popIndex] =stk[stackIndex-1];
                popOrder(A, n, stk, x, index,stackIndex-1,popIndex+1);
                stk[stackIndex-1]=x[popIndex];
            }
        }
    }
    
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int i=0,j=nums.size()-1,k=-1;
        while(i<j)
        {
            int mid=(i+j)/2;
            if(nums[mid]>=nums[i])
            {
                if(nums[mid]<= nums[j])
                {
                    k=mid;
                    break;
                }
                else
                    i=mid+1;
            }
            else
                j=mid;
        }
        if(k>=0) return;
        reverse(nums.begin(),nums.begin()+i);
        reverse(nums.begin()+i,nums.end());
        reverse(nums.begin(),nums.end());
    }
    int maxKSubArrays(vector<int> nums, int k) {
        // write your code here
        int n= nums.size();
        vector<vector<int>> d(k+1,vector<int>(n+1));
        int maxSum = INT_MIN;
        for(int i=1;i<=k;++i)
        {
            for(int j=i;j<=n;++j)
            {
                d[i-1][j-1] = j-2 >0 && j>i ? max(d[i-1][j-1],d[i-1][j-2]) : d[i-1][j-1];
                d[i][j] = j==i ? d[i-1][j-1]+nums[j-1] : max(d[i-1][j-1]+nums[j-1], d[i][j-1]+nums[j-1]);
                if(i==k)
                    maxSum = max(d[i][j],maxSum);
            }
        }
        return maxSum;
    }
    int read4(char* buf)
    {
        int i=0;
        for(;p<data.size()&&i<4;p++,buf++,i++)
            *buf=data[p];
        return i;
    }
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        if(A.size()<2) return 0;
        vector<int> d(101),e(101);
        int minCost =INT_MAX;
        for(int i=0;i<A.size();++i)
        {
            for(int j=0;j<=100;++j)
            {
                e[j]=INT_MAX;
                for(int k=max(j-target,0);k<=min(j+target,100);++k)
                    e[j]= min(e[j],d[k]+abs(A[i]-j));
                if(i==A.size()-1)
                    minCost = min(minCost, e[j]);
            }
            
            d=e;
        }
        return minCost;
    }
    int median(vector<int> nums) {
        // write your code here
        int n=nums.size();
        return median(nums,0,n-1,(n&1)? n/2+1 :n/2);
        
    }
    int median(vector<int> &nums, int L, int R, int k)
    {
        if(L==R) return nums[L];
        int i=L;
        for(int j=L+1;j<=R;++j)
            if(nums[j]<nums[L])
                swap(nums[++i],nums[j]);
        swap(nums[L],nums[i]);
        if(i-L+1==k) return nums[i];
        else if(i-L+1>k) return median(nums,L,i-1,k);
        else return median(nums,i+1,R,k-(i-L+1));
    }
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int capacity = hashTable.size()*2;
        vector<ListNode*> table(capacity);
        for(auto slot: hashTable)
            if(slot)
            {
                for(auto p=slot;p;)
                {
                    ListNode *next = p->next;
                    int index=p->val%capacity;
                    if(table[index]==NULL) table[index]=p;
                    else{
                        ListNode *cur;
                        for(cur=table[index];cur->next;cur=cur->next);
                        cur->next = p;
                        cur=p;
                    }
                    p->next=NULL;
                    p=next;
                }
            }
        return table;
    }
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int n = 0;
        for(int e : A)
            n ^= e;
        int j=0;
        for(;j<32;++j)
            if((n>>j)&1) break;
        int a = 0, b = 0;
        for(int e : A)
            if((e>>j)&1)
                a ^= e;
            else
                b ^= e;
        return vector<int> {a,b};
    }
    int compareVersion(string version1, string version2) {
        for(size_t i=0,l=0;;){
            size_t j=version1.find('.', i), m=version2.find('.',l);
            int a = i<string::npos? stoi(version1.substr(i,j)):0, b= l<string::npos?stoi(version2.substr(l,m)):0;
            if(a>b) return 1;
            else if(a<b) return -1;
            else{
                if(j==string::npos && m==string::npos) return 0;
                i= j==string::npos? j:j+1;
                l= m==string::npos? m:m+1;
            }
        }
    }
    int bw(vector<int> a, int x){
        int l = 0, r=a.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(x<=m)
                r=m;
            else
                l=m+1;
        }
        return l;
    }
    int lower_bound(vector<int> A, int target)
    {
        int i=0,j=A.size()-1;
        while(i<=j)
        {
            int mid= i+(j-i)/2;
            if(target>A[mid])
                i=mid+1;
            else
                j=mid;
        }
        return i;
    }
private:
    int len;
    int start;
    char  aux_buf[4];
    string data;
    int p;
};

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it==m.end()) return -1;
        int ret = it->second->second;
        l.splice(l.end(), l, it->second);
        it->second=prev(l.end());
        return ret;
    }
    
    void set(int key, int value) {
        auto it = m.find(key);
        if(it!=m.end()){
            it->second->second = value;
            l.splice(l.end(), l, it->second);
        }else{
            if(l.size()==capacity){
                m.erase(l.front().first);
                l.pop_front();
            }
            l.push_back(make_pair(key, value));
        }
        m[key]=prev(l.end());
    }
private:
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    int capacity;
};

class Solution3 {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1), *prevM = &dummy;
        dummy.next = head;
        for (int i = 0; i < m - 1 && prevM; ++i, prevM = prevM->next) ;
        if (!prevM || !prevM->next || !prevM->next->next) return head;
        auto &head2 = prevM->next, mNode = prevM->next;
        auto &next = mNode->next, cur = mNode->next;
        for (int i = m + 1; i <= n && cur; ++i) {
            next = cur->next;
            cur->next = head2;
            head2 = cur;
            cur = next;
        }
        return dummy.next;
    }
    
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        for (int i = 0; i < 32; n = n >> 1)
            m = (m << 1) | (n & 1);
        return m;
    }
};
class Solution11 {
public:
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count ++;
                }
            }
        
        return count;
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i == grid.size() || i < 0 || j == grid[i].size() || j < 0) return;
        if (grid[i][j] != '1') return;
        grid[i][j] = '2';
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
    }
};
vector<int> subarraySumClosest(vector<int> nums){
    // write your code here
    if (nums.empty()) return vector<int>();
    
    vector<pair<int,int>> prefixSum;
    prefixSum.push_back(make_pair(0, -1));
    for (int i = 0;i < nums.size(); ++i)
        prefixSum.push_back(make_pair(nums[i] + prefixSum.back().first, i));
    
    sort(prefixSum.begin(), prefixSum.end());
    
    int minDiff = INT_MAX, start = -1, end = -1;
    for (int i = 1; i < prefixSum.size(); i++) {
        if (abs(prefixSum[i].first - prefixSum[i-1].first)  < minDiff) {
            minDiff = abs(prefixSum[i].first - prefixSum[i-1].first);
            start = min(prefixSum[i].second, prefixSum[i-1].second) + 1;
            end = max(prefixSum[i].second, prefixSum[i-1].second);
        }
    }
    
    return vector<int> {start, end};
}
struct Point {
         int x;
         int y;
         Point() : x(0), y(0) {}
         Point(int a, int b) : x(a), y(b) {}
     };
class Solution100 {
public:
    int f(vector<vector<int>>& A) {
        
        map<vector<vector<int>>, bool> marked;
        map<vector<vector<int>>, int> dist;
        map<vector<vector<int>>, vector<vector<int>>> pre;
        queue<pair<vector<vector<int>>, pair<int,int>>> q;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (A[i][j] == 0) {
                    q.push(make_pair(A, make_pair(i, j)));
                    break;
                }
            }
        }
        marked[A] = true;
        dist[A] = 0;
        pre[A] = A;
        pair<int, int> dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        const vector<vector<int>> T = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
        while (!q.empty()) {
            auto x = q.front(); q.pop();
            auto B = x.first;
            int i = x.second.first, j = x.second.second;
            for (auto &d : dirs) {
                int ni = i + d.first, nj = j + d.second;
                if(ni < 0 || ni >= 3 || nj < 0  || nj >= 3) continue;
                swap(B[ni][nj], B[i][j]);
                if (marked[B] == false) {
                    marked[B] = true;
                    dist[B] = dist[x.first] + 1;
                    pre[B] = x.first;
                    if (B == T) {
                        
                    }
                    q.push(make_pair(B, make_pair(ni, nj)));
                }
                swap(B[ni][nj], B[i][j]);
            }
        }
        return -1;
    }
    int atoi(const char *str) {
        if(!str) return 0;
        while(*str && *str==' ')str++;
        bool negative = false;
        if(*str=='-'){
            negative = true;
            str++;
        }
        else if(*str=='+')
            str++;
        int value = 0, maxdiv10 = INT_MAX/10,last_digit_max=INT_MAX%10;
        while(*str && isdigit(*str)) {
            if(value>maxdiv10 || value==maxdiv10 && *str-'0'>last_digit_max)
                return negative ? INT_MIN : INT_MAX;
            value = value * 10 + *str -'0';
            str++;
        }
        return negative ? -value : value;
    }
};



void test()
{
    string a = string("a") + 'b';
    vector<int> v = {0, 1, 2};
    auto str = to_string(INT_MIN).c_str();
    list<int> l;
    l.push_back(1);
    auto it = l.begin();
    it++;
    auto x = Solution100().atoi(str);
    
    
}



class Singleton
{
public:
    static Singleton & getInstance()
    {
        static Singleton instance;
        return instance;
    }
    
    
    
private:
    int i;
    Singleton()
    {
        i=1;
        cout<<"constructor"<<endl;
    }
    Singleton & operator=(Singleton &a)
    {
        cout<<"Assginment"<<endl;
        i=a.i;
        return *this;
    }
    Singleton(Singleton &a)
    {
        i=a.i;
        cout<<"copy constructor"<<endl;
    }
};














