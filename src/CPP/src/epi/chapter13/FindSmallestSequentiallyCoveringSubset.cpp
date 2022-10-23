#include "FindSmallestSequentiallyCoveringSubset.hpp"

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <sstream>
#include <queue>
#include <functional>
#include <iostream>
#include <stdexcept>

#include "../../MyUtils.h"

using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::list;
using std::istringstream;
using std::priority_queue;
using std::function;
using std::invalid_argument;
using std::runtime_error;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter13 {
    struct FindSmallestSequentiallyCoveringSubset::Subarray {
        int st, ed;

        bool operator==(const Subarray &that) const {
            return st == that.st && ed == that.ed;
        }

        bool operator!=(const Subarray &that) const {
            return !(*this == that);
        }
};

    std::ostream& operator<<(std::ostream &os, const FindSmallestSequentiallyCoveringSubset::Subarray &subarray) {
        os << subarray.st << " " << subarray.ed;

        return os;
    }

    FindSmallestSequentiallyCoveringSubset::Subarray FindSmallestSequentiallyCoveringSubset::findSmallestSequentiallyCoveringSubset
            (const vector<string> &paragraph, const vector<string> &keywords) {
        unordered_map<string, size_t> keywordIdx;
        for (size_t i = 0; i != keywords.size(); ++i) {
            keywordIdx.insert({keywords[i], i});
        }

        vector<int> lastOccurance(keywords.size(), -1);
        vector<int> shortestLen(keywords.size(), -1);

        Subarray res{0, (int)paragraph.size()};
        for (int i = 0; i != (int)paragraph.size(); ++i) {
            auto iter = keywordIdx.find(paragraph[i]);
            if (iter != keywordIdx.end()) {
                size_t idx = iter->second;

                if (idx == 0) {
                    shortestLen[0] = 1;
                    lastOccurance[0] = i;
                } else if (lastOccurance[idx - 1] != -1) { // means previous keyword shows
                    shortestLen[idx] = i - lastOccurance[idx - 1] + shortestLen[idx - 1];
                    lastOccurance[idx] = i;
                }

                if (idx == keywords.size() - 1 && shortestLen[idx] != -1) {
                    if (shortestLen.back() < res.ed - res.st) {
                        res = {lastOccurance.front(), lastOccurance.back()};
                    }
                }

            } // end if
        } // end for

        return res;
    }

    bool FindSmallestSequentiallyCoveringSubset::test() {
        vector<string> paragraph = {
                "apple", "banana", "cat", "apple"
        };

        vector<string> keywords = {"banana", "apple"};


        Subarray res = findSmallestSequentiallyCoveringSubset(paragraph, keywords);
        Subarray ans{1, 3};

        if (res != ans) {
            cout << "Should be " << ans << endl;
            cout << "Result1 " << res << endl;
            return false;
        }

        return true;
    }

  } // chapter13
} // epi
