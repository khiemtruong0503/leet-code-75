#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = candies[0];
        int n = candies.size();

        for(int i = 1; i < n; ++i) { 
            if(candies[i] > maxCandy) { 
                maxCandy = candies[i];
            }
        }
        vector<bool> ans(n, false);
        
        for(int i = 0; i < n; ++i) { 
            ans[i] = (candies[i] + extraCandies >= maxCandy) ? true : false; 
        }

        return ans;
    }
};
