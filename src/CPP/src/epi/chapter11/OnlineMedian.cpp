#include "OnlineMedian.hpp"

#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <cmath>
#include <functional>
#include <iterator>
#include <iostream>
#include <ostream>
#include <array>
#include "../../MyUtils.h"

using std::vector;
using std::priority_queue;
using std::greater;
using std::istringstream;
using std::stringstream;
using std::string;
using std::sqrt;
using std::getline;
using std::array;
using std::stod;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter11 {
    vector<float> OnlineMedian::onlineMedian(istringstream *sequence) {
        vector<float> res;

        priority_queue<int, vector<int>> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int num;
        while (*sequence >> num) {
            if (maxHeap.empty() || num < maxHeap.top()) {
                maxHeap.push(num);
            } else if (!minHeap.empty() && num < minHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            if (maxHeap.size() < minHeap.size()) {
                int tmp = minHeap.top();
                minHeap.pop();
                maxHeap.push(tmp);
            } else if (maxHeap.size() > minHeap.size() + 1) {
                int tmp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(tmp);
            }

            if (maxHeap.size() == minHeap.size()) {
                res.push_back(static_cast<float>(maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                res.push_back(static_cast<float>(maxHeap.top()));
            }
        }

        return res;
    }

    bool OnlineMedian::test() {
        string input("1 0 3 5 2 0 1");
        istringstream *iss = new istringstream(input);

        vector<float> ans = {1.0, 0.5, 1.0, 2.0, 2.0, 1.5, 1.0};
        vector<float> res = onlineMedian(iss);

        if (ans != res) {
            cout << "Should be " << vec_to_string(ans) << endl;
            cout << "Result " << vec_to_string(res) << endl;
            return false;
        }

        delete iss;

        return true;
    }

  } // chapter11
} // epi
