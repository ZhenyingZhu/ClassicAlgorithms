/*
 * [Source] https://leetcode.com/problems/encode-and-decode-strings/
 * [Difficulty]: Medium
 * [Tag]: String
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Use two special chars and a length in between to indicate if a string is end
// [Corner Case]:
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (string &s : strs) {
            res += s + "#" + to_string(s.length()) + "%";
        }
//cout << res << endl;
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        size_t st = 0;
        size_t ed = s.find_first_of("#");
        while (ed != string::npos) {
            size_t suffixEd = s.find_first_of("%", ed + 1);
            string len = s.substr(ed + 1, suffixEd - ed - 1);
//cout << "len " << len << endl;
            if (convert(len) != -1 && convert(len) == (int)(ed - st)) {
                res.push_back(s.substr(st, ed - st));
                st = suffixEd + 1;
                ed = s.find_first_of("#", st);
            } else {
                ed = s.find_first_of("#", ed + 1);;
            }
        }
        return res;
    }

    long convert(string &len) {
        // deal with the case if the string is only one '#'
        if (len.length() == 0)
            return -1;
        long res = 0;
        for (char &c : len) {
            if (!isdigit(c))
                return -1;
            res = res * 10 + c - '0';
        }
        return res;
    }
};

class Solution {
public:
    void test() {
        Codec codec;
        //vector<string> strs = {"#", "##", "a", "ab", "ab#", "", "#d"};
        vector<string> strs = {};

        cout << "Start" << endl;
        int idx = 0;
        for (string &s : codec.decode(codec.encode(strs))) {
            if (idx < (int)strs.size()) {
                if (s != strs[idx]) {
                    cout << strs[idx - 1] << endl;
                    cout << strs[idx] << " :-: " << s << endl;
                }
                idx++;
            }
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    sol.test();

    return 0;
}
