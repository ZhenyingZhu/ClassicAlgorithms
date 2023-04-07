/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    if (digits.length === 0) {
        return [1];
    }

    let val = digits[digits.length - 1] + 1;
    digits[digits.length - 1] = val % 10;
    let rem = Math.floor(val / 10);
    for (let i = digits.length - 2; i >= 0 && rem === 1; i--) {
        val = digits[i] + 1;
        digits[i] = val % 10;
        rem = Math.floor(val / 10);
    }

    if (rem === 1) {
        digits.unshift(1);
    }

    return digits;
};

document.getElementById("plus-one").innerHTML =
    // plusOne([1,2,3]);
    // plusOne([]);
    plusOne([9]);
