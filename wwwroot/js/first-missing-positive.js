/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    firstMissingPositiveNS.bucketSort(nums);
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== i + 1) {
            return i + 1;
        }
    }
    return nums.length + 1;
};

const firstMissingPositiveNS = {
    bucketSort: function(nums) {
        for (let i = 0; i < nums.length; i++) {
            while (nums[i] > 0 && nums[i] <= nums.length && nums[i] !== i + 1) {
                let val = nums[i];
                let pos = val - 1;
                // avoid inf loop.
                if (nums[pos] === val) {
                    break;
                }

                nums[i] = nums[pos];
                nums[pos] = val;
            }
        }
    }
};

document.getElementById("first-missing-positive").innerHTML =
    // firstMissingPositive([3,4,-1,1]);
    firstMissingPositive([]);
