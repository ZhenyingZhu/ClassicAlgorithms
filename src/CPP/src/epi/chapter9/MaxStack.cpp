#include "MaxStack.hpp"

#include <stack>
#include <stdexcept>
#include <iostream>
#include <vector>

using std::stack;
using std::length_error;
using std::cout;
using std::endl;
using std::vector;

namespace epi {
  namespace chapter9 {

    int MaxStack::max() const {
        if (elements_.empty())
            throw length_error("Empty stack");
        return maxes_.top();
    }

    bool MaxStack::empty() const {
        return elements_.empty();
    }

    void MaxStack::push(int x) {
        elements_.push(x);
        if (maxes_.empty() || maxes_.top() <= x) {
            maxes_.push(x);
        }
    }

    int MaxStack::pop() {
        if (elements_.empty())
            throw length_error("Empty stack");
        int res = elements_.top();
        elements_.pop();
        if (res == maxes_.top())
            maxes_.pop();
        return res;
    }

    int MaxStack::top() const {
        if (elements_.empty())
            throw length_error("Empty stack");
        return elements_.top();
    }

    bool MaxStack::test() {
        this->push(1);
        this->push(2);
        this->push(2);
        this->push(3);
        this->push(2);

        vector<int> res = {3, 2, 3, 3, 2, 2, 2, 2, 1, 1};

        for (size_t i = 0; i != 5; ++i) {
            if (this->max() != res[i * 2]) {
                cout << "Max should be: " << res[i * 2] << endl;
                cout << "Result is: " << this->max() << endl;
                return false;
            }

            if (this->top() != res[i * 2 + 1]) {
                cout << "Top should be: " << res[i * 2 + 1] << endl;
                cout << "Result is: " << this->max() << endl;
                return false;
            }

            this->pop();
        }

        return true;
    }

  } // chapter9
} // epi
