/*
 * [Source] https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Two Pointers
 */

#include <iostream>

using namespace std;

// [Solution]: Use a cnt. When find current char is same as the slow pointer, increase cnt. If cnt reach the number, reset it and move forward
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/RemoveDuplicatesFromSortedArrayII.java
 */

/* Java solution
public class Solution {
    public int removeDuplicates(int[] A) {
        HashMap<Integer, Integer> map=new HashMap<Integer, Integer>();
		ArrayList<Integer> list=new ArrayList<Integer>();
		for(int i=0; i<A.length; i++){
			if(!map.containsKey(A[i])){
				map.put(A[i], 1);
				list.add(A[i]);
			}else if(map.get(A[i])<2){
				map.put(A[i], map.get(A[i])+1);
				list.add(A[i]);
			}
		}
		for(int i=0; i<list.size(); i++){
			A[i]=list.get(i);
		}
		return list.size();
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
