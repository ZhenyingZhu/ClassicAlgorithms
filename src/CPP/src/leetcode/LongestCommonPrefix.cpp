/*
 * [Source] https://leetcode.com/problems/longest-common-prefix/
 * [Difficulty]: Easy
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Read in first two string, find the common prefix, then use this prefix to compare with the third string.
// [Corner Case]:
class Solution {
};

// [Solution]: Read in as columns. If one column does not have only one char, or one string is already end, return the string with the length.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/LongestCommonPrefix.java
 */

/* Java solution
public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return ""; 
        }
        if (strs.length == 1) {
            return strs[0]; 
        }
        int ed = strs[0].length(); 
        for (int i = 1; i < strs.length; ++i) {
            for (int j = 0; j < ed; ++j) {
                if (j == strs[i].length() || strs[0].charAt(j) != strs[i].charAt(j)) {
                    ed = j; 
                    break; 
                }
            }
        }
        return strs[0].substring(0, ed); 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
