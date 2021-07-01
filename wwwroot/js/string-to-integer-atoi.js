const myAtoi = function(s) {
    s = s.trim();

    let isNeg = false;
    if (s[0] === '-') {
        isNeg = true;
        s = s.substr(1);
    } else if (s[0] === '+') {
        s = s.substr(1);
    }

    let res = 0;
    for (let i = 0; i < s.length; i++) {
        // console.log(s[i]);
        if (s[i] === ' ' || isNaN(s[i]))
        {
            break;
        }

        res *= 10;
        res += ~~s[i];

        if (res >= Math.pow(2, 31)) {
            if (isNeg) {
                return -Math.pow(2, 31);
            }
            return Math.pow(2, 31) - 1;
        }
    }

    return isNeg ? -res : res;
};

document.getElementById("string-to-integer-atoi").innerHTML = myAtoi("4193 with words");