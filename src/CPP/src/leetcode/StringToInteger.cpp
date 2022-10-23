/*
 * [Source] https://leetcode.com/problems/string-to-integer-atoi/
 * [Difficulty]: Easy
 * [Tag]: Math
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Work backwards. So that if the number is overflowed, we can know it in advance.
// [Corner Case]: sign, overflow, white spaces at the begining, special characters.
class Solution {
};

// [Solution]: Work frontwards. If the previous value is larger than max_int / 10, it means overflow. If it equals max_int / 10, need consider the last digit.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/StringToInteger.java
 */

/* Java solution
public class Solution {
    public int atoi(String str) {
        if (str == null || str.length() == 0) {
            return 0; 
        }
        int sign = 1, num = 0; 
        int i = 0; 
        while (str.charAt(i) == ' ' && i < str.length()) {
            ++i; 
        }
        if (str.charAt(i) == '+') {
            ++i; 
        } else if (str.charAt(i) == '-') {
            sign = -1; 
            ++i; 
        }
        for (; i < str.length(); ++i) {
            if (!Character.isDigit(str.charAt(i))) {
                break; 
            }
            if (num > Integer.MAX_VALUE / 10 || (num == Integer.MAX_VALUE / 10 && str.charAt(i) - '0' > Integer.MAX_VALUE % 10)) { // Overflow
                return sign == -1 ? Integer.MIN_VALUE : Integer.MAX_VALUE; 
            }
            num = num * 10 + str.charAt(i) - '0'; 
        }
        return sign * num; 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
