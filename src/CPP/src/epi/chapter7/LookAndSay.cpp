#include "LookAndSay.hpp"

#include <iostream>
#include <string>
#include <array>

using std::string;
using std::cout;
using std::endl;
using std::to_string;

namespace epi {
  namespace chapter7 {
    string LookAndSay::nextNumber(string &s) {
        string res = "";

        int count = 0, start = 0, cur = 0, size = s.size();
        for (; cur != size; ++cur) {
            if (s[cur] == s[start])
                ++count;
            else {
                res += to_string(count) + s[start];
                count = 1;
                start = cur;
            }
        }

        res += to_string(count) + s[start];

        return res;
    }

    string LookAndSay::lookAndSay(int n) {
        string s("1");

        for (int i = 0; i != n; ++i)
            s = nextNumber(s);

        return s;
    }

    bool LookAndSay::test() {
        if (lookAndSay(5) != "312211") {
            cout << "Should be " << "312211" << endl;
            cout << "result " << lookAndSay(5) << endl;
        }

        return true;
    }

  } // chapter7
} // epi

