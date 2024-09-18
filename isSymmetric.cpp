#include <iostream>
#include <vector>

using namespace std;

//! self-coded (AC)
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
    static void bfs(vector<TreeNode*>& v, vector<TreeNode*>& childNodes)
    {
        if (v.size() == 0) return;

        TreeNode* curNode = v[0];
        if (curNode)
        {
            childNodes.push_back(curNode->left);
            childNodes.push_back(curNode->right);
        }
        v.erase(v.begin(), v.begin() + 1);
        bfs(v, childNodes);
    }
    static bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        vector<TreeNode*> v;
        vector<TreeNode*> childNodes;
        
        v.push_back(root);
        bfs(v, childNodes);

        while (childNodes.size() > 0)
        {
            if (childNodes.size() % 2 != 0) return false;
            bool isAllNull = true;
            for (int i = 0; i < childNodes.size(); ++i)
            {
                if (childNodes[i])
                {
                    isAllNull = false;
                    break;
                }
            }

            if (isAllNull) break;
            for (int i = 0; i < childNodes.size() / 2; ++i)
            {
                TreeNode* firstNode = childNodes[i];
                TreeNode* secNode = childNodes[childNodes.size() - 1- i];
                if (!firstNode && secNode) return false;
                else if (firstNode && !secNode) return false;
                else if (!firstNode && !secNode) continue;
                if (firstNode->val != secNode->val)
                {
                    return false;
                }
            }

            v = childNodes;
            childNodes.clear();
            bfs(v, childNodes);
        }
        return true;
    }
};

int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(2);
    TreeNode *d = nullptr;
    TreeNode *e = new TreeNode(3);
    TreeNode *f = new TreeNode(3);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;

    cout << Solution::isSymmetric(a);
}