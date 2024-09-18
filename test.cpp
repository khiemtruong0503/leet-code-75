#include <iostream>
#include <queue> 
#include <vector>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void bfs(TreeNode *root, vector<int> &v) { 
    if(!root) return;

    v.push_back(root->val);
    bfs(root->left, v);
    bfs(root->right, v);
}
int main() { 
    TreeNode *a = new TreeNode(5);
    TreeNode *b = new TreeNode(3);
    TreeNode *c = new TreeNode(6);
    TreeNode *d = new TreeNode(2);
    TreeNode *e = new TreeNode(4);
    TreeNode *f = new TreeNode(7);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->right = f;

    TreeNode *found = c;
    TreeNode **p = &found;

    (*p) = NULL;

    TreeNode *walker = a;
    queue<TreeNode*> q;
    vector<int> v;
    q.push(a);

    while(!q.empty()) { 
        bfs(a, v);
        q.pop();
    }

    for(int i = 0; i < v.size(); ++i) { 
        cout << v[i] << " ";
    }
}