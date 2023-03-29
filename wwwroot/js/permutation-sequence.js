/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
    let fac = new Array(n);
    fac[0] = 1;
    for (let i = 1; i < n; i++) {
        fac[i] = fac[i - 1] * i;
    }

    let nums = new Array(n);
    for (let i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    let res = "";
    k = k - 1;
    for (let i = n - 1; i >= 0; i--) {
        let idx = Math.floor(k / fac[i]);
        res += nums[idx];
        nums.splice(idx, 1);
        k = k % fac[i];
    }

    return res;
};

document.getElementById("permutation-sequence").innerHTML =
    // getPermutation(3, 4);
    getPermutation(4, 9);
