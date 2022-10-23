#include "MostFrequentQueries.hpp"

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
using std::runtime_error;
using std::vector;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter13 {
    vector<string> MostFrequentQueries::mostFrequentQueries(const vector<string> &queries, size_t k) {
        unordered_map<string, size_t> queryFreq;
        for (string query : queries) {
            ++queryFreq[query];
        }

        priority_queue< QueryFreq, vector<QueryFreq>, function<bool(QueryFreq, QueryFreq)> > minHeap
                ( [](const QueryFreq &a, const QueryFreq &b) -> bool {return a.freq > b.freq;} );

        for (const auto &pair : queryFreq) {
            if (minHeap.size() == k) // check first, otherwise the size would be k-1
                minHeap.pop();
            minHeap.push({pair.first, pair.second});
        }

        vector<string> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().query);
            minHeap.pop();
        }
        return res;
    }

    bool MostFrequentQueries::test() {
        vector<string> queries = {"a", "a", "a", "b", "b", "c"};
        vector<string> ans = {"b", "a"};
        vector<string> res = mostFrequentQueries(queries, 2);

        if (res != ans) {
            for (string ress : res) {
                cout << ress << " ";
            }
            cout << endl;
            return false;
        }

        return true;
    }

  } // chapter13
} // epi
