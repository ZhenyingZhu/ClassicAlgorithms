#include <iostream>
#include <algorithm>

using namespace std;

// [Source]: https://leetcode.com/problems/add-binary/
// http://www.1point3acres.com/bbs/thread-224495-1-1.html

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length())
            swap(a, b);

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        vector<char> res;
        int carry = 0;
        int ap = 0, bp = 0;
        while (ap < (int)a.length() && bp < (int)b.length()) {
            int sum = a[ap] - '0' + b[bp] - '0' + carry;
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
            ++ap;
            ++bp;
        }

        while (ap < (int)a.length()) {
            int sum = a[ap] - '0' + carry;
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
            ++ap;
        }

        if (carry != 0)
            res.push_back(carry + '0');

        return string(res.rbegin(), res.rend());
    }
};

int main() {
    Solution sol;

    cout << sol.addBinary("11", "1") << endl;
}
