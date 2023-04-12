/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    let ways = new Array(n + 1);
    ways[0] = 1;
    ways[1] = 1;
    for (let i = 2; i <= n; i++) {
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    return ways[n];
};

document.getElementById("climbing-stairs").innerHTML =
    // climbStairs(2);
    climbStairs(3);
