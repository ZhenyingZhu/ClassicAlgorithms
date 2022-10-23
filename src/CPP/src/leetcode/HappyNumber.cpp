/*
 * [Source] https://leetcode.com/problems/happy-number/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 * [Tag]: Math
 */

#include <iostream>
#include <unordered_set>

using namespace std;

// [Solution]: Use a hash set to record showed number, so that we can detect loop
// [Corner Case]:
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> computed;
        while (n != 1) {
            n = computeHappy(n);
            if (computed.find(n) != computed.end())
                return false;
            computed.insert(n);
        }
        return true;
    }

private:
    int computeHappy(int n) {
        int res = 0;
        while (n != 0) {
            int ld = n % 10;
            res += ld * ld;
            n /= 10;
        }
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    for (int i = 1; i <= 100; ++i)
        cout << i << " " << (sol.isHappy(i)?"True":"False") << endl;

    return 0;
}
