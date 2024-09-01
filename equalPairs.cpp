#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//! self-coded (AC)
class Solution {
public:
    static int equalPairs(vector<vector<int>>& grid) {
        int Count = 0;
        vector<vector<int>> map; // get a map of grid's columns

        int n = grid.size();
        for(int i = 0; i < n; ++i) { 
            vector<int> v;
            for(int j = 0; j < n; ++j) { 
                v.push_back(grid[j][i]);
            }

            map.push_back(v);
        } 

        for(int i = 0; i < grid.size(); ++i) { 
            vector<vector<int>>::iterator found = find(map.begin(), map.end(), grid[i]);

            while(found != map.end()) { 
                Count++;
                found = find(found + 1, map.end(), grid[i]);
            }
        }

        return Count;
    }
};

int main() { 
    vector<vector<int>> grid = {
        {3,1,2,2},
        {1,4,4,4},
        {2,4,2,2},
        {2,5,2,2},
    };

    cout << Solution::equalPairs(grid);

    return 0;
}