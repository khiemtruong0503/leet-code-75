#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool isDifferByOneLetter(string word1, string word2)
    {
        if (word1.size() != word2.size()) return false;

        int countDifferLetter = 0;
        for (int i = 0;  i < word1.size(); ++i)
        {
            if (word1[i] != word2[i])
            {
                if (countDifferLetter == 0) countDifferLetter++;
                else return false;
            }
        }

        return true;
    }
    static int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        {
            return 0;
        }

        int count = 0;
        string curWord = beginWord;
        for (int i = 0; i < wordList.size(); ++i)
        {
            if (!isDifferByOneLetter(curWord, wordList[i]))
            {
                return 0;
            }

            ++count;
            curWord = wordList[i];
            if (curWord == endWord) break;
        }

        return count;
    }
};

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << Solution::ladderLength(beginWord, endWord, wordList);

    return 0;

}