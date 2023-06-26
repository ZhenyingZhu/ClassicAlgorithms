/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isScramble = function(s1, s2) {
    // Use DP. dp[i][j][k] means whether s1[i:i+k] is a scramble of s2[j:j+k].
};

document.getElementById("scramble-string").innerHTML =
    isScramble("great", "rgeat");