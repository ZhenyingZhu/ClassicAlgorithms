/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    let res = [];
    subsetsNS.helper(nums, 0, [], res);
    return res;
};

const subsetsNS = {
    helper: function(nums, i, arr, res) {
        if (i === nums.length) {
            res.push(JSON.parse(JSON.stringify(arr)));
            return;
        }

        this.helper(nums, i + 1, arr, res);

        arr.push(nums[i]);
        this.helper(nums, i + 1, arr, res);
        arr.pop();
    },
};

document.getElementById("subsets").innerHTML =
    subsets([1,2,3]);
