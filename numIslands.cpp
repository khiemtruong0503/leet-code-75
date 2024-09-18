#include <iostream>
#include <vector>

using namespace std;

//! self-coded (AC)
class Solution {
public:
    static void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if (grid[i][j] == '0')
        {
            return;
        }

        grid[i][j] = '0';
        
        if (j + 1 < grid[i].size() && grid[i][j + 1] == '1')
        {
            dfs(grid, i, j + 1);
        }

        if (i + 1 < grid.size() && grid[i + 1][j] == '1')
        {
            dfs(grid, i + 1, j);
        }

        if (j - 1 >= 0 && grid[i][j - 1] == '1')
        {
            dfs(grid, i, j - 1);
        }

        if (i - 1 >= 0 && grid[i - 1][j] == '1')
        {
            dfs(grid, i - 1, j);
        }
    }
    static int numIslands(vector<vector<char>>& grid) {
        int countIslands = 0;
        
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '0') continue;

                dfs(grid, i, j); 
                ++countIslands;       
            }
        }

        return countIslands;
    }
};

int main()
{
    vector<vector<char>> v = {
        {'1', '1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    cout << Solution::numIslands(v);
}