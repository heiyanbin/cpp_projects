#include <vector>
#include "lib.h"
using namespace std;
template <typename T>
struct TreeNode
{
    T data;
    TreeNode *left;
    TreeNode * right;
    TreeNode(T data1) {data = data1;}
};
vector<TreeNode<int>*> path;
void findPath(TreeNode<int>* root, int sum)
{
	if(root==NULL) return;
	path.push_back(root);
	sum=sum-root->data;
	if(sum==0)
		printVector(path);
	findPath(root->left, sum);
	findPath(root->right,sum);
	path.pop_back();
}