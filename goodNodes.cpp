#include <iostream>

using namespace std;


 //Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//! self-coded (AC)
class Solution {
public:
    static void dfs(TreeNode *root, int &cnt, int Max = INT32_MIN) { 
        if(!root) { 
            return;
        }

        if(root->val >= Max) { 
            ++cnt;
            Max = root->val;
        }
        dfs(root->left, cnt, Max);
        dfs(root->right, cnt, Max);
    }
    static int goodNodes(TreeNode* root) {
        int cnt = 0;

        dfs(root, cnt);

        return cnt;
    }
};