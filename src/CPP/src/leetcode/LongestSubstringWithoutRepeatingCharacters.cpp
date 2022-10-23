/*
 * [Source] https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * [Difficulty]: Medium
 * [Tag]: Hash table
 * [Tag]: Two pointers
 * [Tag]: String
 */

#include <iostream>

using namespace std;

class Solution {
};

// [Solution]: Use a pointer to record the current start point, and another pointer to indicate the process char. Use a hash set to record the shown chars, and if found, record the length, move the starter to the duplicate char and pop those chars from set.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/LongestSubstringWithoutRepeatingCharacters.java
 */

// [Solution]: An improvement of previous solution. Use a hash table that map the char to the index. Always record the latest position of each char.
/* Java solution
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0; 
        }
        HashMap<Character, Integer> map = new HashMap<Character, Integer>(); 
        int maxLen = 0; 
        int st = -1; // The pos of last conflicate one
        int lastPos = -1; 
        for (int i = 0; i < s.length(); ++i) {
            if (!map.containsKey(s.charAt(i))) {
                map.put(s.charAt(i), i); 
            } else {
                lastPos = map.get(s.charAt(i)); 
                map.put(s.charAt(i), i); 
                if (lastPos > st) {
                    maxLen = Math.max(maxLen, i - 1 - st); 
                    st = lastPos; 
                }
            }
        }
        return Math.max(maxLen, s.length() - 1 - st); 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
