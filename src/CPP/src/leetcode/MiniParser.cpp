/*
 * [Source] https://leetcode.com/problems/mini-parser/
 * [Difficulty]: medium
 * [Tag]: Stack
 * [Tag]: String
 */

#include <iostream>
#include <vector>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;

private:
    bool isInt_;
    int num_;
    vector<NestedInteger> list_;
};

NestedInteger::NestedInteger():
    isInt_(false),
    num_(0) { }

NestedInteger::NestedInteger(int value):
    isInt_(true),
    num_(value) { }

bool NestedInteger::isInteger() const {
    return isInt_;
}

int NestedInteger::getInteger() const {
    return num_;
}

void NestedInteger::setInteger(int value) {
    num_ = value;
    isInt_ = true;
}

void NestedInteger::add(const NestedInteger &ni) {
    list_.push_back(ni);
    isInt_ = false;
}

const vector<NestedInteger> &NestedInteger::getList() const {
    return list_;
}

void printNestedInteger(const NestedInteger &ni) {
    if (ni.isInteger()) {
        cout << ni.getInteger() << ", ";
    } else {
        const vector<NestedInteger> &vec = ni.getList();
        cout << "[";
        for (const NestedInteger &subNi : vec) {
            printNestedInteger(subNi);
        }
        cout << "]";
    }
}

// [Solution]: Use function call to act as stack. Use a tempory reference int to keep index increasing
// [Corner Case]:
class Solution {
public:
    NestedInteger deserialize(string s) {
        int idx = 0;
        return deserialize(s, idx);
    }

    NestedInteger deserialize(string &s, int &idx) {
        NestedInteger res;
        if (s[idx] == ']') {
            return res; // empty list
        }
        
        if (s[idx] == '[') {
            ++idx; // skip '['
            while (s[idx] != ']') {
                NestedInteger newNi = deserialize(s, idx);
                res.add(newNi);
                // comma between NIs
                if (idx < (int)s.length() && s[idx] == ',')
                    ++idx; // the last ','
            }
            ++idx; // the last ']'
            return res;
        }

        int value = 0;
        bool negative = false;
        if (s[idx] == '-') {
            ++idx;
            negative = true;
        }

        while (idx < (int)s.length() && isdigit(s[idx])) {
            value = value * 10 + s[idx++] - '0';
        }
        res.setInteger(negative ? -value : value);
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //NestedInteger ni = sol.deserialize("[123,[456,[-789]]]");
    NestedInteger ni = sol.deserialize("[123,456,[788,799,833],[[]],10,[]]");
    printNestedInteger(ni);
    cout << endl;

    return 0;
}
