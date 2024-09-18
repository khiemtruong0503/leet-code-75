#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//! self-coded (AC)
class Solution {
public:
    static vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int size = asteroids.size();

        s.push(asteroids[0]);
        for(int i = 1; i < size; ++i) { 
            if(s.empty()) {
                s.push(asteroids[i]);
                continue;
            }
            if(asteroids[i] < 0 && s.top() > 0) { 
                bool isCollided = false;
                while(!s.empty()) { 
                    if(abs(asteroids[i]) > s.top() && s.top() > 0) { 
                        s.pop();
                    }
                    else if(abs(asteroids[i]) == s.top() && asteroids[i] < 0) { 
                        s.pop();
                        isCollided = true;
                        break;
                    } 
                    else { 
                        if(s.top() > abs(asteroids[i])) { 
                            isCollided = true;
                        }
                        break;
                    }
                }
                if(!isCollided) { 
                    s.push(asteroids[i]);
                }
            }
            else { 
                s.push(asteroids[i]);
            }
        }

        vector<int> ans; 
        while(!s.empty()) { 
            ans.insert(ans.begin(), s.top());
            s.pop();
        }

        return ans;
    }
};

int main() { 
    vector<int> asteroids = {1,-1,-2,-2};

    vector<int> ans = Solution::asteroidCollision(asteroids);
    int n = ans.size();

    cout << '[';
    for(int i = 0; i < n; ++i) { 
        cout << ans[i];

        if(i < n - 1) { 
            cout << ',';
        }
    }
    cout << ']';
    return 0;
}