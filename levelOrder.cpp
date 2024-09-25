#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//! self-coded (AC)
///Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void bfs(vector<TreeNode*>& level, queue<TreeNode*>& q)
    {
        if (q.size() == 0) return;
        if (!q.front()) return;
        if (q.front()->left) level.push_back(q.front()->left);
        if(q.front()->right) level.push_back(q.front()->right);
        q.pop();
        bfs(level, q);
    }


    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if (!root) return v;

        queue<TreeNode*> q;
        vector<TreeNode*> level;
        level.push_back(root);
        q.push(root);

        while (!q.empty())
        {
            vector<int> newLevel;
            for_each(level.begin(), level.end(), [&newLevel](TreeNode* x){
                newLevel.push_back(x->val);
            });
            v.push_back(newLevel);
            level.clear();
            bfs(level, q);
            
            for_each(level.begin(), level.end(), [&q](TreeNode* x){q.push(x);});
        }
        
        return v;
    }
};
