/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    if (nums.length === 0) {
        return 0;
    }

    let sum = nums[0];
    let max = nums[0];
    for (let i = 1; i < nums.length; i++) {
        if (sum < 0) {
            sum = 0;
        }
        sum += nums[i];
        max = Math.max(sum, max);
    }

    return max;
};

document.getElementById("maximum-subarray").innerHTML =
    // maxSubArray([-2,1,-3,4,-1,2,1,-5,4]);
    // maxSubArray([5,4,-1,7,8]);
    maxSubArray([-2,1]);
