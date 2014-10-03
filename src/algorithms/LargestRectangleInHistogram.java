package algorithms; 

import java.util.*; 

public class LargestRectangleInHistogram {
    /* Function: Give a histogram with all non-negative numbers, 
     *    find the largest rectangle. 
     * Solution: Use a stack to record the previous index, to find 
     *    a rectangle that both sides lower than it. 
     */ 
    public int largestRectangleArea(int[] height) {
        if (height == null || height.length == 0) {
            return 0; 
        }
        
        int max = 0; 
        Stack<Integer> stack = new Stack<Integer>(); 
        for (int i = 0; i <= height.length; ++i) {
            int key = i == height.length ? 0 : height[i]; 
            while (!stack.empty() && key < height[stack.peek()]) {
                int h = height[stack.pop()]; 
                int w = stack.empty() ? i : i - 1 - stack.peek(); 
                max = Math.max(max, h * w); 
            }
            stack.push(i); 
        }
        
        return max; 
    }
}
