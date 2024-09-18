#include <iostream>
#include <queue>

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
    static void bfs(TreeNode *root, queue<TreeNode*> &q, int &Sum) { 
        if(!root) {return;}

        if(root->left) { 
            q.push(root->left);
            Sum += root->left->val;
        }
        if(root->right) { 
            q.push(root->right);
            Sum += root->right->val;
        }
    }
    static int maxLevelSum(TreeNode* root) {
        int Max = root->val, maxLevel = 1;
        int Sum = 0, level = 1;
        queue<TreeNode*> q;
        
        bfs(root, q, Sum);
        ++level;

        if(Sum > Max) { 
            Max = Sum;
            maxLevel = level;
        }

        while(!q.empty()) { 
            ++level;    
            Sum = 0;
            int size = q.size();
            while(size--) { 
                bfs(q.front(), q, Sum);
                q.pop();
            }
            
            if(q.empty()) { // in case we reached the last level
                break;
            }

            if(Sum > Max) { 
                Max = Sum;
                maxLevel = level;
            }
        }

        return maxLevel;
    }
};