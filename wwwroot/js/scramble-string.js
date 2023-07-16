/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isScramble = function(s1, s2) {
    // Use DP. dp[i][j][k] means whether s1[i:i+k) is a scramble of s2[j:j+k)
    // dp[i][j][k] = for l in [1:k), if any (dp[i][j+k-l][l] && dp[i+k-l][j][k-l]) || (dp[i][j][x] && dp[i+k-x][j+k-x][k-x])
    let n = s1.length;
    let dp = new Array(n);
    for (let i = 0; i < n; i++) {
        dp[i] = new Array(n);
        for (let j = 0; j < n; j++) {
            dp[i][j] = new Array(n);
            dp[i][j][0] = true;
            dp[i][j][1] = s1[i] === s2[j];
        }
    }

    return isScrambleNS.helper(s1, s2, 0, 0, n, dp);
};

const isScrambleNS = {
    helper: function(s1, s2, i, j, k, dp) {
        if (dp[i][j][k] !== undefined) {
            return dp[i][j][k];
        }

        for (let l = 1; l < k; l++) {
            if ((this.helper(s1, s2, i, j+k-l, l, dp) && this.helper(s1, s2, i+l, j ,k-l, dp)) ||
            (this.helper(s1, s2, i, j, l, dp) && this.helper(s1, s2, i+l, j+l, k-l, dp))) {
                dp[i][j][k] = true;
                return true;
            }
        }

        dp[i][j][k] = false;
        return false;
    }
};

document.getElementById("scramble-string").innerHTML =
    isScramble("great", "rgeat");