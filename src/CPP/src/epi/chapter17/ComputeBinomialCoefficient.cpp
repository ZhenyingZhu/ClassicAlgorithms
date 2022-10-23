#include "ComputeBinomialCoefficient.hpp"

#include <unordered_map>
#include <utility>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::unordered_map;
using std::pair;
using std::hash;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter17 {
    struct ComputeBinomialCoefficient::PairHash {
        size_t operator() (const pair<int, int> &intPair) const {
            return hash<int>()(intPair.first) ^ hash<int>()(intPair.second);
        }
    };

    int ComputeBinomialCoefficient::coefficientHelper(int n, int k, unordered_map<pair<int, int>, int, PairHash> &map) {
        assert(n >= 1 && n >= k);

        if (k == 0 || k == n)
            return 1;

        pair<int, int> intPair{n, k};

        unordered_map<pair<int, int>, int, PairHash>::const_iterator it = map.find(intPair);
        if (it != map.end())
            return it->second;

        int firstPart = coefficientHelper(n - 1, k, map);
        int secondPart = coefficientHelper(n - 1, k - 1, map);
        int res = firstPart + secondPart;

        map.emplace(intPair, res);
        return res;
    }

    int ComputeBinomialCoefficient::computeBinomialCoefficient(int n, int k) {
        unordered_map<pair<int, int>, int, PairHash> map;
        return coefficientHelper(n, k, map);
    }

    bool ComputeBinomialCoefficient::test() {
        size_t res = computeBinomialCoefficient(5, 2);

        if (res != 10) {
            cout << "Should be: 10" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter17
} // epi
