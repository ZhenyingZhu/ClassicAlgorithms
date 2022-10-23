#include "FindAmpleCity.hpp"

#include <vector>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter18 {
    size_t FindAmpleCity::findAmpleCity(const vector<int> &gallons, const vector<int> &distances) {
        assert(!gallons.empty() && gallons.size() == distances.size());

        size_t ampleIdx = 0;
        int canRunMiles = gallons[0] * kMPG - distances[0];
        for (size_t idx = 1; idx != gallons.size(); ++idx) {
            if (canRunMiles < 0) {
                ampleIdx = idx;
                canRunMiles = 0;
            }

            canRunMiles += gallons[idx] * kMPG - distances[idx];
        }

        return ampleIdx;
    }

    bool FindAmpleCity::test() {
        vector<int> gallons = {50, 20, 5, 30, 25, 10, 10};
        vector<int> distances = {900, 600, 200, 400, 600, 200, 100};

        size_t res = findAmpleCity(gallons, distances);
        if (res != 3) {
            cout << "Should be: 3" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter18
} // epi
