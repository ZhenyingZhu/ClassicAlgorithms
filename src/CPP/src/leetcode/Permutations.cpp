/*
 * [Source] https://leetcode.com/problems/permutations/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 */

#include <iostream>

using namespace std;

// [Solution]: First sort. Use a boolean vector to indicate if current value is used or not. If previous is not used and is same as current, skip.
// [Corner Case]: Duplicate
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/PermutationsUnique.java
*/

/* Java solution
public class Solution {
    public List<List<Integer>> permuteUnique(int[] num) {
        List<List<Integer>> result=new ArrayList<List<Integer>>();
		if(num==null || num.length<=0) return result;
		Arrays.sort(num);
		List<Integer> list=new ArrayList<Integer>();
		permute(num, num.length, list, result);
		return result;
    }
	
	private void permute(int[] array, int idx, List<Integer> prev, List<List<Integer>> result){
		if(idx==0){
			result.add(prev);
			return;
		}
		int i=0;
		List<Integer> firList=new ArrayList<Integer>(prev);
		firList.add(array[i]);
		int[] firCp=remove(array, idx, i);
		permute(firCp, idx-1, firList, result);
		while(i<idx-1){
			i++;
			if(array[i]!=array[i-1]){
				List<Integer> list=new ArrayList<Integer>(prev);
				list.add(array[i]);
				int[] cp=remove(array, idx, i);
				permute(cp, idx-1, list, result);
			}
		}
	}
	
	private int[] remove(int[] array, int idx, int del){
		if(idx==1) return array;
		int[] copy=new int[array.length];
		for(int i=0; i<del; i++){
			copy[i]=array[i];
		}
		for(int i=del; i<idx-1; i++){
			copy[i]=array[i+1];
		}
		return copy;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
