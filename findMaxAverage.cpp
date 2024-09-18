#include <iostream>
#include <vector>

using namespace std;

//! self-coded
class Solution {
public:
    static double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxAvg = 0;
        // get first ans
        for(int i = 0; i < k; ++i) { 
            maxAvg += nums[i];
        }
        maxAvg /= k;

        int idx = 0;
        double curWindow = maxAvg * k;
        for(int i = k; i < n; ++i) { 
            double avg = (curWindow - nums[idx++] + nums[i]) / k;
            if(avg > maxAvg) { 
                maxAvg = avg;
            }
            curWindow = avg * k;
        }

        return maxAvg;
    }
};

int main() { 
    vector<int> nums = { 1,12,-5,-6,50,3};

    cout << Solution::findMaxAverage(nums, 4);

    return 0;
}