/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    let max = 0;
    for (let i = 0; i < nums.length && i <= max; i++) {
        max = Math.max(max, nums[i] + i);
    }

    return max >= nums.length - 1;
};

document.getElementById("jump-game").innerHTML =
    // canJump([2,3,1,1,4]);
    // canJump([3,2,1,0,4]);
    canJump([2,0,0]);
