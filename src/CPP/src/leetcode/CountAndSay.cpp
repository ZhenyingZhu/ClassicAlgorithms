/*
 * [Source] https://leetcode.com/problems/count-and-say/
 * [Difficulty]: Easy
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Count the same number and write to a string. Repeat n times.
// [Corner Case]: Don't forget the last number, and count the number itself.
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/CountAndSay.java
 */

/* Java solution
public class Solution {
    public String countAndSay(int n) {
        if (n == 1) {
			return "1"; 
		}
		StringBuffer sb = new StringBuffer(); 
		String s = "1"; 
		for (int i = 1; i < n; ++i) {
			int cnt = 1; 
			for (int j = 1; j < s.length(); ++j) {
				if (s.charAt(j) == s.charAt(j-1)) {
					++cnt;
				} else {
					sb.append(cnt).append(s.charAt(j-1)); 
					cnt = 1;
				}
			}
			sb.append(cnt).append(s.charAt(s.length() - 1)); 
			s = sb.toString(); 
			sb.setLength(0); 
		}
		return s; 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
