/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    // candidates.sort(function(a, b) { return a - b; });
    
};

const combinationSumNS = {
    combinationSumIter: function(candidates, idx, target, cur, res) {
        // If multiple numbers add up to 0, how to return?
        if (idx === candidates.length) {
            return;
        }

        cur.add(candidates[idx]);
        if (candidates[idx] === target) {
            // deep copy?
            res.add(cur);
        }
        this.combinationSumIter(candidates, idx, target - candidates[idx], cur, res);

        cur.pop();
        this.combinationSumIter(candidates, idx + 1, target - candidates[idx], cur, res);
    }
};

document.getElementById("combination-sum").innerHTML = combinationSum([2,3,6,7], 7);
