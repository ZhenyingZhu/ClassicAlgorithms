/*
 * [Source] https://leetcode.com/problems/design-phone-directory/
 * [Difficulty]: Medium
 * [Tag]: Linked List
 * [Tag]: Design
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// [Solution]: Use a release set to store released numbers, and a used set to count used numbers. Those sets are implement as vector, since unordered set needs compute extra hash function
// [Corner Case]:
class PhoneDirectory {
public:
    /**
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        available.reserve(maxNumbers);
        for (int i = maxNumbers - 1; i >= 0; --i) {
            available.push_back(i);
        }
        used.resize(maxNumbers, false);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int candidate = -1;
        if (!available.empty()) {
            candidate = available.back();
            available.pop_back();
        }
        if (candidate != -1)
            used[candidate] = true;
        return candidate;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return !used[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (!used[number])
            return;

        used[number] = false;
        available.push_back(number);
    }

    vector<int> used;
    vector<int> available;
};

class Solution {
public:
    void test() {
        PhoneDirectory pd(3);
        cout << pd.get() << endl;
        cout << pd.get() << endl;
        cout << pd.check(2) << endl;
        cout << pd.get() << endl;
        cout << pd.check(2) << endl;
        pd.release(2);
        cout << pd.check(2) << endl;
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
