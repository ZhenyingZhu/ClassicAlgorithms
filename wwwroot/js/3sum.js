/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    if (nums.length < 3) {
        return [];
    }

    // sort
    let res = [];

    for (let i = 0; i < nums.length - 2; i++) {
        let target = -nums[i];
        let st = i + 1;
        let ed = nums.lengh - 1;
        while (st < ed) {
            if (nums[st] + nums[ed] === target) {

            }
        }
    }
};

document.getElementById("3sum").innerHTML = threeSum([-1,0,1,2,-1,-4]);