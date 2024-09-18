#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return;
        bool fisrtZero = true;
        int idx = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0) {
                if(fisrtZero) { 
                    fisrtZero = false;
                    nums.erase(nums.begin() + i);
                    nums.push_back(0);
                    i--;
                    idx = nums.size() - 1;
                } 
                else if(i < idx) { 
                    nums.erase(nums.begin() + i);
                    nums.push_back(0);
                    i--;
                    idx--;
                }
            }
        }
    }
};

int main() { 
    vector<int> nums = {0,1,0,3,12};

    Solution::moveZeroes(nums);

    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
}