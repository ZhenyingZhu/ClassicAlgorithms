/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    // Use DP. d[j] = i means s[i, j] has unclosed left parentheses.
    // d[j] = 1. if s[j] = ), from 0 to j - 1, d[]

};

const longestParentheses = function(s, st, ed, d) {
    if (st > ed) {
        console.log("doesn't make sense: " + st + " " + ed);
        return 0;
    }

    if (st === ed) {
        d[st][ed] = true;
        return 0;
    }

    if (st === ed - 1) {
        if (s[st] === '(' && s[ed] === ')') {
            d[st][ed] = true;
            return 2;
        } else {
            d[st][ed] = false;
            return 0;
        }
    }

    if (s[st] === '(' && s[ed] === ')' && d[st][ed])
};

document.getElementById("longest-valid-parentheses").innerHTML =
    longestValidParentheses("");
