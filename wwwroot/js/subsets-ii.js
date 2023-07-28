/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
    nums.sort(function(a, b) { return a - b; });
    let res = [];
    subsetsWithDupNS.helper(nums, 0, [], res);

    for (let i = 0; i < res.length; i++) { console.log(res[i]); console.log("end"); }
    return res;
};

const subsetsWithDupNS = {
    helper: function(nums, st, cur, res) {
        if (st === nums.length) {
            res.push(JSON.parse(JSON.stringify(cur)));
            return;
        }

        cur.push(nums[st]);
        let next = st + 1;
        while (next < nums.length && nums[next] === nums[st]) {
            next++;
        }
        this.helper(nums, next, cur, res);

        cur.pop();

        this.helper(nums, st + 1, cur, res);
    }
};

document.getElementById("subsets-ii").innerHTML =
    subsetsWithDup([1, 2, 2]);