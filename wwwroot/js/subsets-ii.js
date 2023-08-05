/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
    nums.sort(function(a, b) { return a - b; });
    let res = [];
    subsetsWithDupNS.helper(nums, 0, [], res);

    // for (let i = 0; i < res.length; i++) { console.log(res[i]); console.log("end: " + i); }
    return res;
};

const subsetsWithDupNS = {
    helper: function(nums, st, cur, res) {
        res.push(JSON.parse(JSON.stringify(cur)));

        for (let i = st; i < nums.length; i++) {
            if (i !== st && nums[i] === nums[i - 1]) {
                continue;
            }

            cur.push(nums[i]);
            this.helper(nums, i + 1, cur, res);
            cur.pop();
        }
    }
};

document.getElementById("subsets-ii").innerHTML =
    subsetsWithDup([1, 2, 2, 3, 3]);