/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    let digitMap = {
        '2': "abc",
        '3': "def",
        '4': "ghi",
        '5': "jkl",
        '6': "mno",
        '7': "pqrs",
        '8': "tuv",
        '9': "wxyz"
    };

    let res = [];
    let com = "";
    for (let i = 0; i < digits.length; i++) {
        let poss = digitMap[digits[i]];
    }
};

document.getElementById("letter-combinations-of-a-phone-number").innerHTML = letterCombinations("23");