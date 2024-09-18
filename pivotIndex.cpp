#include <iostream>
#include <vector>

using namespace std;

//! self-coded
class Solution {
public:
    static int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0;

        // find right sum
        int right = 0;
        for(int i = 1; i < n; ++i) { 
            right += nums[i];
        }

        for(int i = 0; i < n - 1; ++i) { 
            if(left == right) { 
                return i;
            }
            else { 
                left += nums[i];
                right -= nums[i + 1];
            }
        }

        if(left == right) { 
            return n - 1;
        }

        return -1;
    }
};