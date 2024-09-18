#include <iostream>
#include <vector>

using namespace std;


// Definition for a binary tree node.
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
    static void dfs(TreeNode *root, int targetSum, int &cnt, long long Sum = 0) { 
        if(!root) {
            return;
        }

        Sum += root->val;
        if(Sum == targetSum) { 
            ++cnt;
        }

        dfs(root->left, targetSum, cnt, Sum);
        dfs(root->right, targetSum, cnt, Sum);
    }
    static void bfs(TreeNode *root, vector<TreeNode*> &v) { // get all the nodes in bfs traverse style and store in a vector
        if(!root) {return;}

        v.push_back(root); 
        bfs(root->left, v);
        bfs(root->right, v);
    }
    static int pathSum(TreeNode* root, int targetSum) {
        vector<TreeNode*> v;

        bfs(root, v);
        int n = v.size();
        int cnt = 0;
        for(int i = 0; i < n; ++i) { 
            dfs(v[i], targetSum, cnt);
        }

        return cnt;
    }
};

