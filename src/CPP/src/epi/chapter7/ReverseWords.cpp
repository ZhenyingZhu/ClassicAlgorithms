#include "ReverseWords.hpp"

#include <string>
#include <algorithm>
#include <iostream>

using std::string;
using std::find;
using std::reverse;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter7 {
    void ReverseWords::reverseWords(string &s) {
        string::iterator start = s.begin(), end = find(s.begin(), s.end(), ' ');

        while (end != s.end()) {
            reverse(start, end);
            start = end + 1;
            end = find(start, s.end(), ' ');
        }
        reverse(start, end);

        reverse(s.begin(), s.end());
    }

    bool ReverseWords::test() {
        string s = "Alice likes Bob ";
        reverseWords(s);
        if (s != " Bob likes Alice") {
            cout << s << endl;
            return false;
        }

        return true;
    }

  } // chapter7
} // epi
