/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let romanVal = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    };

    let sum = 0;
    let prev = 0;
    for (let i = 0; i < s.length; i++) {
        let cur = romanVal[s[i]];
        if (cur > prev) {
            sum -= 2 * prev;
        }

        sum += cur;
        prev = cur;
    }

    return sum;
};

document.getElementById("roman-to-integer").innerHTML = romanToInt("IX");