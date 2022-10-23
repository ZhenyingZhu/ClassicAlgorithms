/*
 * [Source] https://leetcode.com/problems/plus-one/
 * [Difficulty]: Easy
 * [Tag]: Array
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]: Use a carry value
// [Corner Case]: array is empty. Or need an additional slot.
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/PlusOne.java
 */

/* Java solution
public class Solution {
    public int[] plusOne(int[] digits) {
		int c=1;
        for(int i=digits.length-1; i>=0; i--){
			digits[i]+=c;
			if(digits[i]>=10){
				c=1;
				digits[i]-=10;
			}else{
				c=0;
			}
		}
		if(c==0) return digits;
		int[] res=new int[digits.length+1];
		res[0]=1;
		for(int i=0; i<digits.length; i++){
			res[i+1]=digits[i];
		}
		return res;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
