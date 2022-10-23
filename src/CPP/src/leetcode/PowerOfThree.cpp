/*
 * [Source] https://leetcode.com/problems/power-of-three/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>
#include <cmath>

using namespace std;

// [Solution]: Recursively divide 3
// [Corner Case]:
class SolutionIterative {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;

        while (n > 1) {
            if (n % 3 != 0)
                return false;
            n /= 3;
        }
        return true;
    }
};

// [Solution]: Math, use log2(A)/log2(B)=logA(B). Notice log result has round off error and need call round
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1)
            return false;

        int a = round(log(n) / log(3)); // without round, round off error make 5 becomes 4
        cout << a << endl;
        cout << pow(3, a) << endl;
        return pow( 3, round(log(n) / log(3)) ) == n;
    }
};


int main() {
    Solution sol;

    int num = 1;
    for (int i = 1; i < 10; ++i) {
        cout << num << " " << sol.isPowerOfThree(num) << endl;
        num *= 3;
    }

    return 0;
}
