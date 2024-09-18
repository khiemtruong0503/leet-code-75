#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//! self-coded (AC)
// class RecentCounter {
// public:
//     vector<int> v; // stores pinged singals' time    
// public:
//     RecentCounter() {
        
//     }
    
//     int ping(int t) {
//         int cnt = 1;

//         int size = v.size();
//         for(int i = 0; i < size; ++i) { 
//             if(v[i] >= t - 3000 && v[i] <= t) { 
//                 ++cnt;
//             }
//         }

//         v.push_back(t);

//         return cnt;
//     }
// };

//! leetcode reference
class RecentCounter {
public:
queue<int>q;
    RecentCounter() {   
    }
    int ping(int t) {
       q.push(t);
       while(q.front()<t-3000){
           q.pop();
       }
       return q.size(); 
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() { 
    RecentCounter *rc = new RecentCounter();

    cout << rc->ping(1) << endl;
    cout << rc->ping(100) << endl;
    cout << rc->ping(3001) << endl;
    cout << rc->ping(3002) << endl;
    cout << rc->ping(10000) << endl;
    
}
