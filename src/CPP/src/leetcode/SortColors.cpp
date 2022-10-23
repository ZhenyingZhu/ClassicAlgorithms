/*
 * [Source] https://leetcode.com/problems/sort-colors/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Two Pointers
 * [Tag]: Sort
 */

#include <iostream>

using namespace std;

// [Solution]: Count the number and reconstruct the array
// [Corner Case]:
class Solution {
};

// [Solution]: Use two pointers point to the end of sorted part. Notice if swap 1, need first swap with the next 1 position, which is 2 already, so don't move pointer ahead.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/sortandsearch/SortColors.java
 */

/* Java solution
public class Solution {
    public void sortColors(int[] A) {
        int white=-1;
		int blue=-1;
		for(int i=0; i<A.length; i++){
			if(A[i]==0){
				white++;
				blue++;
				swap(A, white, i);
				if(blue==white) continue;
				swap(A, blue, i);
			}else if(A[i]==1){
				blue++;
				swap(A, blue, i);
			}
		}
    }
	
	public void swap(int[] A, int a, int b){
		int tmp=A[a];
		A[a]=A[b];
		A[b]=tmp;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
