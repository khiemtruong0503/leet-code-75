#include <iostream>
#include <vector>
#include <algorithm> 
#include <utility>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

//! self-coded (AC)
class Solution {
public:
    static bool canVisitAllRooms(vector<vector<int>>& rooms) {
        map<int, vector<int>> mapRooms;

        for (int i = 0; i < rooms.size(); ++i)
        {
            pair<int, vector<int>> p(i, rooms[i]);
            mapRooms.insert(p);
        }
        
        unordered_set<int> currentKeys = unordered_set<int>(rooms[0].begin(), rooms[0].end());
        mapRooms.erase(mapRooms.begin());
        while (mapRooms.size() > 0 && currentKeys.size() > 0)
        {
            currentKeys.erase(0);
            int keyOfTraveledRoom = *currentKeys.begin();

            vector<int> newKeys;
            if (mapRooms.find(keyOfTraveledRoom) != mapRooms.end())
            {
                newKeys = mapRooms.at(keyOfTraveledRoom);
                currentKeys.insert(newKeys.begin(), newKeys.end());
            }
            else
            {
                currentKeys.erase(keyOfTraveledRoom);
                continue;
            }
            // check if current key list is sufficient to go through all rooms
            auto map_clone = mapRooms;
            for (unordered_set<int>::iterator it = currentKeys.begin(); it != currentKeys.end(); ++it)
            {
                if (*it == 0) continue;
                if (map_clone.find(*it) != map_clone.end())
                {
                    map_clone.erase(*it);
                }
            }   

            if (map_clone.empty())
            {
                return true;
            }

            mapRooms.erase(keyOfTraveledRoom);
            currentKeys.erase(currentKeys.find(keyOfTraveledRoom));
        }

        return mapRooms.size() == 0 ? true : false;
    }
};

int main()
{
    vector<vector<int>> rooms = {{1,3}, {3,0,1}, {2}, {0}};
    cout << Solution::canVisitAllRooms((rooms));
    return 0;
}

