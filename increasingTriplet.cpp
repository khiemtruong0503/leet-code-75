#include <iostream>
#include <vector>

using namespace std;

//! self-coded (TLE)
// class Solution {
// public:
//     static bool increasingTriplet(vector<int>& nums) {
//         int n = nums.size();

//         for(int i = 0; i < n - 2; ++i) { 
//             for(int j = i + 1; j < n - 1; ++j) { 
//                 if(nums[j] <= nums[i]) { 
//                     continue;
//                 }
//                 for(int k = j + 1; k < n; ++k) { 
//                     if(nums[k] <= nums[j]) { 
//                         continue;
//                     }
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };

//! leetcode discussion (TLE)
// idea is: at index i, check whether exists a number in range of [0, i) that is
// smaller than nums[i]; a number in range of (i, n) that is greater than nums[i]

// class Solution {
//     public:
//     static bool increasingTriplet(vector<int> &nums) { 
//         int n = nums.size();

//         for(int i = 1; i < n - 1; ++i) {
//             bool isIncreasing = false;
//             for(int j = 0; j < i; ++j) { 
//                 if(nums[j] < nums[i]) { 
//                     isIncreasing = true;
//                     break;
//                 }
//             }

//             if(!isIncreasing) { 
//                 continue; 
//             }

//             isIncreasing = false;
//             for(int j = i + 1; j < n; ++j) { 
//                 if(nums[j] > nums[i]) {
//                     isIncreasing = true;
//                     break;
//                 }
//             }

//             if(isIncreasing) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

//! leetcode solution
class Solution {
    public:
    static bool increasingTriplet(vector<int> &nums) { 
        int n = nums.size();
        int a = INT32_MAX, b = INT32_MAX;

        for(int i = 0; i < n; ++i) { 
            if(nums[i] <= a) { 
                a = nums[i];
                continue;
            }
            if(nums[i] >= a && nums[i] <= b) {
                b = nums[i];
                continue;
            }
            if(nums[i] >= b) { 
                return true;
            }
        }
        return false;
    }
};
int main() { 
    vector<int> nums = {5,4,3,2,1};

    cout << Solution::increasingTriplet(nums);

    return 0;
}
