#include "MinimumMessiness.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::string;
using std::min;
using std::max;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter17 {
    int MinimumMessiness::minimumMessiness(const vector<string> &words, int lineLength) {
        vector<int> messinesses(words.size() + 1, 0);

        for (size_t wordNum = 1; wordNum <= words.size(); ++wordNum) {
            assert((int)words[wordNum-1].size() <= lineLength);

            messinesses[wordNum] = lineLength * lineLength;
            int currentLen = 0;
            bool firstWord = true;
            for (int idx = wordNum - 1; idx >= 0; --idx) {
                currentLen += words[idx].size();
                if (firstWord)
                    firstWord = false;
                else
                    ++currentLen;

                if (currentLen > lineLength)
                    break;

                int messiness = (lineLength - currentLen) * (lineLength - currentLen) + messinesses[idx];
                messinesses[wordNum] = min(messinesses[wordNum], messiness);
            }
        }

        return messinesses[words.size()];
    }

    bool MinimumMessiness::test() {
        vector<string> words = {"aaa", "bbb", "c", "d", "ee", "ff", "ggggggg"};

        int res = minimumMessiness(words, 11);

        if ( res != 36 ) {
            cout << "Should be: 36" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter17
} // epi
