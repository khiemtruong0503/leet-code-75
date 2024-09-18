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
    static void getLeaves(TreeNode *root, vector<int> &leaf) { 
        if(root) { 
            if(!root->left && !root->right) { 
                leaf.push_back(root->val);
                return;
            }
        }
        if(root->left) { 
            getLeaves(root->left, leaf);
        }
        if(root->right) { 
            getLeaves(root->right, leaf);
        }
    }
    static bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;

        getLeaves(root1, leaf1);
        getLeaves(root2, leaf2);

        return leaf1 == leaf2;
    }
};