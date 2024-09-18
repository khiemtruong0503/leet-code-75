#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//! self-coded
class Solution {
public:
    static int largestAltitude(vector<int>& gain) {
        vector<int> heights(1, 0);
        int n = gain.size();

        for(int i = 0; i < n; ++i) { 
            heights.push_back(heights[heights.size() - 1] + gain[i]);
        }

        return *max_element(heights.begin(), heights.end());
    }
};
