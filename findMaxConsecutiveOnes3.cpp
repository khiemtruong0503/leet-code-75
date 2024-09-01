#include <iostream>
#include <vector>

using namespace std;

//! self-coded (AC)
// class Solution {
// public:
//     static int longestOnes(vector<int>& nums, int k) {
//         int n =  nums.size();
//         int cnt = 0;
//         int ans = 0;
//         int tempK = k;
//         // this vector stores indices of zeros
//         vector<int> z;

//         for(int i = 0; i < n; ++i) { 
//             if(nums[i] == 1) { 
//                 cnt++;
//             }
//             else { 
//                 if(k > 0) {
//                     z.push_back(i);
//                     cnt++;
//                     k--;
//                 }
//                 else { 
//                     if(cnt > ans) { 
//                         ans = cnt;
//                     }
//                     if(z.empty()) { 
//                         cnt = 0;
//                         k = tempK;
//                         continue;
//                     }
//                     cnt = i - z[0];
//                     z.push_back(i);
//                     z.erase(z.begin());
//                 }
//             }
//         }

//         if(cnt > ans) { 
//             ans = cnt;
//         }
//         return ans;
//     }
// };

//! leetcode reference (same approach, different code style)
class Solution{
    public:
    static int longestOnes(vector<int> &nums, int k) { 
        int n = nums.size();
        int i = 0, j = 0;
        
        while(j < n) { 
            if(nums[j] == 0) { 
                k--;
            }
            if(k < 0) { 
                if(nums[i] == 0) { 
                    k++;
                }
                i++;
            }

            j++;
        }

        cout << "\nj = " << j;
        cout << "\ni = " << i;
        return j - i;
    }
};

int main() { 
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    cout << Solution::longestOnes(nums, 2);

    return 0;
}