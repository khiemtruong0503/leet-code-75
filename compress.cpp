#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static int compress(vector<char>& chars) {
        vector<char> ans;

        int size = chars.size();
        char c = chars[0];
        int Count = 1;
        for(int i = 1; i < size; ++i) {
            if(chars[i] != c) {
                ans.push_back(c); 
                if(Count != 1) { 
                    string t = to_string(Count);
                    for(int j = 0; j < t.size(); ++j) { 
                        ans.push_back(t[j]);
                            }
                }
                Count = 1;
                c = chars[i];
            }   
            else Count++;
        }

        ans.push_back(c); 
        if(Count != 1) { 
        string t = to_string(Count);
        for(int j = 0; j < t.size(); ++j) { 
            ans.push_back(t[j]);
            }
        }
        
        chars = ans;
        return ans.size();
    }
};

int main() { 
    vector<char> chars = {'a','a','b','b','b','c','c'};
    cout << Solution::compress(chars);

    return 0;
}