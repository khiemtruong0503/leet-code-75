#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

using namespace std;

//! leetcode reference
class Solution {
public:
    static void dfs(vector<vector<int>> arr, int idx, map<int, bool>& visited)
    {
        visited.at(idx) = false;
        for (int i = 0; i < arr[idx].size(); ++i)
        {
            if (arr[idx][i] == 1 && visited.at(i))
            {
                dfs(arr, i, visited);
            }
        }
    }

    static int findCircleNum(vector<vector<int>>& isConnected) {
        map<int, bool> visited;

        for (int i = 0; i < isConnected.size(); ++i)
        {
            visited.insert(pair<int, bool>(i, true));
        }    

        int count = 0;
        for (int i = 0; i < isConnected.size(); ++i)
        {
            for (int j = 0; j < isConnected[i].size(); ++j)
            {
                if (isConnected[i][j] == 1 && visited.at(j))
                {
                    count++;
                    dfs(isConnected, j, visited);
                }
            }
        }

        return count;
    }
};

int main()
{
    vector<vector<int>> v = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};

    cout << Solution::findCircleNum(v);
}