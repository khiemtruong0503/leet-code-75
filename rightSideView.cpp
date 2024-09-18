#include <iostream>
#include <vector>
#include <math.h>
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
//! first try (no AC)
// class Solution {
// public:
//     static void reverseBFS(TreeNode *root, vector<TreeNode*> &v) { 
//         if(!root) { 
//             v.push_back(nullptr);
//             return;
//         }
//         v.push_back(root);
//         reverseBFS(root->left, v);
//         reverseBFS(root->right, v);
//     }
//     static vector<int> rightSideView(TreeNode* root) {
//         vector<TreeNode*> v;
//         vector<int> ans;

//         reverseBFS(root, v);
//         int n = v.size();
//         int idx = 0;
//         for(int i = 0; i <= log2(n); ++i) {
//             int size = pow(2, i);
//             for(int j = i - 1 + idx; j >= idx; --j) { 
//                 if(v[j] != nullptr) { 
//                     ans.push_back(v[j]->val);
//                     break;
//                 }
//             }
//             idx = size - 1;
//         }

//         return ans;
//     }
// };

//! self-coded (AC beats 100% users)
class Solution {
public:
    static void getChildrenRoots(TreeNode *root, queue<TreeNode*> &q) { 
        if(!root) {return;}

        if(root->right) { 
            q.push(root->right);
        }
        if(root->left) { 
            q.push(root->left);
        }
    }
    static vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(!root) {return ans;}
        getChildrenRoots(root, q);

        ans.push_back(root->val);

        while(!q.empty()) { 
            ans.push_back(q.front()->val);
            int qSize = q.size();
            while(qSize--) { 
                getChildrenRoots(q.front(), q);
                q.pop();
            }
        }

        return ans;
    }
};
int main() { 
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);

    a->left = b;
    a->right = c;

    b->left = d;

    vector<int> ans = Solution::rightSideView(a);
    int n = ans.size();

    cout << '[';
    for(int i = 0; i < n; ++i) { 
        cout << ans[i];
        if(i < n - 1) { 
            cout << ',';
        }
    }
    cout << ']';
}

