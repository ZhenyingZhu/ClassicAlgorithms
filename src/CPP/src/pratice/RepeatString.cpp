#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/decode-string
// http://www.1point3acres.com/bbs/thread-226722-1-1.html

class Solution {
public:
    string repeatString(string compact) {
        int pt = 0;
        return helper(compact, pt);
    }

private:
    string helper(string &compact, int &pt) {
        string res = "";
        while (pt < (int)compact.size() && compact[pt] != ']') {
            int num = 0;
            while (pt < (int)compact.size() && isdigit(compact[pt])) {
                num = 10 * num + compact[pt++] - '0';
            }
            if (num == 0)
                num = 1;

            if (compact[pt] == '[') {
                ++pt;
                string substr = helper(compact, pt);
                for (int i = 0; i < num; ++i)
                    res += substr;
                ++pt; // skip ']'
            } else if (compact[pt] == ']') {
                continue; // empty char like []
            } else {
                res += string(num, compact[pt++]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    cout << sol.repeatString("3[2[a]]b") << endl;

    return 0;
}
