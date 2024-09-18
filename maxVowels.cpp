#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//! self-coded
class Solution {
public:
    static bool isVowel(char c) { 
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u') { 
            return true;
        }

        return false;
    }
    static int maxVowels(string s, int k) {
        int n = s.size();
        int countVwl = 0;
        vector<int> Counts;
        string window;
        // get first window
        for(int i = 0; i < k; ++i) { 
            if(isVowel(s[i])) { 
                countVwl++;
            }
            window += s[i];
        }
        Counts.push_back(countVwl);

        for(int i = k; i < n; ++i) { 
            if(isVowel(window[0])) { 
                countVwl--;
            }
            window.erase(window.begin());
            if(isVowel(s[i])) { 
                countVwl++;
            }
            window += s[i];

            Counts.push_back(countVwl);
        }

        return *max_element(Counts.begin(), Counts.end());
    }
};

int main() { 
    cout << Solution::maxVowels("abciiidef", 3);

    return 0;
}