/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    nums.sort(function(a, b) { return a - b; });

    let res = [];
    premuteUniqueNS.helper(nums, [], res);
    return res;
};

const premuteUniqueNS = {
    helper: function(nums, cur, res) {
        if (nums.length === 0) {
            res.push(JSON.parse(JSON.stringify(cur)));
            return;
        }

        let i = 0;
        while (i < nums.length) {
            let val = nums[i];
            nums.splice(i, 1);
            cur.push(val);
            this.helper(nums, cur, res);
            cur.pop();
            nums.splice(i, 0, val);

            while(nums[i] === val) {
                i++;
            }
        }
    }
};

document.getElementById("permutations-ii").innerHTML =
    permuteUnique([1,1,2]);
