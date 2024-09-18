#include <iostream>
#include <vector>

using namespace std;

//! self-coded (AC)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int ans = 0;
        int idx = -1;

        for(int i = 0; i < n; ++i) { 
            if(nums[i] == 1) {
                ++cnt;
                continue;
            }
            else { 
                if(idx == -1) { 
                    idx = i;
                    ++cnt;
                }
                else {
                    if(cnt > ans) { 
                        ans = cnt;
                    }
                    cnt = i - idx;
                    idx = i;
                }
            }
        }
        
        if(cnt > ans) { 
            ans = cnt;
        }

        return ans - 1;
    }
};
