//#include <iostream>
#include "lib.h"
#include <map>


  
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
 
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if(!root) return 0;
        int globalMaxSum = root->val;
        int x = maxPathSumFromRoot(root, globalMaxSum);
        return globalMaxSum;
    }
    
    int maxPathSumFromRoot(TreeNode * root, int &globalMaxSum)
    {
        if(root==NULL) return 0;
        
        int maxSum = root->val;
        int leftSum = maxPathSumFromRoot(root->left,globalMaxSum)+root->val;
        if(leftSum>maxSum)
            maxSum = leftSum;
        int rightSum = maxPathSumFromRoot(root->right,globalMaxSum)+root->val;
        if( rightSum>maxSum)
            maxSum = rightSum;
        int allSum = leftSum - root->val + rightSum;
        if(allSum > globalMaxSum)
            globalMaxSum= allSum;
        if(maxSum>globalMaxSum)
            globalMaxSum = maxSum;
        return maxSum;
    }

};
void test()
{
   
    TreeNode *root = new TreeNode(5,new TreeNode(4,new TreeNode(11,new TreeNode(7,NULL,new TreeNode(1)),new TreeNode(2)),NULL),new TreeNode(8,new TreeNode(13),new TreeNode(4)));
    
    Solution s;
    int x = s.maxPathSum(root);
}

