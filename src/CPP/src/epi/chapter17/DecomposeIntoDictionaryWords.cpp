#include "DecomposeIntoDictionaryWords.hpp"

#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::string;
using std::unordered_set;
using std::reverse;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter17 {
    vector<string> DecomposeIntoDictionaryWords::decomposeIntoDictionaryWords(const string &domain,
            const unordered_set<string> &dictionary) {
        vector<int> substringLength(domain.size() + 1, -1);
        substringLength[0] = 0;

        for (int ed = 0; ed != (int)domain.size(); ++ed) {
            for (int st = ed; st >= 0; --st) {
                if (substringLength[st] != -1 &&
                        dictionary.find( domain.substr(st, ed + 1 - st) ) != dictionary.cend()) {
                    substringLength[ed + 1] = ed + 1 - st;
                    break;
                }
            }
        }

        vector<string> res;
        if (substringLength[domain.size()] != -1) {
            int idx = domain.size();
            while (idx != 0) {
                int currentLen = substringLength[idx]; // idx == ed + 1
                res.push_back( domain.substr(idx - currentLen, currentLen) );
                idx -= currentLen;
            }

            reverse(res.begin(), res.end());
        }

        return res;
    }

    bool DecomposeIntoDictionaryWords::test() {
        vector<string> dicVec = {"a", "man", "a", "plan", "a", "canal"};
        unordered_set<string> dic(dicVec.begin(), dicVec.end());

        string input("amanaplanacanal");

        vector<string> res = decomposeIntoDictionaryWords(input, dic);

        if ( res.size() != 6 ) {
            cout << "Wrong number of results" << endl;
            for (string s : res) {
                cout << s << endl;
            }

            return false;
        }

        return true;
    }

  } // chapter17
} // epi
