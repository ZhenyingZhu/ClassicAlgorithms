#include "FindBuplicateMissing.hpp"

#include <vector>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::vector;
using std::invalid_argument;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter12 {
    struct FindBuplicateMissing::DuplicateAndMissing{
             int duplicate, missing;
    };

    FindBuplicateMissing::DuplicateAndMissing FindBuplicateMissing::findBuplicateMissing(vector<int> &vec) {
        int dupXorMissing = 0;
        for (size_t i = 0; i != vec.size(); ++i) {
            dupXorMissing ^= vec[i] ^ i;
        }

        int differentBit = dupXorMissing & ( ~(dupXorMissing - 1) );
        int dupOrMissing = 0;
        for (size_t i = 0; i != vec.size(); ++i) {
            if (vec[i] & differentBit)
                dupOrMissing ^= vec[i];

            if (i & differentBit)
                dupOrMissing ^= i;
        }

        for (size_t i = 0; i != vec.size(); ++i) {
            if (vec[i] == dupOrMissing)
                return {dupOrMissing, dupOrMissing ^ dupXorMissing};
        }

        return {dupOrMissing ^ dupXorMissing, dupOrMissing};
    }

    bool FindBuplicateMissing::test() {
        vector<int> vec = {5,3,0,3,1,2};

        DuplicateAndMissing res = findBuplicateMissing(vec);
        if (res.duplicate != 3) {
            cout << "Duplcated element should be 3" << endl;
            cout << "Result " << res.duplicate << endl;
            return false;
        }

        if (res.missing != 4) {
            cout << "Missing element should be 4" << endl;
            cout << "Result " << res.missing << endl;
            return false;
        }

        return true;
    }

  } // chapter12
} // epi
