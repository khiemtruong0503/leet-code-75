#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//! self-coded 
class Solution {
    public:
    //! brute-force (TLE)
    // static int maxArea(vector<int> &height) { 
    //     int size = height.size();

    //     int maxArea = 0;
    //     for(int i = 0; i < size - 1; ++i) { 
    //         for(int j = i + 1; j < size; ++j) { 
    //             int curArea = min(height[i], height[j]) * (j - i);
    //             if(curArea > maxArea) { 
    //                 maxArea = curArea;
    //             }
    //         }
    //     }

    //     return maxArea;
    // }
    
    //! two-pointer approach (accepted)
    static int maxArea(vector<int> &height) { 
        int size = height.size();

        int maxArea = 0;
        int left = 0; 
        int right = size - 1;
        while(left < right) {
            int curArea = min(height[left], height[right]) * (right - left);

            if(curArea > maxArea) { 
                maxArea = curArea;
            }
            height[left] <= height[right] ? left++ : right--;
        }

        return maxArea;
    }
};


int main() { 
    vector<int> height = {2,3,4,5,18,17,6};

    cout << Solution::maxArea(height);

    return 0;
}