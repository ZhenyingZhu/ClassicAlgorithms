const reverse = function(x) {
    if (x === 0 || x <= -(2 ** 31)) {
        return 0;
    }

    if (x === 0) {
        return 0;
    }

    let isNegative = x < 0;
    x = Math.abs(x);

    let res = 0;
    let cnt = 33;
    while (x > 0 && cnt > 0) {
        cnt--;
        res *= 10;
        res += x % 10;

        x = Math.floor(x / 10);
        if (res >= (2 ** 31)) {
            return 0;
        }
        // console.log(x);
    }

    return isNegative ? -res : res;
};

document.getElementById("reverse-integer").innerHTML = reverse(1534236469);