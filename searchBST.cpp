#include <iostream>

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

//! self-coded (AC) 1 line
class Solution {
public:
    static TreeNode* searchBST(TreeNode* root, int val) {
        return !root ? nullptr: root->val == val ? root : (root->val > val ? searchBST(root->left, val) : searchBST(root->right, val));
    }
};

