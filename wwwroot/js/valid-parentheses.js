/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack = [];
    for (let i = 0; i < s.length; i++) {
        if ("([{".includes(s[i])) {
            stack.push(s[i]);
        }
    }
};

document.getElementById("valid-parentheses").innerHTML = isValid("()");