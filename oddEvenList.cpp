#include <iostream>

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

class Solution {
public:
    static void addTail(ListNode *&Head, ListNode *&Tail, ListNode *p) { 
        if(!Head && !Tail) { 
            Head = Tail = p;
        }
        else { 
            Tail->next = p;
            Tail = p;
        }
    }
    static ListNode* oddEvenList(ListNode* head) {
        ListNode *oddListHead = nullptr, *oddListTail = nullptr;
        ListNode *evenListHead = nullptr, *evenListTail = nullptr;
        ListNode *walker = head;
        int idx = 1;

        while(walker) { 
            ListNode *p = new ListNode(walker->val);

            if(idx % 2 != 0) { 
                addTail(oddListHead, oddListTail, p);
            }
            else { 
                addTail(evenListHead, evenListTail, p);
            }

            walker = walker->next;
            ++idx;
        }

        // rejoin 2 lists
        if(oddListTail) { 
            oddListTail->next = evenListHead;
        }

        return oddListHead;
    }
};

int main() {
    // ListNode *a = new ListNode(2);
    // ListNode *b = new ListNode(1);
    // ListNode *c = new ListNode(3);
    // ListNode *d = new ListNode(5);
    // ListNode *e = new ListNode(6);
    // ListNode *f = new ListNode(4);
    // ListNode *g = new ListNode(7);

    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    // ListNode *d = new ListNode(4);
    // ListNode *e = new ListNode(5);

    a->next = b;
    b->next = c;
    // c->next = d;
    // d->next = e;
    // e->next = f;
    // f->next = g;

    ListNode *newListHead = Solution::oddEvenList(a);

    ListNode *walker = newListHead;

    while(walker) { 
        cout << walker->val << " ";
        walker = walker->next;
    }

    return 0;
}