#include "FindSmallestSubarrayCoveringSet.hpp"

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
    struct FindSmallestSubarrayCoveringSet::Subarray {
        int st, ed;

        bool operator==(const Subarray &that) const {
            return st == that.st && ed == that.ed;
        }

        bool operator!=(const Subarray &that) const {
            return !(*this == that);
        }
};

    std::ostream& operator<<(std::ostream &os, const FindSmallestSubarrayCoveringSet::Subarray &subarray) {
        os << subarray.st << " " << subarray.ed;

        return os;
    }

    FindSmallestSubarrayCoveringSet::Subarray FindSmallestSubarrayCoveringSet::findSmallestSetMovingWindow
            (const vector<string> &paragraph, const unordered_set<string> &keywords) {
        unordered_map<string, int> keywordsRequiredNum;
        for (string keyword : keywords) {
            ++keywordsRequiredNum[keyword];
        }

        int remainWordsCnt = keywords.size();
        Subarray res{0, (int)paragraph.size()};

        for (int left = 0, right = 0; right != (int)paragraph.size(); ++right) {
            string cur = paragraph[right];
            if (keywords.count(cur) && --keywordsRequiredNum[cur] >= 0) {
                --remainWordsCnt;
            }

            while (remainWordsCnt == 0) {
                if (right - left < res.ed - res.st) {
                    res.st = left;
                    res.ed = right;
                }

                // make left always point to the start of the sub array that doesn't cover
                string start = paragraph[left];
                if (keywords.count(start) && ++keywordsRequiredNum[start] > 0) {
                    ++remainWordsCnt;
                }

                ++left;
            }
        }

        if (res.ed == (int)paragraph.size())
            throw runtime_error("Cannot find a subarray");

        return res;
    }

    FindSmallestSubarrayCoveringSet::Subarray FindSmallestSubarrayCoveringSet::findSmallestSetLinkedList
            (istringstream *sin, const unordered_set<string> &queryStrings) {
        list<int> loc;

        unordered_map<string, list<int>::iterator> stringLoc;
        for (string query : queryStrings) {
            stringLoc.emplace(query, loc.end());
        }

        Subarray res{0, -1};

        int idx = 0;
        string s;
        while (*sin >> s) {
            auto iter = stringLoc.find(s);
            if (iter != stringLoc.end()) {
                if (iter->second != loc.end()) {
                    loc.erase(iter->second);
                }

                loc.push_back(idx);
                iter->second = --loc.end();

                if (loc.size() == queryStrings.size()) {
                    if (res.ed == -1 || idx - loc.front() < res.ed - res.st) {
                        res = {loc.front(), loc.back()};
                    }
                }
            }

            ++idx;
        }

        return res;
    }

    bool FindSmallestSubarrayCoveringSet::test() {
        unordered_set<string> keys( {"banana", "cat"} );

        vector<string> paragraph = {
                "apple", "banana", "apple", "apple", "dog", "cat", "apple", "dog", "banana", "apple", "cat", "dog"
        };

        string input = "apple banana apple apple dog cat apple dog banana apple cat dog";
        istringstream ss(input);

        Subarray res1 = findSmallestSetMovingWindow(paragraph, keys);
        Subarray res2 = findSmallestSetLinkedList(&ss, keys);
        Subarray ans{8, 10};

        if (res1 != ans) {
            cout << "Should be " << ans << endl;
            cout << "Result1 " << res1 << endl;
            return false;
        }

        if (res2 != ans) {
            cout << "Should be " << ans << endl;
            cout << "Result2 " << res2 << endl;
            return false;
        }

        return true;
    }

  } // chapter13
} // epi
