/*
 * [Source] https://leetcode.com/problems/jump-game-ii/
 * [Difficulty]: Hard
 * [Tag]: Array
 * [Tag]: Greedy
 */

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// [Solution]: Maintain two ranges. One range is the farest position current step can reach, one is the farest position next step can reach.
// [Corner Case]: Which range should compute first.
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;

        int curFarest = 0, nextFarest = 0;
        int steps = 0;
        for (int i = 0; i < len; ++i) {
            if (i > curFarest) {
                curFarest = nextFarest;
                ++steps;
            }
            nextFarest = max(i + nums[i], nextFarest);
        }

        return steps;
    }
};

/* Java solution
public class Solution {
    public int jump(int[] A) {
		if(A==null || A.length<=1) return 0;
		int step=0;
		int last=A[0];
		int curStepCanReach=0;
		for(int i=0; i<A.length; i++){
			if(i>last) return Integer.MAX_VALUE; // Cannot reach the end
			if(i>curStepCanReach){
				step++;
				curStepCanReach=last;
			}
			if(i+A[i]>last) last=i+A[i];
			if(last>=A.length-1) return step+1;
		}
		return Integer.MAX_VALUE;
    }
}
 */

// [Solution]: DP. A[j] = min(A[x] + 1) where nums[x] + x >= j.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/JumpGameMinStep.java
 */

int main() {
    Solution sol;

    //vector<int> arr = {2,3,1,1,4};
    vector<int> arr = {1};
    //vector<int> arr = {1, 0};
    //vector<int> arr = {1, 2, 3};
    cout << sol.jump(arr) << endl;

    return 0;
}
