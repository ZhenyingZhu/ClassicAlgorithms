/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    // If multiple candidates add up to 0, there would be inf res. So it is not possible.
    // Avoid keep adding the same negative candidate. But negative candidate should still be added. Consider [-1, 2] t=0.
    // but because the question avoids negative num, so no need to worry about it.
    candidates.sort(function(a, b) { return a - b; });
    let res = [];
    combinationSumNS.combinationSumRecur(candidates, 0, target, [], res);
    return res;
};

const combinationSumNS = {
    combinationSumRecur: function(candidates, st, target, comb, res) {
        if (target === 0) {
            res.push([].concat(comb));
            return;
        }

        if (st === candidates.length) {
            return;
        }

        if (target < candidates[st]) {
            return;
        }

        comb.push(candidates[st]);
        this.combinationSumRecur(candidates, st, target - candidates[st], comb, res);
        comb.pop();
        this.combinationSumRecur(candidates, st + 1, target, comb, res);
    }
};

document.getElementById("combination-sum").innerHTML =
    combinationSum([2,3,6,7], 7);
