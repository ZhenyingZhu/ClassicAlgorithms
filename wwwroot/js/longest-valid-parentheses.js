/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    // Use DP. d[i][j] means s[i, j] is valid.
    // d[i][j] = d[i-1][j-1] = T && s[i] s[j] are () || d[i][j-2] = T && s[j-1] s[j] are () || d[i+2][j] = T && s[i] s[i+1] are ()
};

document.getElementById("longest-valid-parentheses").innerHTML =
    longestValidParentheses("");
