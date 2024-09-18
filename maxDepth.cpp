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
    static int traverseRecursively(TreeNode *walker) { 
        if(!walker) { 
            return 0;
        }

        int depth = 1;
        int leftDepth = 0, rightDepth = 0;

        if(walker->left) { 
            leftDepth = traverseRecursively(walker->left);
        }
        if(walker->right) { 
            rightDepth = traverseRecursively(walker->right);
        }

        return leftDepth >= rightDepth ? depth + leftDepth : depth + rightDepth;
    }
    static int maxDepth(TreeNode* root) {
        TreeNode *walker = root;
        int depth = traverseRecursively(walker);

        return depth;
    }
};

