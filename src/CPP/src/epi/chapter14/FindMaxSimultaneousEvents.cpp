#include "FindMaxSimultaneousEvents.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "../../MyUtils.h"

using std::vector;
using std::string;
using std::sort;
using std::max;
using std::cout;
using std::endl;
using myutils::vec_to_string;

namespace epi {
  namespace chapter14 {
    struct FindMaxSimultaneousEvents::Event {
        int start, finish;
    };

    struct FindMaxSimultaneousEvents::Endpoint {
        bool operator<(const Endpoint &that) const {
            if (time < that.time)
                return true;

            if (time == that.time)
                return isStart;

            return false;
        }

        int time, isStart;
    };

    int FindMaxSimultaneousEvents::findMaxSimultaneousEvents(const vector<Event> &events) {
        vector<Endpoint> endpoints;

        for (Event event : events) {
            endpoints.push_back({event.start, true});
            endpoints.push_back({event.finish, false});
        }

        sort(endpoints.begin(), endpoints.end());

        int count = 0, maxCnt = 0;
        for (Endpoint endpoint : endpoints) {
            if (endpoint.isStart)
                ++count;
            else
                --count;

            maxCnt = max(maxCnt, count);
        }

        return maxCnt;
    }

    bool FindMaxSimultaneousEvents::test() {
        vector<Event> events = {
                {1, 5},
                {6, 10},
                {11, 13},
                {14, 15},
                {2, 7},
                {8, 9},
                {12, 15},
                {4, 5},
                {9, 17}
        };

        int res = findMaxSimultaneousEvents(events);

        if (res != 3) {
            cout << "Should be 3" << endl;
            cout << "Result " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter14
} // epi
