/*
 * [Source] https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Binary Search
 */

#include <iostream>

using namespace std;

// [Solution]: Other parts are same. If md is equal to st or ed, need to search the whole array.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/sortandsearch/SearchInRotatedSortedArrayDup.java
 */

/* Java solution
public class Solution {
    public boolean search(int[] A, int target) {
        return search(A, 0, A.length-1, target);
    }
	
	public boolean search(int[] array, int start, int end, int target){
		if(start>end) return false;
		if(array[end]==target || array[start]==target) return true;
		int mid=(start+end)/2;
		if(array[mid]==target) return true;
		if(array[mid]== array[start] && array[mid]==array[end]){
			return search(array, start+1, mid-1, target) || search(array, mid+1, end-1, target);
		}
		if(array[mid]>target){
			if(array[end]>=array[mid]){ // No wrap
				return search(array, start+1, mid-1, target);
			}else{ // end<mid, mid>tar
				if(array[end]>target){
					return search(array, mid+1, end-1, target);
				}else{ 
					return search(array, start+1, mid-1, target);
				}
			}
		}else{ // mid<target
			if(array[start]<=array[mid]){
				return search(array, mid+1, end-1, target);
			}else{ //start>mid
				if(array[start]<target){
					return search(array, start+1, mid-1, target);
				}else{ // start>tar
					return search(array, mid+1, end-1, target);
				}
			}
		}
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
