/*
 * [Source] https://leetcode.com/problems/valid-parentheses/
 * [Difficulty]: Easy
 * [Tag]: Stack
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Use a stack to push left part, and if encounter a right part not match the top of stack, or at the end the stack is not empty, return false
// [Corner Case]:
class Solution {
};

/* Java solution
public class Solution {
    public boolean isValid(String s) {
        if (s == null || s.length() % 2 == 1) {
            return false; 
        }
        Stack<Character> stack = new Stack<Character>(); 
        int i; 
        char cur, pre; 
        for (i = 0; i < s.length(); ++i) {
            cur = s.charAt(i); 
            if ( cur == '(' || cur == '[' || cur == '{') { 
                stack.push((char)(cur == '(' ? cur + 1 : cur + 2)); // Which is ')' or '}' or ']'
            } else if (cur == ')' || cur == ']' || cur == '}') {
                if (stack.empty()) {
                    return false; 
                } else {
                    pre = stack.pop(); 
                    if (pre != cur) {
                        return false; 
                    }
                }
            } else { // Not parthesis char
                return false; 
            }
        }
        if (!stack.empty()) {
            return false; 
        }
        return true; 
    }
}
 */

// [Solution]: Use int to map parentheses
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/datastructure/ValidParentheses.java
 */

int main() {
    Solution sol;

    return 0;
}
