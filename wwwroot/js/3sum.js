/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    if (nums.length < 3) {
        return [];
    }

    nums.sort(function(a, b) { return a - b });
    console.log(nums);

    let res = [];

    for (let i = 0; i < nums.length - 2; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }

        let target = -nums[i];
        console.log("Target " + target);

        let st = i + 1;
        let ed = nums.length - 1;
        while (st < ed) {
            console.log(nums[i] + " " + nums[st] + " " + nums[ed]);
            if (nums[st] + nums[ed] === target) {
                res.push([nums[i], nums[st], nums[ed]]);
                st++;
            } else if (nums[st] + nums[ed] > target) {
                ed--;
            } else {
                st++;
            }
        }
    }

    return res;
};

document.getElementById("3sum").innerHTML = threeSum([-1,0,1,2,-1,-4]);