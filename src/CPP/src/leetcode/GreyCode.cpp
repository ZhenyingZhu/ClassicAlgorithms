/*
 * [Source] https://leetcode.com/problems/gray-code/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 */

#include <iostream>

using namespace std;

// [Solution]: Start from 0 and 1, keep add 2^n to the list in reverse order.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/GrayCode.java
 */

/* Java solution
public class Solution {
    public List<Integer> grayCode(int n) {
		List<Integer> result=new ArrayList<Integer>();
		result.add(0);
		if(n<=0) return result;
		result.add(1);
        int bit=1;
		int add=1;
		while(bit<n){
			add*=2;
			for(int i=add-1; i>=0; i--){
				result.add(result.get(i)+add);
			}
			bit++;
		}
		return result;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
