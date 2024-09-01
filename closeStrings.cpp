#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

//! self-coded (AC)
class Solution {
public:
    static bool closeStrings(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();

        if(size1 != size2) return false;

        unordered_map<char, int> map1, map2;
        vector<int> v; // this vector contains the appearance times of characters in word2
        // count the characters' appearance times in word1 and store in map
        for(auto i : word1) { 
            map1[i]++;
        }

        
        // count the characters' apperance times in word2
        for(auto i : word2) { 
            map2[i]++;
        }

        for(auto i : map2) { 
            v.push_back(i.second);
        }

        // check if there exists a character that appears in word2 but not in word1
        for(unordered_map<char, int>::iterator it = map2.begin(); it != map2.end(); ++it) { 
            unordered_map<char, int>::iterator found = map1.find(it->first);

            if(found == map1.end()) { 
                return false;
            }
        }

        // check if all the appearances in word2 don't match the appearances in word1
        for(unordered_map<char, int>::iterator it = map1.begin(); it != map1.end(); ++it) { 
            vector<int>::iterator found = find(v.begin(), v.end(), it->second);

            if(found == v.end()) { 
                return false;
            }
            else v.erase(found);
        }

        return true;
    }
};

int main() { 
    cout << Solution::closeStrings("abbzccca", "babzzczc");

    return 0;
}