#include "StackQueue.hpp"

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "../../MyUtils.h"

using std::stack;
using std::length_error;
using std::invalid_argument;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter9 {
    class StackQueue::Queue {
    public:
        void enqueue(int x) {
            enq_.push(x);
        }

        int dequeue() {
            if (deq_.empty()) {
                if (enq_.empty())
                    throw length_error("Empty queue");

                while (!enq_.empty()) {
                    deq_.push(enq_.top());
                    enq_.pop();
                }
            }

            int ele = deq_.top();
            deq_.pop();
            return ele;
        }

    private:
        std::stack<int> enq_, deq_;
    };

    bool StackQueue::test() {
        Queue q;
        int res;

        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);

        for (int i = 1; i != 3; ++i) {
            res = q.dequeue();
            if (res != i) {
                cout << "Should be: " << i << endl;
                cout << "Result: " << res << endl;
                return false;
            }
        }

        q.enqueue(5);
        q.enqueue(6);

        for (int i = 3; i != 7; ++i) {
            try {
                res = q.dequeue();
            } catch (length_error &ex) {
                cout << ex.what() << endl;
                continue;
            }
            if (res != i) {
                cout << "Should be: " << i << endl;
                cout << "Result: " << res << endl;
                return false;
            }
        }

        try {
            q.dequeue();
        } catch (length_error &ex) {
            cout << ex.what() << endl;
        }

        return true;
    }

  } // chapter9
} // epi
