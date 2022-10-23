/*
 * [Source] https://leetcode.com/problems/length-of-last-word/
 * [Difficulty]: Easy
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: count from the end. Start with the first no-space char, end with the first space.
// [Corner Case]: trailing spaces at the end. String is only spaces.
class Solution {
};

// [Solution]: Call split function
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/LengthOfLastWord.java
 */

/* Java solution
public class Solution {
    public int lengthOfLastWord(String s) {
		if(s.length()<=0) return 0;
        String[] array=s.split(" ");
		int pt=array.length-1;
		if(pt<0) return 0;
		return array[pt].length();
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
