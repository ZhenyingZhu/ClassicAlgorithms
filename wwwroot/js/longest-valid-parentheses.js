/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    // Solution 1:
    // Use DP. d[j] = i means the length of the longest valid parentheses closed at s[j].
    // init: d[0] = 0 matching s[-1]
    // if s[i] = '(', d[i+1] = 0;
    // if s[i] = ')', if s[i-1] = '(', d[i+1] = d[i-1] + 2
    //                if s[j-1] = ')', using d[j] we can find the first '(' matches s[j-1]. If the previous char is '(', then d[j] = d[j-1-d[j-1]] + 2
    let res = 0;
    let d = new Array(s.length + 1);
    d[0] = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            d[i + 1] = 0;
        } else if (s[i - 1] === '(') {
            d[i + 1] = d[i - 1] + 2;
            res = Math.max(d[i + 1], res);
        } else if (s[i - 1 - d[i]] === '(') {
            d[i + 1] = d[i] + 2 + d[i - d[i] - 1];
            res = Math.max(d[i + 1], res);
        } else {
            d[i + 1] = 0;
        }
    }

    return res;
    // Solution 2: use stack
};

document.getElementById("longest-valid-parentheses").innerHTML =
    longestValidParentheses("()(())");
