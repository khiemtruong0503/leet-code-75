#include <iostream>
#include <vector>

using namespace std;

//! self-coded
class Solution {
public:
    static bool isSubsequence(string s, string t) {
        int size = t.size();
        int n = s.size();

        if(n == 0) return true;
        for(int i = 0; i < size; ++i) { 
            if(t[i] == s[0]) {
                s.erase(s.begin());
                if(s.empty()) return true;
            }
        }

        return false;
    }
};
