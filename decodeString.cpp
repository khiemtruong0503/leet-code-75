#include <iostream>
#include <string>
#include <stack> 
#include <cmath>

using namespace std;

// class Solution {
// public:
//     static string decodeString(string s) {
//         int n = s.size();
//         string ans;

//         size_t idx = 0;
//         for(int i = -1; i < n;) { 
//             // get number 
//             idx = s.find_first_of('[', idx);
//             if(idx == string::npos) { 
//                 break;
//             }
            
//             string tmp = s.substr(i + 1, idx - i);
//             int num = stoi(tmp);

//             // get encoded_string
//             int tmp_idx = idx;
//             idx = s.find_first_of(']', idx);
//             string ncd_str = s.substr(tmp_idx + 1, idx - tmp_idx - 1);

//             for(int j = 0; j < num; ++j) { 
//                 ans += ncd_str;
//             }

//             i = idx;
//         }

//         return ans;
//     }
// };

// attemp #2
// class Solution {
// public:
//     static int getNumber(string s, int start, int end) { 
//         int n = s.size(); 
//         string num;

//         for(int i = start; i < end; ++i) { 
//             if(s[i] >= '0' && s[i] <= '9') { 
//                 num += s[i];
//             } 
//             else if(s[i] == '[') { 
//                 break;
//             }
//         }

//         if(num == "") { 
//             num = "1";
//         }

//         return stoi(s);
//     }   
//     static string getEncodedStr(string s) { 
//         int n = s.size();
//         string ans;

//         for(int i = 0; i < n; ++i) { 
//             if(s[i] < 'a' || s[i] > 'z') { 
//                 break;
//             }
//             ans += s[i];
//         }

//         return ans;
//     }
//     static string decodeString(string s) {
//         stack<string> stk;
        
//         size_t found = s.find('[');
//         int idx = 0;
//         while(found != string::npos) {
//             int num = getNumber(s, 0, found);
//             int tmp_Found = found;
//             int numInBracket;
//             found = s.find('[');
//             if(found != string::npos) { 
//                 numInBracket = getNumber(s, tmp_Found, found);
//             }
//         }
//     }
// };


// int main() { 
//     string s = "2[abc]3[cd]ef";

//     cout << Solution::decodeString(s);

//     return 0;
// }

/*attemp #3 success*/
class Solution {
public:
    string decodeString(string s) {
        // step 1: starts at index 0, find the string that starts from idx = 0 to the first found open square bracket's index
        // step 2:check the string before the open square bracket, if it's a number then print the content behind the open square bracket, if not then print it out as string once only
        string ans;
        size_t idx = 0;
        size_t openSqrBracketIdx = 0;
        size_t closeSqrBracketIdx = 0;

        

        while (openSqrBracketIdx != string::npos) { 
            openSqrBracketIdx  = s.find('[', idx);

            if (openSqrBracketIdx == string::npos) { 
                ans += s.substr(idx, s.size() - idx);
                // ans += s.substr(idx, s.size());

                break;
            }
            string tmp = s.substr(idx, openSqrBracketIdx - idx);
            bool containsCharacters = false;
            for(int i = 0; i < tmp.size(); ++i) { 
                if (tmp[i] >= 'a' && tmp[i] <= 'z') {
                    containsCharacters = true;
                    break;
                }
            }

            if (containsCharacters) { 
                string chars;
                for(int i = 0; i < tmp.size(); ++i) { 
                    if (tmp[i] >= '0' && tmp[i] <= '9') { 
                        idx = i;
                        break;
                    }
                    chars += tmp[i];
                }
                ans += chars;
                if (closeSqrBracketIdx == 0) { 
                    idx = closeSqrBracketIdx + idx;
                }
                else idx = closeSqrBracketIdx + idx + 1;
                continue;
            }  
            else { 
                int stackOpenSqrBrackets = 1; // acts as stack
                int number = stoi(tmp);
                // find the content inside the square brackets

                //? find current close bracket
                for (int i = openSqrBracketIdx + 1; i < s.size(); ++i) { 
                    if (s[i] == '[') {
                        stackOpenSqrBrackets++;
                    }
                    else if(s[i] == ']') { 
                        stackOpenSqrBrackets--;
                        if (stackOpenSqrBrackets == 0) {
                            closeSqrBracketIdx = i;
                            break;
                        }
                    }
                }

                string contentInsideBrackets = s.substr(openSqrBracketIdx + 1, closeSqrBracketIdx - 1 - openSqrBracketIdx);
                while(number--) { 
                    ans += decodeString(contentInsideBrackets);
                }
            }

            idx = closeSqrBracketIdx + 1;
        }

        return ans;
    }
};

int main() { 
    Solution s;

    cout << s.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef"); 
}