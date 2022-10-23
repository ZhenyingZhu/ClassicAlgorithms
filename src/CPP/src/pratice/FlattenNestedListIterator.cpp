#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class NestedInteger {
public:
    NestedInteger() {
        isVal = false;
    }

    NestedInteger(int x) {
        isVal = true;
        val = x;
    }

    void setList(vector<NestedInteger> &vec) {
        swap(vec, list);
    }

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return isVal;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        return val;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return list;
    }

private:
    int val;
    vector<NestedInteger> list;
    bool isVal;
};

// [Source]: https://leetcode.com/problems/flatten-nested-list-iterator/
// http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=212481 

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        iterators.push(nestedList.cbegin());
        ends.push(nestedList.cend());
        valid();
    }

    int next() {
        if (!hasNext())
            return INT_MAX;

        int val = iterators.top()->getInteger();
        ++iterators.top();
        valid();
        return val;
    }

    bool hasNext() {
        return !iterators.empty();
    }

private:
    void valid() {
        if (iterators.empty())
            return;

        if (iterators.top() == ends.top()) {
            iterators.pop();
            ends.pop();
            if (!iterators.empty()) {
                ++iterators.top();
            }
            valid();
            return;
        }

        if (iterators.top()->isInteger())
            return;

        const vector<NestedInteger> &list = iterators.top()->getList();
        if (list.empty()) { // skip this NestedInteger
            ++iterators.top();
            valid();
            return;
        }

        iterators.push(list.cbegin());
        ends.push(list.cend());
        valid();
    }

    stack<vector<NestedInteger>::const_iterator> iterators;
    stack<vector<NestedInteger>::const_iterator> ends;
};

int main() {
    NestedInteger nl11(1), nl12(1), nl1;
    vector<NestedInteger> v1 = {nl11, nl12};
    nl1.setList(v1);

    NestedInteger ni2(2);

    NestedInteger nl31(1), nl32(1), nl3;
    vector<NestedInteger> v3 = {nl31, nl32};
    nl3.setList(v3);

    vector<NestedInteger> vec = {nl1,ni2,nl3};

    NestedIterator it(vec);
    while (it.hasNext())
        cout << it.next() << " ";
    cout << endl;
}
