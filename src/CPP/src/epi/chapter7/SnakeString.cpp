#include "SnakeString.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

namespace epi {
  namespace chapter7 {
    string SnakeString::snakeString(const string &s) {
        string res(s.size(), ' ');

        size_t pos(0);
        for (size_t upper = 1; upper < s.size(); upper += 4)
            res[pos++] = s[upper];

        for (size_t mid = 0; mid < s.size(); mid += 2)
            res[pos++] = s[mid];

        for (size_t lower = 3; lower < s.size(); lower += 4)
            res[pos++] = s[lower];

        return res;
    }

    bool SnakeString::test() {
        string s("Hello World!");

        if (snakeString(s) != "e lHloWrdlo!") {
            cout << "Should be: 'e lHloWrdlo!'" << endl;
            cout << "Result '" << snakeString(s) << "'" << endl;
            return false;
        }

        return true;
    }

  } // chapter7
} // epi
