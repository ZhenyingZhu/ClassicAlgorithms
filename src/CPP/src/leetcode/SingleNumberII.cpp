/*
 * [Source] https://leetcode.com/problems/single-number-ii/
 * [Difficulty]: Medium
 * [Tag]: Bit Manipulate
 */

#include <iostream>

using namespace std;

// [Solution]: Count how many 1s in each digit position. If it is times of 3, then this digit is 0, otherwise 1.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/bitmanipulate/SingleNumberInThree.java
 */

/* Java solution
public class Solution {
    public int singleNumber(int[] A) {
		int result=0;
		int size=A.length;
		for(int i=0; i<32; i++){
			int cntZero=0;
			for(int j=0; j<size; j++){
				if((A[j]>>i&0x01)==0) cntZero++;
			}
			if(cntZero%3==0){ // So 1 at this position is not the multiple of 3
				result|=(1<<i);
			}
		}
		return result;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
