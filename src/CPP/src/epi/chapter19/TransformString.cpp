#include "TransformString.hpp"

#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::string;
using std::unordered_set;
using std::queue;
using std::ostream;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter19 {
    int TransformString::transformString(unordered_set<string> dict, const string &s, const string &t) {
        assert(s.size() == t.size());

        struct StringDist {
            string s;
            int distance;
        };

        queue<StringDist> queue;
        queue.push({s, 0});
        dict.erase(s);

        while (!queue.empty()) {
            StringDist &cur = queue.front();
            string str = cur.s;
            if (str == t)
                return cur.distance;

            for (size_t i = 0; i != str.size(); ++i) {
                for (size_t j = 0; j != 26; ++j) {
                    str[i] = 'a' + j;
                    if (dict.find(str) != dict.end()) {
                        dict.erase(str);
                        queue.push({str, cur.distance + 1});
                    }
                }
                str[i] = cur.s[i];
            }

            queue.pop();
        }

        return -1;
    }

    bool TransformString::test() {
        vector<string> strings = {"bat", "cot","dog","dag","dot","cat"};
        unordered_set<string> dict(strings.begin(), strings.end());

        int res = transformString(dict, "cat", "dog");
        if (res != 3) {
            cout << "Should be: 3" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter19
} // epi
