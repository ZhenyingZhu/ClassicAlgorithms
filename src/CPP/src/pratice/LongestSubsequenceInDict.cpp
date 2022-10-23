#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-225639-1-1.html

class Solution {
public:
    string longestSubsequenceWord(string str, vector<string> &dict) {
        vector<unordered_map<char, int>> jumpTable = buildCache(str);

        string longestWord = "";
        for (string &word : dict) {
            if (isSubsequence(word, jumpTable)) {
                if (word.length() > longestWord.length()) {
                    longestWord = word;
                }
            }
        }
        return longestWord;
    }

private:
    vector<unordered_map<char, int>> buildCache(string &str) {
        int len = str.length();
        vector<unordered_map<char, int>> table(len);
        for (int i = 0; i < len; ++i) {
            char &c = str[i];
            if (!table[0].count(c))
                table[0][c] = i + 1; // must plus 1

            for (int j = 0; j < i; ++j) {
                if (!table[j + 1].count(c)) {
                    table[j + 1][c] = i + 1;
                }
            }
        }
        return table;
    }

    bool isSubsequence(string &word, vector<unordered_map<char, int>> &table) {
        int pos = 0;
        for (char &c : word) {
            if (!table[pos].count(c))
                return false;
            pos = table[pos][c];
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<string> dict = {"abc", "ac", "caac"};
    cout << sol.longestSubsequenceWord("cabc", dict) << endl;

    return 0;
}
