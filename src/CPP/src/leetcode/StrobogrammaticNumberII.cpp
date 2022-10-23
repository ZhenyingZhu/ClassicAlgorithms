/*
 * [Source] https://leetcode.com/problems/strobogrammatic-number-ii/
 * [Difficulty]: Medium
 * [Tag]: Math
 * [Tag]: Recursion
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// [Solution]: A map between strobogrammatic numbers. Backtracking to add numbers. Notice 0 cannot be the first char, and middle char can only be 0, 1, 8
// [Corner Case]:
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        unordered_map<char, char> pairs;
        pairs['0'] = '0';
        pairs['1'] = '1';
        pairs['6'] = '9';
        pairs['8'] = '8';
        pairs['9'] = '6';
        vector<char> useable = {'0', '1', '6', '8', '9'};
        vector<char> midable = {'0', '1', '8'};

        vector<string> partial;
        vector<char> prev;
        helper(useable, prev, n / 2, partial);

        if (n % 2 == 0)
            return construct(partial, {' '}, pairs);
        else
            return construct(partial, midable, pairs);
    }

    void helper(const vector<char> &useable, vector<char> &prev, int targetLen, vector<string> &res) {
        if ((int)prev.size() == targetLen) {
            res.push_back( string(prev.begin(), prev.end()) );
            return;
        }

        for (const char &c : useable) {
            if (prev.empty() && c == '0')
                continue;
            prev.push_back(c);
            helper(useable, prev, targetLen, res);
            prev.pop_back();
        }
    }

    vector<string> construct(vector<string> &partial, vector<char> middle, unordered_map<char, char> &pairs) {
        vector<string> res;
        for (string &part : partial) {
            int len = part.length();
            for (char &m : middle) {
                string str = part;
                if (m != ' ')
                    str += m;
                for (int i = len - 1; i >= 0; --i) {
                    str += pairs[ str[i] ];
                }
                res.push_back(str);
            }
        }
        return res;
    }
};


int main() {
    Solution sol;

    vector<string> res = sol.findStrobogrammatic(3);
    for (string &str : res)
        cout << str << " ";
    cout << endl;


    return 0;
}
