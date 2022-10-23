/*
 * [Source] https://leetcode.com/problems/strong-password-checker/
 * [Difficulty]: Hard
 * [Tag]: 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Delete is no cheaper than insert than replace. If delete is necessary, trying to delete chars to make replace cheaper. If meet this question during interview, just go die
// [Corner Case]:
class Solution {
public:
    int strongPasswordChecker(string s) {
        if (s.length() == 0)
            return 6;

        // checking if has upper, lower and digit
        int typeCnt = countType(s);

        // checking how many chars need to insert
        int totalCnt = s.length();
        if (totalCnt < 6) {
            // need insert some chars
            // if less than 4 repeats, insert 1 char can handle
            // 5 repeats, there must be less typeCnt than necessary, replace the middle repeat can handle
            return max(6 - totalCnt, 3 - typeCnt);
        }

        // checking how many char needs to delete
        int deleteCnt = 0;
        int charNumOver = totalCnt > 20 ? totalCnt - 20 : 0;

        // count total number of chars that has more than 3 repeat chars in a row
        vector<int> repeats = countRepeats(s);

        // trying to delete some chars to make the number of chars that  need replaced minimal
        bool needDelete = charNumOver > 0;
        for (int mod = 0; mod < 3; ++mod) {
            if (!needDelete)
                break;
            for (int i = 0; i < (int)repeats.size(); ++i) {
                if (repeats[i] < 3 || repeats[i] % 3 != mod)
                    continue;
                // e.g. aaaaaaaa, delete 3 chars becomes aaaaa, which need only 1 replace
                if (charNumOver < mod + 1) {
                    needDelete = false;
                    break;
                }
                deleteCnt += mod + 1;
                charNumOver -= mod + 1;
                repeats[i] -= mod + 1;
            }
        }
        deleteCnt += charNumOver;

        int changeCnt = 0;
        for (int &r : repeats) {
            if (r >= 3)
                changeCnt += r / 3;
        }

        return deleteCnt + max(changeCnt, 3 - typeCnt);
    }

    int countType(string &s) {
        bool hasupper = false, haslower = false, hasdigit = false;
        int typeCnt = 0;
        for (char &c : s) {
            if (isdigit(c)) {
                if (!hasdigit) {
                    hasdigit = true;
                    ++typeCnt;
                }
            } else if (isupper(c)) {
                if (!hasupper) {
                    hasupper = true;
                    ++typeCnt;
                }
            } else if (islower(c)) {
                if (!haslower) {
                    haslower = true;
                    ++typeCnt;
                }
            }

            if (typeCnt == 3)
                break;
        }
        return typeCnt;
    }

    vector<int> countRepeats(string &s) {
        vector<int> repeats;
        int curCnt = 1;
        for (int i = 1; i < (int)s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                ++curCnt;
            } else {
                if (curCnt >= 3)
                    repeats.push_back(curCnt);
                curCnt = 1;
            }
        }
        if (curCnt >= 3)
            repeats.push_back(curCnt);
        return repeats;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.strongPasswordChecker("aaaaaaaaaaaaaaaaaaaaa") << endl;
                                     //aaxaaxaaxaaxaaxaaxaa

    return 0;
}
