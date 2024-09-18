#include <iostream>

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
    static bool isSameTree(TreeNode* p, TreeNode* q) {
        // dfs
        if (p == nullptr && q != nullptr) return false;
        if (p != nullptr && q == nullptr) return false;
        if (p == nullptr && q == nullptr) return true;
        if (p->val != q->val) return false;

        bool checkLeft = isSameTree(p->left, q->left);
        if (!checkLeft) return false;
        return isSameTree(p->right, q->right);
    }
};

int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);

    TreeNode *d = new TreeNode(1);
    TreeNode *e = new TreeNode(2);
    TreeNode *f = new TreeNode(3);

    a->left = b;
    a->right = c;

    d->left = e;
    d->right = f;

    cout << Solution::isSameTree(a, d);
}