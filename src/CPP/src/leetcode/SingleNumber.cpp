/*
 * [Source] https://leetcode.com/problems/single-number/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 * [Tag]: Bit Manipulate
 */

#include <iostream>

using namespace std;

// [Solution]: XOR all the numbers. Those appear twice numbers disappear after XOR.
// [Corner Case]:
class Solution {
};

// [Solution]:
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/bitmanipulate/SingleNumber.java
 */

/* Java solution
public class Solution {
    public int singleNumber(int[] A) {
		int result=0;
		int size=A.length;
		for(int i=0; i<32; i++){
			int bit=0;
			for(int j=0; j<size; j++){
				bit^=A[j]>>i&0x01; // If there are odd 1s, bit=1
			}
			result|=(bit<<i);
		}
		return result;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
