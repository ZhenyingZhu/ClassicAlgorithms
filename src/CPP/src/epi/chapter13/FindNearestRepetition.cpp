#include "FindNearestRepetition.hpp"

#include <string>
#include <unordered_map>
#include <queue>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "../../MyUtils.h"

using std::string;
using std::unordered_map;
using std::priority_queue;
using std::function;
using std::invalid_argument;
using std::vector;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter13 {
    int FindNearestRepetition::findNearestRepetition(const vector<string> &paragraph) {
        if (paragraph.empty())
            throw invalid_argument("Paragraph empty");

        //string res = paragraph[0];
        size_t minDist = paragraph.size(); // The largest distance

        unordered_map<string, size_t> stringPrevIndex;

        for (size_t i = 0; i != paragraph.size(); ++i) {
            string key = paragraph[i];

            unordered_map<string, size_t>::iterator iter = stringPrevIndex.find(key);
            if (iter != stringPrevIndex.end()) {
                size_t dist = i - iter->second;
                if (dist < minDist) {
                    minDist = dist;
                    //res = key;
                }
            }

            stringPrevIndex[key] = i;
        }

        return minDist;
    }

    bool FindNearestRepetition::test() {
        vector<string> paragraph = {
                "All", "work", "and", "no", "play", "makes", "for", "no", "work", "no", "fun", "and", "no", "results"
        };
//        string ans = "no";
//        string res = findNearestRepetition(paragraph);
        int ans = 2;
        int res = findNearestRepetition(paragraph);

        if (res != ans) {
            cout << "Should be " << ans << endl;
            cout << "Result " << res << endl;
            return false;
        }

        return true;
    }

  } // chapter13
} // epi
