#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans(1, asteroids[0]);
        int size = asteroids.size();

        for(int i = 1; i < size; ++i) { 
            if(asteroids[i] * ans.back() < 0) {
                if(asteroids[i] > 0) {
                    ans.push_back(asteroids[i]);
                    continue;
                } 
                while(abs(asteroids[i]) > abs(ans.back())) { 
                    ans.pop_back();
                }

                if(abs(asteroids[i]) == abs(ans.back())) { 
                    ans.pop_back();
                    continue;
                }
            }
            else{ 
                ans.push_back(asteroids[i]);
            }
        }

        return ans;

    }
};

int main() { 
    vector<int> asteroids = {-2,-2,1,-2};

    vector<int> ans = Solution::asteroidCollision(asteroids);

    cout << '[';
    for(int i = 0; i < ans.size(); ++i) { 
        cout << ans[i];
        if(i < ans.size() - 1) { 
            cout << ',';
        }
    }
    cout << ']';

    return 0;
}