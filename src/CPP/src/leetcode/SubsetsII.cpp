/*
 * [Source] https://leetcode.com/problems/subsets-ii/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Backtracking
 */

#include <iostream>

using namespace std;

// [Solution]: Recursive call. Add at the begining of each call. If same as previous value and previous value is not used, skip
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/SubsetsUnique.java
 */

/* Java solution
public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] num) {
		List<List<Integer>> result=new ArrayList<List<Integer>>();
		List<Integer> list=new ArrayList<Integer>();
		result.add(list);
        Arrays.sort(num);
		HashMap<Integer, Integer> map=new HashMap<Integer, Integer>();
		for(int i=0; i<num.length-1; i++){
			if(num[i+1]>num[i]) map.put(num[i], i+1);
		} // The biggest value not put to map
		subsetsWithDup(num, map, list, 0, result);
		return result;
    }
	
	public void subsetsWithDup(int[] num, HashMap<Integer, Integer> map, List<Integer> prev, int index, List<List<Integer>> result){
		if(index>=num.length) return;
		List<Integer> list=new ArrayList<Integer>(prev);
		int value=num[index];
		list.add(value);
		result.add(list);
		subsetsWithDup(num, map, list, index+1, result);
		while(map.containsKey(value)){
			int nxtId=map.get(value);
			List<Integer> more=new ArrayList<Integer>(prev);
			value=num[nxtId];
			more.add(value);
			result.add(more);
			subsetsWithDup(num, map, more, nxtId+1, result);
		}
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
