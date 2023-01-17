/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    // d[2][1] == T means h[1, 1] == s[0, 0]
    // d[i][j] == T means h[i - j, i - 1] matches s[0, j - 1]
    // d[i][j] = d[i - 1][j - 1] && h[i - 1] == s[j - 1]
    // d[i][0] = T
    // d[0][j] = F
    let d = new Array(haystack.length + 1);
    for (let i = 0; i < haystack.length + 1; i++) {
        d[i] = new Array(needle.length + 1);
        d[i][0] = true;
    }
    for (let j = 1; j < needle.length + 1; j++) {
        d[0][j] = false;
    }

    for (let j = 1; j < needle.length + 1; j++) {
        for (let i = 1; i < haystack.length + 1; i++) {
            d[i][j] = haystack[i - 1] === needle[j - 1] && d[i - 1][j - 1];
            if (j === needle.length && d[i][j]) {
                return i - needle.length;
            }
        }
    }

    return -1;
};

document.getElementById("find-the-index-of-the-first-occurrence-in-a-string").innerHTML =
    //strStr('sadbutsad', 'sad');
    strStr('abbcb', 'bc');
