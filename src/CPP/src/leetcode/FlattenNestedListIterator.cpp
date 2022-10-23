/*
 * [Source] https://leetcode.com/problems/flatten-nested-list-iterator/
 * [Difficulty]: Medium
 * [Tag]: Stack
 * [Tag]: Design
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// This is the interface that allows for creating nested lists.
class NestedInteger {
  public:
    NestedInteger();
    NestedInteger(vector<NestedInteger>&);
    NestedInteger(int);
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;

    bool isInt;
    int num;
    vector<NestedInteger> &vec;
};

vector<NestedInteger> tmp = {};

NestedInteger::NestedInteger(): vec(tmp), isInt(false) { }

NestedInteger::NestedInteger(vector<NestedInteger> &nums): vec(nums), isInt(false) { }

NestedInteger::NestedInteger(int n): num(n), isInt(true), vec(tmp) { }

// Return true if this NestedInteger holds a single integer, rather than a nested list.
bool NestedInteger::isInteger() const {
    return isInt;
}

// Return the single integer that this NestedInteger holds, if it holds a single integer
// The result is undefined if this NestedInteger holds a nested list
int NestedInteger::getInteger() const {
    return num;
}

// Return the nested list that this NestedInteger holds, if it holds a nested list
// The result is undefined if this NestedInteger holds a single integer
const vector<NestedInteger> &NestedInteger::getList() const {
    return vec;
}


// [Solution]: Never thought it is so complicate!!!! basiclly use a vector to store nest indexes, and make sure the last index always points to an integer
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if (!nestedList.empty()) {
            indexes.push_back( NestedIntegerIdx(nestedList) );
            validIndexes();
        }
    }

    int next() {
        NestedIntegerIdx &last = indexes.back();
        int res = last.nest[last.idx].getInteger();

        ++last.idx;
        validIndexes();

        return res;
    }

    bool hasNext() {
        return !indexes.empty();
    }

private:
    struct NestedIntegerIdx {
        NestedIntegerIdx(const vector<NestedInteger> &nestedList) : nest(nestedList), idx(0) { }

        const vector<NestedInteger> &nest;
        int idx = 0;
    };

    void validIndexes() {
        // remove indexes that are reach end
        while (!indexes.empty() && indexes.back().idx == indexes.back().nest.size()) {
            indexes.pop_back();
            if (!indexes.empty())
                ++indexes.back().idx;
        }

        if (indexes.empty())
            return;

        // make sure the last index points to integer
        NestedIntegerIdx &last = indexes.back();
        const NestedInteger &nestedInteger = last.nest[last.idx];
        if (!nestedInteger.isInteger()) {
            const vector<NestedInteger> &vec = nestedInteger.getList();
            // the vector can be empty, so move to the next
            if (vec.empty()) {
                ++last.idx;
            } else {
                indexes.push_back(NestedIntegerIdx(vec));
            }

            validIndexes();
        }
    }

    vector<NestedIntegerIdx> indexes;
};


// [Corner Case]:
class Solution {
public:
    void test() {
        NestedInteger n11(1), n12(1); vector<NestedInteger> vec1 = {n11, n12}; NestedInteger l1(vec1);
        NestedInteger n2(2);
        NestedInteger n31(1), n32(1); vector<NestedInteger> vec3 = {n31, n32}; NestedInteger l3(vec3);
        vector<NestedInteger> nestedList = {l1, n2, l3};

        NestedIterator i(nestedList);
        while (i.hasNext()) cout << i.next() << " ";
        cout << endl;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    sol.test();

    return 0;
}
