#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//! self-coded  (AC)
// Definition for a binary tree node.
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
    void bfs(vector<TreeNode*>& newLevel, queue<TreeNode*>& q, int& isLeft)
    {
        if (q.size() == 0) return;
        if (!q.front()) return;

        if (isLeft % 2 == 0)
        {
            if (q.front()->left) newLevel.push_back(q.front()->left);
            if (q.front()->right) newLevel.push_back(q.front()->right);
        }
        else 
        {
            if (q.front()->right) newLevel.push_back(q.front()->right);
            if (q.front()->left) newLevel.push_back(q.front()->left);
        }

        q.pop();
        bfs (newLevel, q, isLeft);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;

        if (!root) return v;
        vector<TreeNode*> newLevel = {root};
        queue<TreeNode*> q;

        q.push(root);
        int isLeft = 0;
        while(!q.empty())
        {
            vector<int> tmp;
            for_each (newLevel.begin(), newLevel.end(), [&tmp](TreeNode* x){
                tmp.push_back(x->val);
            });          

            v.push_back(tmp);
            
            newLevel.clear();
            isLeft++;
            bfs(newLevel, q, isLeft);

            for_each (newLevel.rbegin(), newLevel.rend(), [&q](TreeNode* x){
                q.push(x);
            });
            
            
        }

        return v;
    }
};