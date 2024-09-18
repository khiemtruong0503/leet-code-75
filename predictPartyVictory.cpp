#include <iostream>
#include <string>
#include <queue>

using namespace std;

//! self-coded (AC)
// class Solution {
// public:
//     static string predictPartyVictory(string senate) {
//         int i = 0;
//         while(senate.size() > 1) { 
//             if(i >= senate.size()) { 
//                 i = 0;
//             }
//             if(senate[i] == 'R') { 
//                 // check announce victory
//                 size_t found = senate.find('D', i);
                
//                 if(found == string::npos) { 
//                     found = senate.find('D');

//                     if(found == string::npos) {
//                         return "Radiant";
//                     }
//                 }

//                 // ban one senator's right
//                 senate.erase(found, 1);
//                 if(found < i) { 
//                     --i;
//                 }
//             }
//             else { 
//                 // check announce victory
//                 size_t found = senate.find('R', i);

//                 if(found == string::npos) { 
//                     found = senate.find('R');

//                     if(found == string::npos) { 
//                         return "Dire";
//                     }
//                 }

//                 // ban one senator's right
//                 senate.erase(found, 1);
//                 if(found < i) { 
//                     --i;
//                 }
//             }

//             ++i;
//         }

//         if(senate[0] == 'R') { 
//             return "Radiant";
//         }

//         return "Dire";
//     }
// };

//! leetcode reference 
class Solution {
public:
    static string predictPartyVictory(string senate) {
        int size = senate.size(), idx = size;
        queue<int> Radiant, Dire;

        for(int i = 0; i < size; ++i) { 
            if(senate[i] == 'R') { 
                Radiant.push(i);
            }
            else Dire.push(i);
        }

        while(!Radiant.empty() && !Dire.empty()) {
            if(Radiant.front() < Dire.front()) { 
                Dire.pop();
                Radiant.pop();
                Radiant.push(idx++);
            }
            else { 
                Radiant.pop();
                Dire.pop();
                Dire.push(idx++);
            }
        }

        if(!Radiant.empty()) { 
            return "Radiant";
        }
        return "Dire";
    }
};

int main() { 
    cout << Solution::predictPartyVictory("DRRDRDRDRDDRDRDR");

    return 0;
}