/*
 * [Source] https://leetcode.com/problems/palindrome-number/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]: Convert to string, then check.
// [Corner Case]: Negative number
class Solution {
};

// [Solution]: First count the number of digits n. Then compare x/10^n with x%10. Then x=x%100/10, n-=2. If n == 0 or n == 1, return true.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/PalindromeNumber.java
 */

/* Java solution
public class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false; 
        }
        int high = 1; 
        while (x / high >= 10) {
            high *= 10; 
        }
        while (high > 1) {
            if (x % 10 != (x / high) % 10) {
                return false; 
            }
            high /= 100;
            x /= 10; 
        }
        return true; 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
