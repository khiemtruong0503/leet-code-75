#include <iostream>
#include <string>
#include <stack>

using namespace std;

//! self-coded (AC)
// class Solution {
// public:
//     string removeStars(string s) {
//         string ans;
//         stack<char> stck;
//         int n = s.size();
        
//         for(int i = 0; i < n; ++i) { 
//             if(s[i] != '*') { 
//                 stck.push(s[i]);
//             }
//             else { 
//                 stck.pop();
//             }
//         }

//         while(!stck.empty()) { 
//             ans.insert(ans.begin(), stck.top());

//             stck.pop();
//         }

//         return ans;
//     }
// };

//! self-coded without using stack (AC)
class Solution {
public:
    static string removeStars(string s) {
        string ans;
        int n = s.size();

        for(int i = 0; i < n; ++i) { 
            if(s[i] != '*') { 
                ans += s[i];
            }
            else { 
                ans.pop_back();
            }
        }

        return ans;
    }
};


