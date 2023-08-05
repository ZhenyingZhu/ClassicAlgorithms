/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
    // dp[x] is the total ways. dp[x] = dp[x-1] + dp[x-2]
    let n = s.length;
    if (n === 0) {
        return 1;
    }

    if (s[0] === '0') {
        return 0;
    }

    let dp = new Array(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (let i = 1; i < n; i++) {
        if (s[i] === '0') {
            dp[i + 1] = dp[i] - 1;
        } else if (s[i - 1] === '0' ||
            s[i - 1] > '2' ||
            s[i - 1] === '2' && ) {
            dp[i + 1] = dp[i - 1];
        } else {
            dp[i + 1] = dp[i - 1] + dp[i];
        }
    }

    return dp[n];
};

document.getElementById("decode-ways").innerHTML =
    numDecodings("102");