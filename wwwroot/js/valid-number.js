/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    if (s.length === 0) {
        return false;
    }

    let arr = s.split('e');
    if (arr.length > 2) {
        return false;
    }
    if (arr.length === 1) {
        arr = s.split('E');
    }

    if (arr.length === 1) {
        return isNumberNS.isSignedInteger(s) || isNumberNS.isSignedDecimal(s);
    }

    let x = arr[0];
    if (!isNumberNS.isSignedInteger(x) && !isNumberNS.isSignedDecimal(x)) {
        return false;
    }

    x = arr[1];
    return isNumberNS.isSignedInteger(x);
};

const isNumberNS = {
    isSignedInteger: function(s) {
        if (s.length === 0) {
            return false;
        }

        if (s[0] === '+' || s[0] === '-') {
            return this.isInteger(s.substring(1));
        } else {
            return this.isInteger(s);
        }
    },

    isInteger: function(s) {
        if (s.length === 0) {
            return false;
        }

        for (let i = 0; i < s.length; i++) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }

        return true;
    },

    isSignedDecimal: function(s) {
        if (s.length === 0) {
            return false;
        }

        if (s[0] === '+' || s[0] === '-') {
            return this.isDecimal(s.substring(1));
        } else {
            return this.isDecimal(s);
        }
    },

    isDecimal: function(s) {
        if (s.length === 0) {
            return false;
        }

        const arr = s.split('.');
        if (arr.length > 2) {
            return false;
        }

        let x = arr[0];
        // not allow to be signed integer because it is checked in isSignedDecimal.
        // Because of the case +.1, to avoid check empty and check sign twice.
        if (x.length !== 0 && !this.isInteger(x)) {
            return false;
        }

        let y = arr[1];
        // not allow to have sign.
        if(y.length !== 0 && !this.isInteger(y)) {
            return false;
        }

        // not allow to have . only
        return x.length !== 0 || y.length !== 0;

    },
};

document.getElementById("valid-number").innerHTML =
    // isNumber("95a54e53");
    isNumber("+eo");
