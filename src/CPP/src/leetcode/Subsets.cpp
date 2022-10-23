/*
 * [Source] https://leetcode.com/problems/subsets/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Backtracking
 * [Tag]: Bit Manipulation
 */

#include <iostream>

using namespace std;

// [Solution]: Sort the array. Recursively add elements. If current element is same as the previous one and previous one is not added, skip.
// [Corner Case]: 
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/SubsetsUnique.java
 */

/* Java solution
public class Solution {
    public List<List<Integer>> subsets(int[] S) {
		List<List<Integer>> result=new ArrayList<List<Integer>>();
		if(S.length==0) return result;
        Arrays.sort(S);
		HashMap<Integer, Integer> map=new HashMap<Integer, Integer>();
		for(int i=0; i<S.length; i++){
			map.put(S[i], i+1);
		}
		List<Integer> list=new ArrayList<Integer>();
		result.add(list);
		subsets(S, map, 0, list, result);
		return result;
    }
	
	public void subsets(int[] S, HashMap<Integer, Integer> map, int index, List<Integer> prev, List<List<Integer>> result){
		if(index>=S.length) return; 
		int tail=S[index];
		while(index<S.length){
			tail=S[index];
			index=map.get(tail);
			List<Integer> list=new ArrayList<Integer>(prev);
			list.add(tail);
			result.add(list);
			subsets(S, map, index, list, result);
		}
    }
}
 */

// [Solution]: DP, same as change coins, inner loop traverse all coins, outer loop traver from 1 to target

int main() {
    Solution sol;

    return 0;
}
