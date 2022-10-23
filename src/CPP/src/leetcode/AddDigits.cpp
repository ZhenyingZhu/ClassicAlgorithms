/*
 * [Source] https://leetcode.com/problems/add-digits/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]: every 9 numbers correspond 1~9.
// [Corner Case]:
class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        return num % 9 == 0 ? 9 : num % 9;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
