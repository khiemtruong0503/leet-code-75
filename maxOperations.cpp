#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//! self-codede (two-pointer approach)
class Solution {
public:
    static int maxOperations(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int countOp = 0;
        sort(nums.begin(), nums.end());

        while(left < right) { 
            int Sum = nums[left] + nums[right];
            
            if(Sum == k) { 
                ++left;
                --right;
                ++countOp;
            }
            else if(Sum < k){ 
                ++left;
            }
            else --right;
        }

        return countOp;
    }
};

int main() { 
    vector<int> nums = {2,2,2,3,1,1,4,1};

    cout << Solution::maxOperations(nums, 4);

}