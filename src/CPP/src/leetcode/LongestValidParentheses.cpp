/*
 * [Source] https://leetcode.com/problems/longest-valid-parentheses/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 * [Tag]: String
 */

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// [Solution]: Use the previous unclosed parenthese as the start, so that we can handle longest length
// [Corner Case]: there are unclosed parenthese when string ends
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0, st = -1;
        stack<int> validIdxes;
        for (int i = 0; i < (int)s.length(); ++i) {
            if (s[i] == '(') {
                validIdxes.push(i);
            } else if (s[i] == ')') {
                if (validIdxes.empty()) {
                    st = i;
                    continue;
                }

                validIdxes.pop();
                int j = validIdxes.empty()? st : validIdxes.top();
                maxLen = max(maxLen, i - j);
            }
        }

        return maxLen;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/datastructure/LongestValidParentheses.java
 */

/* Java solution
public class Solution {
    public int longestValidParentheses(String s) {
        if(s == null || s.length() <= 1) {
            return 0; 
        }
        Stack<Integer> stack = new Stack<Integer>(); 
        int start = -1; 
        int result = 0; 
        for(int i = 0; i < s.length(); ++i) {
            if(s.charAt(i) == '(') {
                stack.push(i); 
            } else if (s.charAt(i) == ')') {
                if(!stack.empty()) {
                    stack.pop(); 
                    if(stack.empty()) { // Find valid seq
                        result = Math.max(result, i - start); 
                    } else {
                        result = Math.max(result, i - stack.peek()); // The last unmatched (
                    }
                } else {
                    start = i;
                }
            }
        }
        return result; 
    }
}
 */

int main() {
    Solution sol;

    string str = "()()";
    //string str = "(()()";
    //string str = "()(()";
    //string str = "()(())(";
    //string str = "(()()(())((";

    cout << sol.longestValidParentheses(str) << endl;

    return 0;
}
