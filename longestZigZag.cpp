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
    static void zigzag(TreeNode *root, int &cnt, int previousDir) { 
        // previousDir = 0 means move to right at current node, and vise versa for previousDir = 1
        if(!root) {
            return;
        }

        ++cnt;

        if(previousDir == 0) { // => move to right node
            zigzag(root->right, cnt, 1);
        }
        else if(previousDir == 1) { 
            zigzag(root->left, cnt, 0);
        }
    }
    static void bfs(TreeNode *root, vector<TreeNode*> &v) {// traverse the list bfs style and store all nodes into vector
        if(!root) {return;}

        v.push_back(root);
        bfs(root->left, v);
        bfs(root->right, v);
    }
    static int longestZigZag(TreeNode* root) {
        int Max = INT32_MIN;
        int cnt = -1; // has to set count to -1 since we don't count the root
        vector<TreeNode*> v;

        bfs(root, v);
        int n = v.size();
        for(int i = 0; i < n; ++i) { 
            zigzag(v[i], cnt, 0);
            if(cnt > Max) { 
                Max = cnt;
            }
            cnt = -1;
            zigzag(v[i], cnt, 1);
            if(cnt > Max) { 
                Max = cnt;
            }
            cnt = -1;
        }

        return Max;
    }
};

