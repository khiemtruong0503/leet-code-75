#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

//! self-coded
// class Solution {
// public:
//     static bool isPrimeString(int n) { 
//         if(n <= 1) return false;
//         if(n <= 3) return true;
//         if(n % 2 == 0) return false;

//         for(int i = 3; i * i <= n; i += 2) { 
//             if(n % i == 0) return false;
//         }

//         return true;
//     }
//     static bool checkGcd(string str, string s) { 
//         int size = str.size();
//         int n = s.size();

//         for(int i = 0; i < size; i += n) { 
//             string t = str.substr(i, n);
            
//             if(t != s) return false;
//         }

//         return true;
//     }
//     static string gcdOfStrings(string str1, string str2) {
//         string ans;
//         if(str1.size() < str2.size()) { 
//             string temp = str1;
//             str1 = str2;
//             str2 = temp;
//         }
//         int size1 = str1.size();
//         int size2 = str2.size();
//         bool isGcd = true;
        
//         // check if str2 is gcd
//         for(int i = 0; i < size1; i += size2) { 
//             string t = str1.substr(i, i + size2);

//             if(t != str2) {
//                 isGcd = false; 
//                 break;
//             }
//         }

//         if(isGcd) { 
//             return str2;
//         }
//         else if(isPrimeString(str2.size())) { 
//             return "";
//         }            
//         else { 
//             for(int i = size2 / 2; i > 0; --i) { 
//                 string s = str2.substr(0, i);

//                 if(!checkGcd(str1, s)) { 
//                     continue;
//                 }
//                 else if(!checkGcd(str2, s)) { 
//                     continue;
//                 }
//                 return s;
//             }
//         }
        
//         return "";
//     }
// };

//! second approach (leetcode reference)
class Solution {
    public:
    static int gcd(int a, int b) { 
        while(a != b) { 
            if(a > b) { 
                a -= b;
            }
            else if(a < b) { 
                b -= a;
            }

            if(a == b) { 
                return b;
            }
        }

        return 1;
    }
    static string gcdOfStrings(string str1, string str2) { 
        return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(str1.size(), str2.size())) : "";
    }
};

int main() { 
    cout << Solution::gcdOfStrings("ABCABC", "ABC");

    return 0;
}