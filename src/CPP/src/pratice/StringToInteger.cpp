#include <iostream>
#include <climits>

using namespace std;

// [Source]: https://leetcode.com/problems/string-to-integer-atoi/?tab=Description
// http://www.1point3acres.com/bbs/thread-223926-1-1.html

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;

        str = trim(str);
        int num = 0, sign = 1;
        str = getSign(str, sign);

        for (int i = 0; i < (int)str.length() && isdigit(str[i]); i++) {
            int prev = num;
            num = 10 * num + sign * (str[i] - '0');
            if (num / 10 != prev) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
        }
        return num;
    }

    string trim(string &str) {
        return str.substr(str.find_first_not_of(" "));
    }

    string getSign(string &str, int &sign) {
        if (str[0] == '-')
            sign = -1;

        if (str[0] == '-' || str[0] == '+')
            return str.substr(1);
        return str;
    }
};

int main() {
    Solution sol;

    cout << sol.myAtoi("    -11100 a   ") << endl;
    cout << sol.myAtoi("    -1000000000000 a   ") << endl;

    return 0;
}
