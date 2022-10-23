#include "StackByHeap.hpp"

#include <vector>
#include <queue>
#include <string>
#include <functional>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::vector;
using std::priority_queue;
using std::function;
using std::length_error;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter11 {
    class StackByHeap::Stack {
    public:
        void push(int val) {
            maxHeap_.push({timestamp_++, val});
        }

        int top() const {
            if (maxHeap_.empty())
                throw length_error("stack empty");

            return maxHeap_.top().value;
        }

        int pop() {
            if (maxHeap_.empty())
                throw length_error("stack empty");

            TimestampValue tmp = maxHeap_.top();
            maxHeap_.pop();
            return tmp.value;
        }

        bool empty() const {
            return maxHeap_.empty();
        }

    private:
        struct TimestampValue {
            size_t timestamp;
            int value;

            bool operator<(const TimestampValue &that) const {
                return timestamp < that.timestamp;
            }
        };

        size_t timestamp_ = 0;
        priority_queue<TimestampValue, vector<TimestampValue>> maxHeap_;
    };

    bool StackByHeap::test() {
        vector<int> input = {1, 2, 3, 4, 5};
        Stack s;
        for (int i : input) {
            s.push(i);
        }

        vector<int> ans = {5, 4, 3, 2, 1};
        vector<int> res;
        while (!s.empty()) {
            res.push_back(s.pop());
        }

        if (ans != res) {
            cout << "Should be " << vec_to_string(ans) << endl;
            cout << "Result " << vec_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter11
} // epi
