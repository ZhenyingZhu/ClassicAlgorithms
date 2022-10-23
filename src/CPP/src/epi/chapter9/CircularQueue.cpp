#include "CircularQueue.hpp"

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "../../MyUtils.h"

using std::vector;
using std::rotate;
using std::length_error;
using std::invalid_argument;
using std::cout;
using std::endl;
using myutils::vec_to_string;

namespace epi {
  namespace chapter9 {
    class CircularQueue::Queue {
    public:
        explicit Queue(size_t capacity) : entries_(capacity) { }

        size_t size() const {
            return size_;
        }

        void enqueue(int x) {
            if (size() == entries_.size()) {
                rotate(entries_.begin(), entries_.begin() + head_, entries_.end());
                entries_.resize(kScaleFactor * entries_.size());
                head_ = 0;
                tail_ = size();
            }

            entries_[tail_] = x;
            tail_ = (tail_ + 1) % entries_.size();
            ++size_;
        }

        int dequeue() {
            if (size() == 0)
                throw length_error("Empty queue");

            int ele = entries_[head_];
            head_ = (head_ + 1) % entries_.size();
            --size_;
            return ele;
        }

    private:
        const size_t kScaleFactor = 2;
        size_t head_ = 0, tail_ = 0;
        size_t size_ = 0;
        std::vector<int> entries_;
    };

    bool CircularQueue::test() {
        Queue q(3);
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
