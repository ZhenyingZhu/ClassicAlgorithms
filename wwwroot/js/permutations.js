/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    let res = new Array();
    premuteNS.helper(nums, [], res);
    return res;
};

const premuteNS = {
    helper: function(nums, cur, res) {
        if (nums.length === 0) {
            res.push(JSON.parse(JSON.stringify(cur)));
            return;
        }

        for (let i = 0; i < nums.length; i++) {
            let val = nums[i];
            cur.push(val);
            nums.splice(i, 1);
            this.helper(nums, cur, res);
            cur.pop();
            nums.splice(i, 0, val);
        }
    }
};

document.getElementById("permutations").innerHTML =
    // permute([1,2,3]);
    permute([1,2,3]);
