#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//! self-coded (AC)
class Solution {
public:
    static int pairSum(ListNode* head) {
        ListNode *walker = head;
        vector<int> v;
        while(walker) { 
            v.push_back(walker->val);
            walker = walker->next;
        }

        int size = v.size();
        int Max = INT32_MIN;
        for(int i = size - 1; i >= size / 2; --i) { 
            if(v[i] + v[size - 1 - i] > Max) { 
                Max = v[i] + v[size - 1 - i];
            }
        }

        return Max;
    }
};