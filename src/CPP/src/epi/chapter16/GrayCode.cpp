#include "GrayCode.hpp"

#include <vector>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter16 {
    vector<int> GrayCode::grayCode(size_t numBits) {
        if (numBits == 0)
            return {0};

        if (numBits == 1)
            return {0, 1};

        const vector<int> &previous = grayCode(numBits - 1);
        vector<int> res;
        for (vector<int>::const_iterator it = previous.cbegin(); it != previous.cend(); ++it) {
            res.push_back(*it);
        }

        int addition = 1;
        for (size_t i = 1; i != numBits; ++i) { // use 1<<numBits-1 can perform this better
            addition *= 2;
        }
        // use the previous result vector can save some space and some copy, just not from the end of the reverse
        for (vector<int>::const_reverse_iterator it = previous.crbegin(); it != previous.crend(); ++it) {
            res.push_back(addition + *it);
        }

        return res;
    }

    bool GrayCode::test() {
        vector<int> res = grayCode(3);
        vector<int> ans = {0, 1, 3, 2, 6, 7, 5, 4};

        if (res != ans) {
            cout << "Should be: " << vec_to_string(ans) << endl;
            cout << "Result: " << vec_to_string(res) << endl;

            return false;
        }

        return true;
    }

  } // chapter16
} // epi
