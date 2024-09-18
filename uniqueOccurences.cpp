#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set> 

using namespace std;

//! self-coded (AC)
class Solution {
public:
    static bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        // get number of appearance of arr[0]
        int a = arr[0];
        int cnt = 1;
        int n = arr.size();
        vector<int> v; // this vector stores number of appearances

        for(int i = 0; i < n; ++i) { 
            int Count = 1;
            for(int j = i + 1; j < n; ++j) { 
                if(arr[j] == arr[i]) {
                    ++Count;

                    if(j == n - 1) {
                        i = j;
                    }
                }
                
                else { 
                    i = j - 1;
                    break;
                }
            }
            vector<int>::iterator found = find(v.begin(), v.end(), Count);

            if(found != v.end()) { 
                return false;
            }
            v.push_back(Count);
        }

        return true;
    }
};

//! leetcode reference: hash map (AC)
// class Solution { 
//     public:
//     static bool uniqueOccurrences(vector<int> &arr) { 
//         unordered_map<int, int> freq;

//         for(auto i: arr) { 
//             freq[i]++;
//         }

//         set<int> s;
        
//         for(auto i: freq) { 
//             s.insert(i.second);
//         }

//         return s.size() == freq.size();
//     }
// };

int main() { 
    vector<int> arr = {-4,3,3};

    cout << Solution::uniqueOccurrences(arr);

    return 0;
}

