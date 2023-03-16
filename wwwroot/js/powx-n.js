/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if (n === 0) {
        return 1;
    }

    if (n < 0) {
        x = 1 / x;
        n = -n;
    }

    return myPowNS.helper(x, n);
};

const myPowNS = {
    helper: function(x, n) {
        if (n === 1) {
            return x;
        }

        let half = this.helper(x, Math.floor(n / 2));
        if (n % 2 === 0) {
            return half * half;
        }

        return half * half * x;
    }
};

document.getElementById("powx-n").innerHTML =
    // myPow(2.00000, 10);
    // myPow(2.1, 3);
    myPow(2, -2);
