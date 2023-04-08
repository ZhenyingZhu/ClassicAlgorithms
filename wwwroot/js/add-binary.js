/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let m = a.length - 1;
    let n = b.length - 1;

    let res = "";
    let val = 0;
    let carry = 0;
    while (m >= 0 && n >= 0) {
        val = parseInt(a[m]) + parseInt(b[n]) + carry;
        carry = Math.floor(val / 2);
        val = val % 2;
        res = val + res;
        m--;
        n--;
    }

    while (m >= 0) {
        val = parseInt(a[m]) + carry;
        carry = Math.floor(val / 2);
        val = val % 2;
        res = val + res;
        m--;
    }

    while (n >= 0) {
        val = parseInt(b[n]) + carry;
        carry = Math.floor(val / 2);
        val = val % 2;
        res = val + res;
        n--;
    }

    if (carry > 0) {
        res = carry + res;
    }

    return res;
};

document.getElementById("add-binary").innerHTML =
    // addBinary("11", "1");
    addBinary("1010", "1011");
