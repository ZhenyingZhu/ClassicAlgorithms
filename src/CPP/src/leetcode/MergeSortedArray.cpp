/*
 * [Source] https://leetcode.com/problems/merge-sorted-array/
 * [Difficulty]: Easy
 * [Tag]: Array
 * [Tag]: Two Pointers
 */

#include <iostream>

using namespace std;

// [Solution]: Start from end
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/MergeSortedArray.java
 */

/* Java solution
public class Solution {
    public void merge(int A[], int m, int B[], int n) {
		if(A.length<m+n) return;
        if(n==0) return;
		if(m==0){
			for(int i=0; i<n; i++){
				A[i]=B[i];
			}
			return;
		}
		int ae=m-1;
		int be=n-1;
		int end=m+n-1;
		while(ae>=0 && be>=0){
			if(A[ae]>B[be]) {
				A[end]=A[ae];
				ae--;
			}else{
				A[end]=B[be];
				be--;
			}
			end--;
		}
		if(be<0) return;
		while(be>=0){
			A[end]=B[be];
			be--;
			end--;
		}
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
