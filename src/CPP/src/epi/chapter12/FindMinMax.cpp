#include "FindMinMax.hpp"

#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::vector;
using std::minmax;
using std::pair;
using std::min;
using std::max;
using std::invalid_argument;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter12 {
    struct FindMinMax::MinMax {
        int min, max;
    };

    FindMinMax::MinMax FindMinMax::findMinMax(const vector<int> &vector) {
        if (vector.size() == 0)
            throw invalid_argument("Empty vector");
        if (vector.size() == 1)
            return {vector.front(), vector.front()};

        pair<int, int> globalMinMax = minmax(vector[0], vector[1]);
        for (int i = 2; i + 1 < (int)vector.size(); ++i) {
            pair<int, int> localMinMax = minmax(vector[i], vector[i + 1]);
            globalMinMax = {
                    min(globalMinMax.first, localMinMax.first),
                    max(globalMinMax.second, localMinMax.second)
            };
        }

        if (vector.size() % 2 == 1) {
            globalMinMax = {
                    min(globalMinMax.first, vector.back()),
                    max(globalMinMax.second, vector.back()),
            };
        }

        return {globalMinMax.first, globalMinMax.second};
    }

    bool FindMinMax::test() {
        vector<int> vector = {3,2,5,1,2,4};
        MinMax res = findMinMax(vector);

        if (res.min != 1) {
            cout << "1 should be the min" << endl;
            cout << "Result " << res.min << endl;
            return false;
        }

        if (res.max != 5) {
            cout << "5 should be the max" << endl;
            cout << "Result " << res.max << endl;
            return false;
        }

        return true;
    }

  } // chapter12
} // epi
