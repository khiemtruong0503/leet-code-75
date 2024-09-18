#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void dfs_left(vector<vector<int>>& connections, int node, int &i, int& count)
    {
        if (i == -1) return;
        if (connections[i][0] != node && connections[i][1] != node || (connections[i][0] == 0 || connections[i][1] == 0))
        {
            ++i;
            return;
        }

        if (connections[i][1] != node)
        {
            node = connections[i][1];
            count++;
        }
        else node = connections[i][0];

        dfs_left(connections, node, --i, count);
    }
    static void dfs_right(vector<vector<int>>& connections, int node, int &i, int& count)
    {
        if (i == connections.size()) return;
        if (connections[i][0] != node && connections[i][1] != node || (connections[i][0] == 0 || connections[i][1] == 0))
        {
            --i;
            return;
        }

        if (connections[i][1] != node)
        {
            node = connections[i][1];
            count++;
        }
        else node = connections[i][0];

        dfs_right(connections, node, ++i, count);
    }
    static int minReorder(int n, vector<vector<int>>& connections) 
    {
        int count = 0;
        for (int i = 0; i < connections.size(); ++i)
        {
            if (connections[i][0] == 0 || connections[i][1] == 0)
            {
                int node = connections[i][0];
                if (connections[i][1] != 0)
                {
                    node = connections[i][1];
                    count++;
                }

                int tmp = i;                
                dfs_left(connections, node, --i, count);
                i = tmp;
                dfs_right(connections, node, ++i, count);
            }
        }

        return count;
    }
};

int main() 
{
    vector<vector<int>> v = {{4,3}, {2,3},{1,2},{1,0}};

    cout << Solution::minReorder(6, v);
}

