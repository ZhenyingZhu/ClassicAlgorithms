/**
 * @param {number} n
 * @return {number[]}
 */
var grayCode = function(n) {
    if (n === 0) {
        return [];
    }

    let res = [0, 1];
    let mul = 1;
    for (let i = 1; i < n; i++) {
        mul *= 2;
        let l = res.length;
        for (let j = l - 1; j >= 0; j--) {
            res.push(mul + res[j]);
        }
    }

    return res;
};

document.getElementById("gray-code").innerHTML =
    grayCode(3);