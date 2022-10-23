#include <iostream>
#include <cmath>

using namespace std;

// [Source]: https://leetcode.com/problems/sqrtx
// http://www.1point3acres.com/bbs/thread-225081-1-1.html

class Solution {
public:
    int mySqrt(int x) {
        if (x < 0)
            return -1;
        if (x == 0 || x == 1)
            return x;

        long left = 1, right = x / 2;
        while (left + 1 < right) {
            long mid = left + (right  - left) / 2;

            long square = mid * mid;
            if (square == x)
                return mid;
            if (square < x)
                left = mid;
            else
                right = mid;
        }

        if (right * right <= x)
            return right;
        return left;
    }

    double mySqrt(double x) {
        if (x <= 0)
            return 0;

        double delta = 0.001;
        double left = 0, right = x;
        while (left < right) {
            double mid = (left + right) / 2.0;
            double square = mid * mid;
            if (abs(square - x) <= delta)
                return mid;
            if (square < x)
                left = mid;
            else
                right = mid;
        }
        return 0;
    }
};

int main() {
    Solution sol;

    double num = 0.0;
    for (int i = 0; i < 10; ++i) {
        num = i;
        double res = sol.mySqrt(num);
        cout << res << ": " << res * res << endl;
    }

    return 0;
}
