/*
 * [Source] https://leetcode.com/problems/sqrtx/
 * [Difficulty]: Medium
 * [Tag]: Binary Search
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]: From 1, to x/2, find if i*i <= x, and (i+1)*(i+1) > x.
// [Corner Case]: x=0 ~ x=4. 
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        int left = 1, right = x / 2;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (mid < x / mid) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (right <= x / right)
            return right;
        return left;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/Sqrt.java
 */

/* Java solution
public class Solution {
    public int sqrt(int x) {
        if(x==0 || x==1) return x;
		int start=1;
		int end=x/2;
		int result=1;
		while(start<=end){
			int mid=(start+end)/2;
			if(x/mid>mid){
				start=mid+1;
				result=mid;
			}else if(x/mid<mid){
				end=mid-1;
			}
			else return mid;
		}
		return result;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
