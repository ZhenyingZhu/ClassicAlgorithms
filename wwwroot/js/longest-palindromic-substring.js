/**
 * @param {String} s
 * @return {String}
 */
 const longestPalindrome = function(s) {
    if (s.length <= 1) {
        return s;
    }

    // Use DP.
    let matrix = new Array(s.length + 1);
    for (let i = 0; i < s.length; i++) {
        matrix[i] = new Array(s.length);
    }

    let st = 0;
    let len = 0;
    for (let i = 0; i < s.length; i++) {
        for (let j = 0; j < s.length - i; j++) {
            let val = true;
            if (i === 0) {
                val = true;
            } else if (i === 1) {
                val = (s[j] === s[j + 1] ? true : false);
            }
            else {
                let prev = matrix[j + 1][j + i - 1];
                val = (s[j] === s[j + i] ? prev : false);
            }

            // console.log("j: " + j + " j+i: " + (j + i) + " val: " + val);
            matrix[j][j + i] = val;

            if (val && i + 1 > len) {
                st = j;
                len = i + 1;

                // console.log(s.substr(st, len));
            }
        }
    }

    return s.substr(st, len);
};

document.getElementById("longest-palindromic-substring").innerHTML = longestPalindrome("abacabe");