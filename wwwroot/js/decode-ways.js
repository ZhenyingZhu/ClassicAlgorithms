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
        dp[i + 1] = 0;

        if (s[i] !== '0') {
            dp[i + 1] = dp[i];
        }

        if (s[i - 1] === '1' ||
        (s[i - 1] === '2' && s[i] <= '6')) {
            dp[i + 1] += dp[i - 1];
        }

        if (dp[i + 1] === 0) {
            return 0;
        }
    }

    return dp[n];
};

document.getElementById("decode-ways").innerHTML =
    // numDecodings("1102");
    // numDecodings("901");
    numDecodings("2611055971756562");
