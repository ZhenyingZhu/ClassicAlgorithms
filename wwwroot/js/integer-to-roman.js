/**
 * @param {number} num
 * @return {string}
 */
const intToRoman = function(num) {
    // num: [1, 3999]
    let s = "";
    s += valToString(Math.floor(num / 1000), 'M', '', '');
    num = num % 1000;
    s += valToString(Math.floor(num / 100), 'C', 'D', 'M');
    num = num % 100;
    s += valToString(Math.floor(num / 10), 'X', 'L', 'C');
    num = num % 10;
    s += valToString(num, 'I', 'V', 'X');

    return s;
};

const valToString = function(num, oneSym, fiveSym, tenSym) {
    let s = "";
    if (num < 4) {
        for (let i = 0; i < num; i++) {
            s += oneSym;
        }
    } else if (num === 4) {
        s += oneSym;
        s += fiveSym;
    }
    else if (num < 9) {
        s += fiveSym;
        for (let i = 5; i < num; i++) {
            s += oneSym;
        }
    } else {
        s += oneSym;
        s += tenSym;
    }

    return s;
}

document.getElementById("integer-to-roman").innerHTML = intToRoman(399);