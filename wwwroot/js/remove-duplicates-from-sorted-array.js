/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    if (nums.length <= 1) {
        return nums.length;
    }

    let k = 1;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] !== nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }

    return k;
};

let nums = [0,0,1,1,1,2,2,3,3,4];
let k = removeDuplicates(nums);
document.getElementById("remove-duplicates-from-sorted-array").innerHTML = [k, nums];
