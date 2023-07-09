/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isScramble = function(s1, s2) {
    // Use DP. dp[i][j][k] means whether s1[i:i+k) is a scramble of s2[j:j+k])
    // dp[i][j][k] = for l in [1:k), if any (dp[i][j+k-l][l] && dp[i+k-l][j][k-l]) || (dp[i][j][x] && dp[i+k-x][j+k-x][k-x])
};

const isScrambleNS = {
    helper: function() {
        
    }
};

document.getElementById("scramble-string").innerHTML =
    isScramble("great", "rgeat");