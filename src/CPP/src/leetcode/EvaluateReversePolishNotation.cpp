/*
 * [Source] https://leetcode.com/problems/evaluate-reverse-polish-notation/
 * [Difficulty]: Medium
 * [Tag]: Stack
 */

#include <iostream>

using namespace std;

// [Solution]: Use a stack. If number, push into stack. If operator, pop two number, do the math and push back result.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/datastructure/EvaluateReversePolishNotation.java
 */

/* Java solution
public class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack=new Stack<Integer>();
        for(int i=0; i<tokens.length; i++){
            if(tokens[i].equals("+")){
                int a=stack.pop();
                int b=stack.pop();
                int c=b+a;
                stack.push(c);
            }else if(tokens[i].equals("-")){
                int a=stack.pop();
                int b=stack.pop();
                int c=b-a;
                stack.push(c);
            }else if(tokens[i].equals("*")){
                int a=stack.pop();
                int b=stack.pop();
                int c=b*a;
                stack.push(c);
            }else if(tokens[i].equals("/")){
                int a=stack.pop();
                int b=stack.pop();
                int c=b/a;
                stack.push(c);
            }else{
                stack.push(Integer.valueOf(tokens[i]));
            }
        }
        return stack.pop();
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
