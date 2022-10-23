/*
 * [Source] https://leetcode.com/problems/integer-to-roman/
 * [Difficulty]: Medium
 * [Tag]: Math
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Use an array to record all Roman expression from large to small. Then divide the int to see how many same expression needed to present that number, then mode the int for next round.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/IntegerToRoman.java
 */

/* Java solution
public class Solution {
    public String intToRoman(int num) {
        if (num <= 0) {
            return ""; 
        }
        String[] roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; 
        int[] value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; 
        int cnt; 
        StringBuffer res = new StringBuffer(); 
        int i, j; 
        for (i = 0; num > 0; ++i) {
            cnt = num / value[i]; 
            num = num % value[i]; 
            for (j = 0; j < cnt; ++j) {
                res.append(roman[i]); 
            }
        }
        return res.toString(); 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
