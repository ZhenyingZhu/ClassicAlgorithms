/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isScramble = function(s1, s2) {
    // Use DP. dp[i][j][k] means whether s1[i:i+k] is a scramble of s2[j:j+k].
    // dp[i][j][k] = for x in 0:k, (dp[i][j+k-x][x] && dp[i+k-x][j][k-x]) || (dp[i][j][x] && dp[i+k-x][j+k-x][k-x])
};

const isScrambleNS = {
    helper: function() {
        
    }
};

document.getElementById("scramble-string").innerHTML =
    isScramble("great", "rgeat");