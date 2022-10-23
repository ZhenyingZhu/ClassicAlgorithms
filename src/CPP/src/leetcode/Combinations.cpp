/*
 * [Source] https://leetcode.com/problems/combinations/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 */

#include <iostream>

using namespace std;

// [Solution]: Recursive call. Add and remove.
// [Corner Case]: while adding ith element, add from i to n - i not n, otherwise next recursive call need return eailer.
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/Combinations.java
*/

/* Java solution
public class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result=new ArrayList<List<Integer>>();
		if(n<=0 || n<k) return result;
		List<Integer> list=new ArrayList<Integer>();
		subset(0, 0, n, k, list, result);
		return result;
    }
	
	public void subset(int cur, int size, int n, int k, List<Integer> prev, List<List<Integer>> result){
		if(cur>n) return; 
		if(size==k){
			result.add(prev);
			return;
		}
		for(int i=cur+1; i<=n; i++){
			List<Integer> list=new ArrayList<Integer>(prev);
			list.add(i);
			subset(i, size+1, n, k, list, result);
		}
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
