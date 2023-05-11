/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
    let res = [];
    combineNS.combineHelper(1, n, k, [], res);
    return res;
};

const combineNS = {
    combineHelper: function(st, n, k, arr, res) {
        if (arr.length === k) {
            res.push(JSON.parse(JSON.stringify(arr)));
            return;
        }

        for (let i = st; i <= n; i++) {
            arr.push(i);
            this.combineHelper(i + 1, n, k, arr, res);
            arr.pop();
        }
    }
};

document.getElementById("combinations").innerHTML =
    combine(4, 2);
