/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    candidates.sort(function(a, b) { return a - b; });
    
};

document.getElementById("combination-sum").innerHTML = combinationSum([2,3,6,7], 7);
