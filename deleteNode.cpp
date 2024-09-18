#include <iostream>
#include <vector>
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
// class Solution {
// public:
    
//     static TreeNode* deleteNode(TreeNode *root, int key) { 
//         if(root) {
//             // find key node

//         }

//         return root;
//     }
// };

class Solution {
public:
    static TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            if(key < root->val) root->left = deleteNode(root->left, key);     //We frecursively call the function until we find the target node
            else if(key > root->val) root->right = deleteNode(root->right, key);       
            else{
                if(!root->left && !root->right) return NULL;          //No child condition
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;    //One child contion -> replace the node with it's child
					                                                //Two child condition   
                TreeNode* temp = root->left;                        //(or) TreeNode *temp = root->right;
                while(temp->right != NULL) temp = temp->right;     //      while(temp->left != NULL) temp = temp->left;
                root->val = temp->val;                            //       root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);  //        root->right = deleteNode(root->right, temp);		
            }
        return root;
    }   
};



int main() { 
    // TreeNode *a = new TreeNode(4);
    // TreeNode *b = nullptr;
    // TreeNode *c = new TreeNode(7);
    // TreeNode *d = new TreeNode(6);
    // TreeNode *e = new TreeNode(8);
    // TreeNode *f = new TreeNode(5);
    // TreeNode *g = nullptr;
    // TreeNode *h = nullptr;
    // TreeNode *i = new TreeNode(9);

    // a->left = b;
    // a->right = c;

    // c->left = d;
    // c->right = e;

    // d->left = f;
    // d->right = g;

    // e->left = h;
    // e->right = i;

    TreeNode *a = new TreeNode(2);
    TreeNode *b = new TreeNode(1);
    
    a->left = b;

    TreeNode *root = Solution::deleteNode(a, 1);
    
    if(!root) return 0;
    queue<TreeNode*> q;
    vector<int> v;

    q.push(root);
    v.push_back(root->val);

    // while(!q.empty()) { 
    //     Solution::bfs(q.front(), q, v);

    //     q.pop();
    // }

    for(int i = 0; i < v.size(); ++i) { 
        cout << v[i] << " ";
    }    

    return 0;
}