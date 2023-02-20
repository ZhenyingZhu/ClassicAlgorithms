/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    candidates.sort(function(a, b) { return a - b; });
    let res = [];
    combinationSum2NS.helper(candidates, 0, target, [], res);
    return res;
};

const combinationSum2NS = {
    helper: function(candidates, st, target, arr, res) {
        if (target === 0) {
            res.push([].concat(arr));
            return;
        }

        if (st === candidates.length) {
            return;
        }

        for (let i = st; i < candidates.length && candidates[i] <= target; i++) {
            if (i > st && candidates[i] === candidates[i - 1]) {
                continue;
            }

            arr.push(candidates[i]);
            this.helper(candidates, i + 1, target - candidates[i], arr, res);
            arr.pop();
        }
    }
};

document.getElementById("combination-sum-ii").innerHTML =
    // combinationSum2([10,1,2,7,6,1,5], 8);
    combinationSum2([1, 1, 1], 2);
