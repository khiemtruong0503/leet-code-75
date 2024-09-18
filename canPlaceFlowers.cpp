#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;

        int size = flowerbed.size();

        // check first plot
        if(flowerbed[0] == 0) {
            if(size == 1) { 
                return n == 1 ? true : false;
            } 
            if(flowerbed[1] == 0) { 
                flowerbed[0] = 1;
                n--;
                if(n == 0) return true;
            }
        }

        for(int i = 1; i < size - 1; ++i) { 
            if(flowerbed[i] == 1) { 
                i++;
                continue;
            }
            else { 
                if(flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0) { 
                    flowerbed[i] = 1;
                    n--;
                    if(n == 0) return true;
                    i++;
                }
                continue;
            }
        }

        // check last plot
        if(flowerbed[size - 1] == 0 && flowerbed[size -2] == 0) { 
            flowerbed[size -1] =1;
            n--;
        }

        if(n == 0) return true;

        return false;
    }
};

int main() { 
    vector<int> flowerbed = {0,0,1,0,1};

    cout << Solution::canPlaceFlowers(flowerbed, 1);

    return 0;
}
