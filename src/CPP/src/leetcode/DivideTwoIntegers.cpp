/*
 * [Source] https://leetcode.com/problems/divide-two-integers/
 * [Difficulty]: Medium
 * [Tag]: Math
 * [Tag]: Binary Search
 */

#include <iostream>

using namespace std;

// [Solution]: Double the divisor by shift left until it is larger than dividend. Then minus and shift.
// [Corner Case]: divisor shift left leads to overflow, divisor is 0 or negative. abs fail for MIN_INT
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/DivideTwoIntegers.java
 */

/* Java solution
public class Solution {
    public int divide(int dividend, int divisor) { // dividend / divisor
        if(divisor == 0) {
            return Integer.MAX_VALUE; 
        }
        int result = 0; 
        if(dividend == Integer.MIN_VALUE) {
            result = 1; 
            dividend += Math.abs(divisor); // First minus one to avoid leak. 
        }
        if(divisor == Integer.MIN_VALUE) {
            return result; 
        }
        boolean negative = ((dividend ^ divisor) >>> 31 == 1) ? true : false; 
        dividend = Math.abs(dividend); 
        divisor = Math.abs(divisor); 
        int bitPos = 0; 
        while((dividend >> 1) >= divisor) {
            ++bitPos; 
            divisor <<= 1; // If dividend is not leak, divisor wont 
        }
        while(bitPos >= 0) { 
            if(dividend >= divisor) {
                dividend -= divisor; 
                result += 1 << bitPos; 
            }
            if(dividend == 0) {
                return negative ? -result : result; 
            }
            divisor >>= 1; 
            --bitPos; 
        }
        return negative ? -result : result; 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
