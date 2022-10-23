/*
 * [Source] https://leetcode.com/problems/zigzag-conversion/
 * [Difficulty]: Easy
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: divide the string by cycle
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/ZigZagConversion.java
 */

/* Java solution
public class Solution {
    public String convert(String s, int nRows) {
        if (s == null || s.length() == 0 || nRows <= 1) {
            return s; 
        }
        StringBuffer[] buffers = new StringBuffer[nRows]; 
        for (int i = 0; i < buffers.length; ++i) {
            buffers[i] = new StringBuffer(); 
        }
        int idx; 
        for (int i = 0; i < s.length(); ++i) {
            idx = i % (nRows + nRows - 2); 
            if (idx >= nRows) {
                idx = nRows + nRows - 2 - idx; 
            }
            buffers[idx].append(s.charAt(i)); 
        }
        for (int j = 1; j < buffers.length; ++j) {
            buffers[0].append(buffers[j]); 
        }
        return buffers[0].toString(); 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
