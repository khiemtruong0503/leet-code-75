#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//! self-coded (AC)
// class Solution {
// public:
//     static bool findPAndQ(TreeNode *ascendent, TreeNode *p, TreeNode *q, bool &foundP, bool &foundQ) { 
//         // this function traverses dfs style
        
//         if(!ascendent) { 
//             return false;
//         }

//         if(ascendent->val == p->val) { 
//             foundP = true;
//         }
//         else if(ascendent->val == q->val) { 
//             foundQ = true;
//         }

//         if(foundP && foundQ) { 
//             return true;
//         }

//         if(!findPAndQ(ascendent->left, p, q, foundP, foundQ)) { 
//             return findPAndQ(ascendent->right, p, q, foundP, foundQ);
//         }

//         return true;
//     }
//     static void bfs(TreeNode *root, vector<TreeNode*> &v) { 
//         if(!root) {return;}

//         v.push_back(root);
//         bfs(root->left, v);
//         bfs(root->right, v);
//     }
//     static TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
//     { 
//         if(!root) return nullptr;
//         TreeNode *ascendent = root;

//         vector<TreeNode*> v;

//         bfs(root, v);
//         int n = v.size();

//         bool foundP = false, foundQ = false;
//         for(int i = 0; i < n; ++i) { 
//             if(findPAndQ(v[i], p, q, foundP, foundQ)) { 
//                 ascendent = v[i];
//             }

//             foundP = false;
//             foundQ = false;
//         }

//         return ascendent;
//     }
// };

//! leetcode reference
class Solution { 
public:
    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
};

int main() { 
    TreeNode *a = new TreeNode(-1);
    TreeNode *b = new TreeNode(0);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(-2);
    TreeNode *e = new TreeNode(4);
    TreeNode *f = nullptr;
    TreeNode *g = nullptr;
    TreeNode *h = new TreeNode(8);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    d->left = h;

    TreeNode *ascendent = Solution::lowestCommonAncestor(a, h, e);

    cout << ascendent->val;
}