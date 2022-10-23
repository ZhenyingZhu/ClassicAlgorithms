#include "TopK.hpp"

#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <iostream>

using std::priority_queue;
using std::vector;
using std::istringstream;
using std::string;
using std::function;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter11 {
    vector<string> TopK::topK(size_t k, istringstream *stream) {
        priority_queue<string, vector<string>, function<bool(string, string)>> minHeap
                ( [](const string &a, const string &b) -> bool {return a.size() >= b.size();} ); // a lambda
        string nextString;
        while (*stream >> nextString) {
            minHeap.push(nextString);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<string> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        return res;
    }

    bool TopK::test() {
        string input("a b c d e aa bb");
        istringstream *iss = new istringstream(input);
        vector<string> res = topK(5, iss);

        for (string s : res) {
            cout << s << endl;
        }

        return true;
    }

  } // chapter11
} // epi
