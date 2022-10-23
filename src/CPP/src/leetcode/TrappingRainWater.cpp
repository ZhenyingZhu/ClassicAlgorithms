/*
 * [Source] https://leetcode.com/problems/trapping-rain-water/
 * [Difficulty]: Hard
 * [Tag]: Array
 * [Tag]: Stack
 * [Tag]: Two Pointers
 */

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// [Solution]: Find the highest left pole, find the highest right pole. The min minus current height is the water this pole can contain.
// [Corner Case]:
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len <= 1)
            return 0;

        vector<int> leftHigh(len);
        leftHigh[0] = 0;
        for (int i = 1; i < len; ++i)
            leftHigh[i] = max(leftHigh[i - 1], height[i - 1]);

        vector<int> rightHigh(len);
        rightHigh[len - 1] = 0;
        for (int i = len - 2; i >= 0; --i)
            rightHigh[i] = max(rightHigh[i + 1], height[i + 1]);

        int sum = 0;
        for (int i = 0; i < len; ++i) {
            int cur = min(leftHigh[i], rightHigh[i]) - height[i];
            if (cur > 0)
                sum += cur;
        }

        return sum;
    }

private: // helper
    void printVec(const vector<int>& vec) {
        for (const int& i : vec)
            cout << i << ",";
        cout << endl;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/TrappingRainWater.java
 */

/* Java solution
public class Solution {
    public int trap(int[] A) {
        int[] left=new int[A.length];
		int[] right=new int[A.length];
		for(int i=1; i<A.length; i++){
			left[i]=Math.max(left[i-1], A[i-1]);
			right[A.length-1-i]=Math.max(right[A.length-i], A[A.length-i]);
		}
		int result=0;
		for(int i=0; i<A.length; i++){
			int height=Math.min(left[i], right[i]);
			if(height>A[i]) result+=(height-A[i]);
		}
		return result;
    }
}
 */

int main() {
    Solution sol;

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(height) << endl;

    return 0;
}
