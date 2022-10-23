/*
 * [Source] https://leetcode.com/problems/roman-to-integer/
 * [Difficulty]: Easy
 * [Tag]: Math
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Read chars and add the value to the result. If current char is larger than previous char, minus previous chars twice.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/RomanToInteger.java
 */

/* Java solution
public class Solution {
    public int romanToInt(String s) {
        int res = 0; 
        for (int i = 0; i < s.length(); ++i) {
            if (i != 0 && romanToInt(s.charAt(i)) > romanToInt(s.charAt(i - 1))) {
                res += romanToInt(s.charAt(i)) - 2 * romanToInt(s.charAt(i - 1)); 
            } else {
                res += romanToInt(s.charAt(i)); 
            }
        }
        return res; 
    }
    
    private int romanToInt(char c) {
        switch (c) {
            case 'I': return 1; 
            case 'V': return 5; 
            case 'X': return 10; 
            case 'L': return 50; 
            case 'C': return 100;
            case 'D': return 500; 
            case 'M': return 1000;
            default: return 0; 
        }
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
