/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let array = [];
    let res = [];
    generatePar(array, 0, n, res);
    return res;
};

const generatePar = function(array, sum, n, res) {
    if (array.length === n) {
        res.push(generateParStr(array));
        return;
    }

    if (array.length === n - 1) {
        array.push(n - sum);
        generatePar(array, n, n, res);
        array.pop();
    } else {
        for (let i = 0; i < array.length + 1 - sum; i++) {
            array.push(i);
            generatePar(array, sum + i, n, res);
            array.pop();
        }
    }
}

const generateParStr = function(array) {
    let str = "";
    for (let i = 0; i < array.length; i++) {
        str += '(';
        for (let j = 0; j < array[i]; j++) {
            str += ')';
        }
    }

    return str;
}

document.getElementById("generate-parentheses").innerHTML = generateParenthesis(3);