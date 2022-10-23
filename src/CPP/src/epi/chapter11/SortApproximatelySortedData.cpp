#include "SortApproximatelySortedData.hpp"

#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <functional>
#include <iterator>
#include <iostream>

#include "../../MyUtils.h"

using std::vector;
using std::priority_queue;
using std::greater;
using std::istringstream;
using std::string;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter11 {
    vector<int> SortApproximatelySortedData::sortApproximatelySortedData(istringstream *sequence, size_t k) {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int num;
        while (*sequence >> num) {
            if (minHeap.size() == k) {
                res.push_back(minHeap.top());
                minHeap.pop();
            }
            minHeap.push(num);
        }

        while (!minHeap.empty()) {
            res.push_back(minHeap.top());
            minHeap.pop();
        }

        return res;
    }

    bool SortApproximatelySortedData::test() {
        string input("3 -1 2 6 4 5 8");
        istringstream *iss = new istringstream(input);

        vector<int> ans = {-1, 2, 3, 4, 5, 6, 8};
        vector<int> res = sortApproximatelySortedData(iss, 2);
        if (res != ans) {
            cout << "Should be " << vec_to_string(ans) << endl;
            cout << "Result " << vec_to_string(res) << endl;
            return false;
        }

        delete iss;

        return true;
    }

  } // chapter11
} // epi
