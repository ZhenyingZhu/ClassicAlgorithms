/*
 * [Source] https://leetcode.com/problems/reconstruct-original-digits-from-english/
 * [Difficulty]: Medium
 * [Tag]: Math
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>

using namespace std;

// [Solution]: 鸡兔同笼
// [Corner Case]:
class Solution {
public:
    string originalDigits(string s) {
        vector<string> digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        unordered_map<char, set<int>> charDigitsMap;
        for (int digit = 0; digit <= 9; ++digit) {
            for (char &c : digits[digit]) {
                charDigitsMap[c].insert(digit);
            }
        }

        unordered_map<char, int> charCnt;
        for (char &c : s) {
            ++charCnt[c];
        }

int stop = 10;

        int totalChar = s.length();
        map<int, int> digitCnt; // for construct result
        while (totalChar > 0) {

if (--stop == 0) {
    cout << "dead loop" << endl;
    break;
}

cout << "letter " << totalChar << endl;
            for (auto it = charDigitsMap.begin(); it != charDigitsMap.end(); ++it) {
cout << it->first << " " << it->second.size() << endl;
                if (it->second.size() != 1)
                    continue;

                char c = it->first;
                // this char can only map to one number
                int num = *(it->second.begin());
cout << "insert " << num << " from " << c << endl;
                int cnt = 0;
                if (c == 'e' && (num == 3 || num == 7)) {
                    cnt = charCnt[c] / 2;
                } else if (c == 'n' && num == 9) {
                    cnt = charCnt[c] / 2;
                } else {
                    cnt = charCnt[c];
                }

cout << "In total " << cnt << endl;
                digitCnt[num] = cnt;
                totalChar -= cleanUp(cnt, charCnt, digits[num]);

                eraseNum(charDigitsMap, num);
            }
        }

        return constructResult(digitCnt);
    }

    void eraseNum(unordered_map<char, set<int>> &charDigitsMap, int num) {
        for (auto it = charDigitsMap.begin(); it != charDigitsMap.end(); ++it) {
            it->second.erase(num);
        }
    }

    string constructResult(map<int, int> &digitCnt) {
        string res;
        for (auto it = digitCnt.begin(); it != digitCnt.end(); ++it) {
            char c = it->first + '0';
            res += string(it->second, c);
        }
        return res;
    }

    int cleanUp(int cnt, unordered_map<char, int> &charCnt, string &digit) {
        int deleteCharCnt = 0;
        for (char &c : digit) {
            charCnt[c] -= cnt;
            deleteCharCnt += cnt;
        }
        return deleteCharCnt;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.originalDigits("owoztneoer") << endl;

    return 0;
}
