/*
 * [Source] https://leetcode.com/problems/peeking-iterator/
 * [Difficulty]: Medium
 * [Tag]: Design
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


// [Solution]:
// [Corner Case]:
class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        peeked_ = false;
        next_ = INT_MAX;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (peeked_)
            return next_;

        if (!hasNext()) // cannot use Iterator::hasNext() because might peek twice
            return INT_MAX;

        next_ = Iterator::next();
        peeked_ = true;
        return next_;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (peeked_) {
            peeked_ = false;
            return next_;
        }
        return Iterator::next();
    }

    bool hasNext() const {
        if (peeked_)
            return true;

        return Iterator::hasNext();
    }

private:
    bool peeked_;
    int next_;
};

class Solution {
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
