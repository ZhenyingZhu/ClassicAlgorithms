// [Source]: http://www.1point3acres.com/bbs/thread-218797-1-1.html
// https://leetcode.com/problems/peeking-iterator/


// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
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


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        peeked = false;
        num = INT_MAX;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (peeked) {
            return num;
        }

        if (hasNext()) {
            peeked = true;
            num = Iterator::next();
            return num;
        }

        peeked = false;
        return INT_MAX;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (!hasNext())
            return INT_MAX;
        if (peeked) {
            peeked = false;
            return num;
        }
        return Iterator::next();
    }

    bool hasNext() const {
        if (peeked)
            return true;
        return Iterator::hasNext();
    }

private:
    int num;
    bool peeked;
};


// [Solution]: Another solution is always store the next element and a bool saying if it is done
