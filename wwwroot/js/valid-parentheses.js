/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const parMap = {
        ')': '(',
        ']': '[',
        '}': '{'
    };

    let stack = [];
    for (let i = 0; i < s.length; i++) {
        if ("([{".includes(s[i])) {
            stack.push(s[i]);
            continue;
        }

        if (stack[stack.length - 1] === parMap[s[i]]) {
            stack.pop();
        } else {
            return false;
        }
    }

    return stack.length === 0;
};

document.getElementById("valid-parentheses").innerHTML = isValid("(()[{])}");