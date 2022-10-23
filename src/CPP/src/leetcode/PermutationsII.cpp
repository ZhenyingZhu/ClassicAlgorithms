/*
 * [Source] https://leetcode.com/problems/permutations-ii/
 * [Difficulty]: Medium
 * [Tag]: Backtrcking
 */

#include <iostream>

using namespace std;

// [Solution]: Same as permutations
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/Permutations.java
 */

/* Java solution
public class Solution {
    public List<List<Integer>> permute(int[] num) {
        List<List<Integer>> result=new ArrayList<List<Integer>>();
		if(num==null || num.length<=0) return result;
		List<Integer> list=new ArrayList<Integer>();
		permute(num, num.length, list, result);
		return result;
    }
	
	private void permute(int[] array, int idx, List<Integer> prev, List<List<Integer>> result){
		if(idx==0){
			result.add(prev);
			return;
		}
		for(int i=0; i<idx; i++){
			List<Integer> list=new ArrayList<Integer>(prev);
			list.add(array[i]);
			int[] cp=remove(array, idx, i);
			permute(cp, idx-1, list, result);
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
