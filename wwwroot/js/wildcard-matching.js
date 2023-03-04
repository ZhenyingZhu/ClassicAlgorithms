/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    // d[i][j] = T means s(0, i] matches p(0, j].
    // d[i][j] = (s[i] == p[j] || p[j] == *) && d[i - 1, j - 1] == T
    //        || p[j] == ? && d[i - x, j - 1] == T
};

document.getElementById("wildcard-matching").innerHTML =
    // isMatch("aa", "a");
    isMatch("aa", "a");
