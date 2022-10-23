#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-225716-1-1.html
// http://www.1point3acres.com/bbs/thread-222632-1-1.html
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class SolutionDFS {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        unordered_map<char, string> digitMap;
        digitMap['0'] = " ";
        digitMap['1'] = "";
        digitMap['2'] = "abc";
        digitMap['3'] = "def";
        digitMap['4'] = "ghi";
        digitMap['5'] = "jkl";
        digitMap['6'] = "mno";
        digitMap['7'] = "pqrs";
        digitMap['8'] = "tuv";
        digitMap['9'] = "wxyz";

        vector<string> res;
        vector<char> partial;
        helper(digits, 0, digitMap, partial, res);
        return res;
    }

    void helper(string &digits, size_t idx, unordered_map<char, string> &digitMap, vector<char> &partial, vector<string> &res) {
        if (idx == digits.length()) {
            res.push_back(string(partial.begin(), partial.end()));
            return;
        }

        string &candidates = digitMap[digits[idx]];
        if (candidates.empty()) { // num 1
            helper(digits, idx + 1, digitMap, partial, res);
        } else {
            for (char &c : candidates) {
                partial.push_back(c);
                helper(digits, idx + 1, digitMap, partial, res);
                partial.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        unordered_map<char, string> digitMap;
        digitMap['0'] = " ";
        digitMap['1'] = "";
        digitMap['2'] = "abc";
        digitMap['3'] = "def";
        digitMap['4'] = "ghi";
        digitMap['5'] = "jkl";
        digitMap['6'] = "mno";
        digitMap['7'] = "pqrs";
        digitMap['8'] = "tuv";
        digitMap['9'] = "wxyz";

        string partial = "";
        queue<string> prevRes;
        prevRes.push(partial);
        for (int idx = 0; idx < (int)digits.length(); ++idx) {
            string &candidates = digitMap[digits[idx]];
            if (candidates.empty())
                continue;

            int size = prevRes.size();
            for (int i = 0; i < size; ++i) {
                string &prev = prevRes.front();
                prevRes.pop();

                for (char &c : candidates) {
                    prevRes.push(prev + c);
                }
            }
        }

        vector<string> res;
        while (!prevRes.empty()) {
            res.push_back(prevRes.front());
            prevRes.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;

    for (string &str : sol.letterCombinations("123"))
        cout << str << endl;

    return 0;
}
