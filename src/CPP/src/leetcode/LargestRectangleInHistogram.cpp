/*
 * [Source] https://leetcode.com/problems/largest-rectangle-in-histogram/
 * [Difficulty]: Hard
 * [Tag]: Array
 * [Tag]: Stack
 */

#include <iostream>
#include <vector>
#include <stack>
#include <functional>
#include <climits>

using namespace std;

// [Solution]: Since the area depends min height on the path. Use a stack to track previous min height index.
// [Corner Case]: stack is empty. Dup height. heights are increasing
class Solution {
private:
    int findMaxArea(stack<size_t>& idxes, const vector<int>& heights, size_t ed, int nextHeight) {
        int maxArea = 0;
        while (!idxes.empty() && nextHeight < heights[idxes.top()]) {
            int height = heights[idxes.top()];
            idxes.pop();
            size_t st = idxes.empty() ? 0 : idxes.top() + 1;
            int width = ed - st;
            maxArea = max(maxArea, height * width);
        }
        return maxArea;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0)
            return 0;

        int maxArea = 0;
        stack<size_t> idxes;
        for (size_t i = 0; i < heights.size(); ++i) {
            if (idxes.size() == 0 || heights[i] > heights[idxes.top()]) {
                idxes.push(i);
                continue;
            }
            maxArea = max(maxArea, findMaxArea(idxes, heights, i, heights[i]));

            idxes.push(i);
        }
        maxArea = max(maxArea, findMaxArea(idxes, heights, heights.size(), 0));

        return maxArea;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/datastructure/LargestRectangleInHistogram.java
 */

/* Java solution
public class Solution {
    public int largestRectangleArea(int[] height) {
		int len=height.length;
		if(len==0) return 0;
		int max=0;
		Stack<Integer> heiStack=new Stack<Integer>();
		Stack<Integer> idxStack=new Stack<Integer>();
		for(int i=0; i<len; i++){
			if(heiStack.empty() || height[i]>=heiStack.peek()){
				heiStack.push(height[i]);
				idxStack.push(i);
			}else{ // Compute
				int l=0;
				while(!heiStack.empty() && heiStack.peek()>height[i]){ // Not equal to leave the equal situation to next compute
					l=idxStack.pop();
					max=Math.max(max, (i-l)*heiStack.pop()); // i already bigger than the current right bound 
				}
				heiStack.push(height[i]);
				idxStack.push(l); // This rectangle should computed before encounter the prev left bound, otherwise wrong when l=0
			}
		}
		while(!heiStack.empty()){
			max=Math.max(max, (len-idxStack.pop())*heiStack.pop());
		}
		return max;
    }
}
 */

int main() {
    Solution sol;

    vector<int> heights = {2,1,5,5,6, 2,3};
    cout << sol.largestRectangleArea(heights) << endl;

    return 0;
}
