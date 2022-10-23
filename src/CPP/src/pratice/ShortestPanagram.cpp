#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-224545-1-1.html

// [Solution]: Use a map to store char positions. but needs t to be unique
class SolutionMap {
public:
    string minWindow(string s, string t) {
        int width = t.length();
        int showed = 0;
        unordered_map<char, int> charPos;

        string res;
        int minLen = INT_MAX;
        int st = -1; // minus it can return right len
        for (int i = 0; i < (int)s.length(); ++i) {
            char c = s[i];
            if (t.find(c) == string::npos)
                continue; // invalid char

            if (charPos.count(c) == 0)
                ++showed;
            charPos[c] = i;

            if (showed == width) {
                if (i - st < minLen) {
                    minLen = i - st;
                    res = s.substr(st + 1, minLen);
                }

                char firstChar = charPos.begin()->first;
                int firstPos = charPos.begin()->second;
                for (auto it = ++charPos.begin(); it != charPos.end(); ++it) {
                    if (it->second < firstPos) {
                        firstChar = it->first;
                        firstPos = it->second;
                    }
                }
                charPos.erase(firstChar);

                int secondPos = charPos.begin()->second;
                for (auto it = ++charPos.begin(); it != charPos.end(); ++it) {
                    if (it->second < secondPos) {
                        secondPos = it->second;
                    }
                }
                st = secondPos - 1;
                --showed;
            }
        }

        return res;
    }
};

// [Solution]: Two Pointers
class Solution {
public:
    string minWindow(string s, string t) {
        int width = t.length();
        int len = s.length();
        if (width == 0 || len == 0 || len < width)
            return "";

        unordered_map<char, int> charCnt;
        for (char &c : t)
            charCnt[c]++;

        int st = 0;
        int showed = 0;
        string res;
        for (int i = 0; i < len; ++i) {
            char cur = s[i];
            if (charCnt.count(cur)) {
                if (charCnt[cur] > 0)
                    showed++;
                charCnt[cur]--;
            }

            while (showed == width) {
                char head = s[st];
                if (charCnt.count(head)) {
                    charCnt[head]++;
                    if (charCnt[head] > 0) {
                        if (res.empty() || i -st + 1 < (int)res.length())
                            res = s.substr(st, i -st + 1);
                        --showed;
                    }
                }
                ++st;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    cout << sol.minWindow("adcdba", "abc") << endl;

    return 0;
};
