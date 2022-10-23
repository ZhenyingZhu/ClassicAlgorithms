#include <iostream>

using namespace std;

// [Source]: https://leetcode.com/problems/count-and-say/
// http://www.1point3acres.com/bbs/thread-222467-1-1.html

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 1; i < n; ++i) {
            str = helper(str);
        }
        return str;
    }

    string helper(string &str) {
        int cnt = 1;

        string res;
        for (int i = 1; i < (int)str.length(); ++i) {
            if (str[i] == str[i - 1]) {
                ++cnt;
            } else {
                res += to_string(cnt) + str[i - 1];
                cnt = 1;
            }
        }
        res += to_string(cnt) + str.back();
        return res;
    }
};

int main() {
    Solution sol;

    for (int i = 1; i <= 5; ++i)
        cout << sol.countAndSay(i) << endl;

    return 0;
}
