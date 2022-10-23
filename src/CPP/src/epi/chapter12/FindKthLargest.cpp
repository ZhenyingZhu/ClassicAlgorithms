#include "FindKthLargest.hpp"

#include <vector>
#include <functional>
#include <utility>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::vector;
using std::greater;
using std::invalid_argument;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter12 {
    int FindKthLargest::findKthLargest(vector<int> &vec, int k) {
        if (k <= 0 || k > (int)vec.size())
            throw invalid_argument("k out of range");

        return findKthHelper(0, vec.size() - 1, vec, k, greater<int>());
    }

    bool FindKthLargest::test() {
        vector<int> ans = {5,4,3,2,2,1};

        for (size_t i = 0; i != ans.size(); ++i) {
            vector<int> vec = {3,2,5,1,2,4};
            int res = findKthLargest(vec, i + 1);
            if (res != ans[i]) {
                cout << i + 1 << "th largest element should be " << ans[i] << endl;
                cout << "result " << res << endl;
                return false;
            }
        }

        return true;
    }

  } // chapter12
} // epi
