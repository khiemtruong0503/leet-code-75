#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static string reverseWords(string s) {
        vector<string> v;

        // remove blank space at beginning and end
        while(s[0] == ' ') { 
            s.erase(s.begin());
        }
        while(s[s.size() - 1] == ' ') { 
            s.erase(s.begin() + s.size() - 1);
        }

        int size = s.size();
        size_t find = s.find_first_of(" ");
        int i = 0;
        while(find != string::npos) { 
            string word = s.substr(i, find - i);
            if(word != "") { 
                v.push_back(word);
            }
            find = s.find_first_of(" ", i = find + 1);
        }

        // add last word
        string word = s.substr(i, size - i);
        v.push_back(word);

        string ans;
        int n = v.size();
        for(int i = n - 1; i >= 0; --i) { 
            ans += v[i];
            if(i > 0) { 
                ans += ' ';
            }
        }

        return ans;
    }
};

int main() { 
    cout << Solution::reverseWords("a good   example");

    return 0;
}