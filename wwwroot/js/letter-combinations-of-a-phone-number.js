/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    let res = [];
    if (digits === null || digits.length === 0) {
        return res;
    }

    appendChar(digits, 0, [], res);
    return res;
};

const digitMap = {
    '2': "abc",
    '3': "def",
    '4': "ghi",
    '5': "jkl",
    '6': "mno",
    '7': "pqrs",
    '8': "tuv",
    '9': "wxyz"
};

/**
 * @param {string} digits
 * @param {int} idx
 * @param {string[]} currChars
 * @param {string[]} res
 */
const appendChar = function(digits, idx, currChars, res) {
    if (idx === digits.length) {
        res.push(currChars.join(''));
        return;
    }

    let poss = digitMap[digits[idx]];
    for (let i = 0; i < poss.length; i++) {
        currChars.push(poss[i]);
        appendChar(digits, idx + 1, currChars, res);
        currChars.pop();
    }
};

document.getElementById("letter-combinations-of-a-phone-number").innerHTML = letterCombinations("23");