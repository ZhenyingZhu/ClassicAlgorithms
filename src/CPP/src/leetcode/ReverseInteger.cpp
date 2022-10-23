/*
 * [Source] https://leetcode.com/problems/reverse-integer/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>
#include <climits>

using namespace std;

// [Solution]: use negative number mode to negative to deal with it.
// [Corner Case]: The sign; The origin number is not overflow but the converted one can; Origin number is 100;
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int val = x % 10;
            int tmp = res * 10 + val;
            if (tmp / 10 != res) // check if overflow
                return 0;
            res = tmp;
            x /= 10;
        }
        return res;
    }
};

// [Solution]: Convert to string, reverse it, and then reverse back.
// [Solution]: mode the origin number by 10, and multiple the result by 10 and add that mode result. If the result the origin number are different sign, then it is overflow.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/ReverseInteger.java
 */

/* Java solution
public class Solution {
    public int reverse(int x) {
        int num = x; 
        int res = 0; 
        while (num != 0) { // Deal with the negative situation
            res = res * 10 + num % 10; 
            num /= 10; 
        }
        return (x ^ res) >>> 31 == 1 ? -1 : res; // Not necessary
    }
}
 */

int main() {
    Solution sol;

    cout << sol.reverse(100) << endl;
    cout << sol.reverse(-123) << endl;
    cout << sol.reverse(INT_MAX) << endl;

    return 0;
}
