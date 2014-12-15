//#include <iostream>
#include "lib.h"
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <stack>

#define repeat while(true)

  
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

/**
 * Definition for undirected graph.
 */ struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
  };
struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
class Solution {
public:
    
    bool dfs(vector<int> &S, int start, int sum)
    {
        for(int i=start;i<S.size();i++)
        {
            sum-=S[i];
            if(sum==0)
                return true;
            if(dfs(S,i+1,sum))
                return true;
            sum+=S[i];
        }
        return false;
    }
    vector<vector<int>> output;
};
class Solution2 {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<int> x(num.size());
        permute(0, x,num);
        return output;
    }
    
    void permute(int t, vector<int> &x, vector<int> &num)
    {
        if(t>=num.size())
        {
            output.push_back(num);
        }
        else
        {
            for(int i=t;i<num.size();i++)
            {
                x[t]=num[i];
                num.erase(num.begin()+i);
                num.insert(num.begin()+t,x[t]);
                permute(t+1, x, num);
                num.erase(num.begin()+t);
                num.insert(num.begin()+i,x[t]);
            }
        }
    }
    
    vector<vector<int>> output;
    
};
void solve()
{
    int n, maxLen=0, x;
    cin>>n;
    vector<int> len;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        auto pos = lower_bound(len.begin(),len.end(),x);
        if(pos==len.end()) 
            len.push_back(x);
        else
            *pos=x;
    }
    cout<<len.size()<<endl;
}


class Solution4 {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lower = lower_bound(A,n,target);
        int upper = upper_bound(A,n,target);
        vector<int> output(2,-1);
        if(lower==n||A[lower]!=target) return output;
        output[0]=lower;
        output[1]=upper;
        return output;
    }
    int lower_bound(int A[], int n, int target)
    {
        int i=0,j=n-1;
        while(i<=j)
        {
            int mid= i+(j-i)/2;
            if(A[mid]<target) 
                i=mid+1;
            else 
                j=mid-1;
        }
        return i;
    }
    int upper_bound(int A[], int n, int target)
    {
        int i=0,j=n-1;
        while(i<=j)
        {
            int mid= i+(j-i)/2;
            if(A[mid]<=target) 
                i=mid+1;
            else 
                j=mid-1;
        }
        return j;
    }
};
bool greater(int a, int b)
{
    return a>b;
}
void topk(int A[],int n, int k)
{
    assert(A && n>0 && k>0);
    make_heap(A,A+k,greater);
    for(int i=k;i<n;i++)
    {
        if(A[i]>A[0])
        {
            pop_heap(A,A+k,greater);
            swap(A[i],A[k-1]);
            push_heap(A,A+k,greater);
        }
    }
}
static void topK(int A[], int n, int k)
{
	if(!A || k<1 || k>= n) return;
	for(int i=1;i<k;i++)
	{
		int j=i;
		while((j-1)/2>=0 && A[(j-1)/2]>A[j])
		{
			swap(A[(j-1)/2], A[j]);
			j=(j-1)/2;
		}
	}
	for(int i=k;i<n;i++)
	{
		if(A[i]>A[0])
        {
            swap(A[i],A[0]);
            int p=0, j=2*p+1;
			while(j<k)
			{
				if(j+1<k && A[j+1]<A[j])
					++j;
				if(A[p]>A[j])
					swap(A[p],A[j]);
				p=j;
				j=2*p+1;
			}
        }
	}
}
TreeNode* buildTreeFromSequence(vector<string> &s)
{
    if(s.empty()||s[0]=="#") return NULL;
    TreeNode* root = new TreeNode(stoi(s[0]));
    queue<TreeNode*> q;
    q.push(root);
    for(int i=1;i<s.size();)
    {
        auto node = q.front();q.pop();
        int j=0;
        for(auto p = &node->left;j<2 && i<s.size();p=&node->right,j++,i++)
        {
            if(s[i]!="#")
            {
                *p = new TreeNode(stoi(s[i]));
                q.push(*p);
            }
        }
    }
    return root;
}
vector<string> serializeTree(TreeNode* root)
{
    vector<string> res;
    if(root==NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        auto root = q.front();q.pop();
        if(root)
        {
            res.push_back(to_string(root->val));
            q.push(root->left);
            q.push(root->right);
        }
        else
            res.push_back("#");
    }
    while(res.back()=="#")
        res.pop_back();
    return res;
}
class Solution7 {
public:
     int maxKSubArrays(vector<int> nums, int k) {
        // write your code here
         vector<vector<int>> d(k+1,vector<int>(nums.size()+1,0));
        int maxSum= -INT_MIN;
        for(int i=1;i<=k;++i)
        {
            for(int j=i;j<=nums.size();j++)
            {
                d[i][j]= max(d[i][j-1]+nums[j-1], d[i-1][j] + nums[j-1]);
                maxSum= max( maxSum,d[i][j]);
                d[i][j]=maxSum;
            }
        }
        return maxSum;
    }

};

class Solution10 {
private:
    //vector<vector<int> >output;
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        return DFS(s,dict);
    }
   vector<string> DFS(string s, unordered_set<string> &dict)
    {
        if(s.empty()) return vector<string>(1,"");
        else
        {
            vector<string> ret = cache[s];
            if(!ret.empty()) return ret;
            for(int i=1;i<=s.length();++i)
            {
                auto sub = s.substr(0,i);
                if(dict.find(sub)!=dict.end())
                {
                    for(auto t : DFS(s.substr(i,s.length()-i),dict))
                    {
                        if(!t.empty())
                        {
                            sub.append(" ");
                            sub.append(t);
                        }
                        ret.push_back(sub);
                    }
                }
            }
            return cache[s]=ret;
        }
    }
    map<string,vector<string>> cache;
    int pow( int a, int b ) 
    {
        int r = 1, base = a;
        while( b != 0 ) 
        {
            if( b % 2 )
                r *= base;
            base *= base;
            b /= 2;
        }
        return r;
    }
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        int maxArea = 0;
        height.push_back(0);
        for(int i=0;i<height.size();)
        {
            if(s.empty()||height[i]>=height[s.top()])
                s.push(i++);
            else {
                int h = height[s.top()]; s.pop();
                int left = s.empty() ? -1 : s.top();
                maxArea = max(maxArea,h*(i-left-1));
            }
        }
        return maxArea;
    }
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        vector<int> res;
        if(nums.empty()) return res;
        int minDiff = INT_MAX;
        pair<int,int> minInterval;
        vector<pair<int,int>> prefixSum;
        prefixSum.push_back(make_pair(0,-1));
        for(int i=0;i<nums.size();++i)
            prefixSum.push_back(make_pair(nums[i]+prefixSum.back().first,i));
        sort(prefixSum.begin(),prefixSum.end());
        for(int i=1;i<prefixSum.size();i++){
            if(abs(prefixSum[i].first-prefixSum[i-1].first)<minDiff){
                minDiff = abs(prefixSum[i].first-prefixSum[i-1].first);
                minInterval = make_pair(min(prefixSum[i].second, prefixSum[i-1].second)+1,max(prefixSum[i].second, prefixSum[i-1].second));
            }
        }
        res.push_back(minInterval.first);
        res.push_back(minInterval.second);
        return res;
    }
    int fastPower(int a, int b, int n) {
        // write your code here
        if(b==0 && n==1) return 0;
        int res = 1;
        while(b>0) {
            if(b&1) 
                res = (res * a) % n;
            a=(a*a) % n;
            b>>=1;
        }
        return res;
    }
    TreeNode* maxTree(vector<int> A) {
        stack<TreeNode*> s;
        TreeNode* cur=NULL;
        A.push_back(INT_MAX);
        for(int i=0;i<A.size();) {
            if(cur==NULL) cur= new TreeNode(A[i]);
            if(s.empty()||cur->val<s.top()->val){
                s.push(cur);
                cur=NULL;
                i++;
            }
            else {
                auto node = s.top(); s.pop();
                if(!s.empty() && s.top()->val <cur->val)
                    s.top()->right = node;
                else {
                    cur->left = node;
                }
            }
        }
        return s.top()->left;
    }
};
void test()
{
    int a[]={6,4,8,2,3,1};
    vector<int> v(a,a+6);
    
    auto x = Solution10().maxTree(v);
    auto y = serializeTree(x);
}

class Solution5 {
public:
    class cmp { public: bool operator()(ListNode* a, ListNode* b){return a->val > b->val;}};
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*,vector<ListNode*>, cmp> q;
        for_each(lists.begin(),lists.end(),[&q](ListNode* head){if(head) q.push(head);});
        return merge(q);
    }
    ListNode *merge(priority_queue<ListNode*,vector<ListNode*>, cmp> &lists)
    {
        if(lists.empty()) return NULL;
        auto head = lists.top();
        lists.pop();
        if(head->next)
            lists.push(head->next);
        head->next=merge(lists);
        return head;
    }
};

struct Sal
{
	int salary;
	int index;
	Sal(int sal, int i):salary(sal),index(i){}
	bool operator <( const Sal& another)
	{
		return this->salary < another.salary;
	}	
};
vector<int> budgetcut(vector<int> &salary, int cut, int wage)
{
	vector<Sal> sals;
	for(int i=0;i<salary.size();++i) sals.push_back(Sal(salary[i],i));
	sort(sals.begin(),sals.end());
	vector<int> ret(salary.size());	
	for(int pos=0;pos<sals.size();)
	{
		int avg_cut = cut/(sals.size()-pos);
        if(sals[pos].salary-avg_cut>=wage) 
		{
			for_each(sals.begin()+pos, sals.end(),[&](Sal &sal)->void{ret[sal.index]=avg_cut;});
			return ret;
		}
		else
		{
			ret[sals[pos].index]=sals[pos].salary-wage;
            cut-= sals[pos].salary-wage;
			pos++;
		}
	}
	return ret;
}
