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
class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)==1)
        {
            freq[key]++;
            return mp[key];
        }
        return -1;
    }
    
    void set(int key, int value) {
        if(mp.size()<capacity)
            mp[key]=value;
        else
        {
            int least = INT_MAX;
            int delKey=0;
            for(map<int,int>::iterator it=freq.begin();it!=freq.end();it++)
            {
                if(it->first<least)
                {
                    least=it->second;
                    delKey = it->second;
                }
            }
            mp.erase(delKey);
        }
    }
private:
    map<int,int> mp;
    map<int,int> freq;
    int capacity;
};
void test()
{
    
}

