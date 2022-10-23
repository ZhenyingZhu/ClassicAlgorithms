/*
 * [Source] https://leetcode.com/problems/generate-parentheses/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: l=3,r=3, recursive call genPar(pre, l, r): if l > 0, genPar(pre+'(', l-1, r); if r > l, genPar(pre+')', l, r-1);
// [Corner Case]:
class Solution {
};

// [Solution]: Add '(', then recursively try to add ')'
/* Java solution
public class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<String>(); 
        if (n <= 0) {
            return result; 
        }
        generateParenthesisHelper(n, 1, 0, "", result); 
        return result; 
    }
    
    private void generateParenthesisHelper(int n, int idx, int used, String prev, List<String> result) {
        int i; 
        if (idx == n) {
            StringBuffer sol = new StringBuffer(prev + "("); 
            for (i = 0; i< idx - used; ++i) {
                sol.append(')'); 
            }
            result.add(sol.toString()); 
            return; 
        }
        String str = prev + "("; 
        for (i = 0; i <= idx - used; ++i) {
            generateParenthesisHelper(n, idx + 1, used + i, str, result); 
            str += ")"; 
        }
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
