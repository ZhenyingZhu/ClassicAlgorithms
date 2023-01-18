/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor) {
    const int_max = 2147483648;
    let factor = 1;
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        factor = -1;
    }

    dividend = Math.abs(dividend);
    divisor = Math.abs(divisor);

    if (divisor > dividend) {
        return 0;
    }

    let cnt = 1;
    let val = divisor;
    while (val + val < dividend) {
        val = val + val;
        cnt = cnt + cnt;
    }

    let res = factor * (cnt + divide(dividend - val, divisor));
    if (res >= int_max) {
        return int_max - 1;
    } else {
        return res;
    }
};

document.getElementById("divide-two-integers").innerHTML =
    //divide(10, 3);
    //divide(4, 2);
    //divide(4, 4);
    //divide(1, 3);
    //divide(7, -3);
    divide(-2147483648, -1);
