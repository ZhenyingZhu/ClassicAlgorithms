#include "GenerateBalancedParentheses.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <cassert>

using std::vector;
using std::string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter16 {
    void GenerateBalancedParentheses::parenthesesHelper(size_t left, size_t right, const string &prefix, vector<string> &result) {
        if (left == 0 && right == 0) {
            result.push_back(prefix);
            return;
        }

        if (left > 0)
            parenthesesHelper(left - 1, right, prefix + "(", result);

        if (right > left)
            parenthesesHelper(left, right - 1, prefix + ")", result);
    }

    vector<string> GenerateBalancedParentheses::generateBalancedParentheses(size_t k) {
        vector<string> res;
        string prev = "";
        parenthesesHelper(k, k, prev, res);

        return res;
    }

    bool GenerateBalancedParentheses::test() {
        vector<string> res = generateBalancedParentheses(3);

        if (res.size() != 5) {
            cout << "Wrong number of results" << endl;
            for (string str : res) {
                cout << string(str) << endl;
            }

            return false;
        }

        return true;
    }

  } // chapter16
} // epi
