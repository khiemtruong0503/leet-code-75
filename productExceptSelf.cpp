#include <iostream>
#include <vector>

using namespace std;

//! self-coded (TLE)
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n, 1);

//         for(int i = 0; i < n; ++i) { 
//             for(int j = 0; j < n; ++j) { 
//                 if(j == i) continue;

//                 if(nums[j] == 0) {
//                     ans[i] = 0;
//                     break;
//                 }
//                 ans[i] *= nums[j];
//             }
//         }

//         return ans;
//     }
// };

//! leetcode reference (DP - tabulation)
class Solution {
    public:
    static vector<int> productExceptSelf(vector<int> &nums) { 
        int n = nums.size();
        vector<int> leftProd(n);
        vector<int> rightProd(n);
        vector<int> ans;

        // get left products
        leftProd[0] = 1;
        for(int i = 1; i < n; ++i) { 
            leftProd[i] = leftProd[i - 1] * nums[i - 1];
        }

        // get right products
        rightProd[n - 1] = 1;
        for(int i = n - 2; i >= 0; --i) { 
            rightProd[i] = rightProd[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < n; ++i) { 
            ans.push_back(leftProd[i] * rightProd[i]);
        }

        return ans;
    }
};

int main() { 
    vector<int> nums = {1,2,3,4};
    vector<int> ans = Solution::productExceptSelf(nums);

    cout << '[';
    for(int i = 0; i < ans.size(); ++i) { 
        cout << ans[i];
        if(i < ans.size() -1) { 
            cout << ',';
        }
    }
    cout << ']';
    return 0;
}