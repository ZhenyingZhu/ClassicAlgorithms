/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    if (nums.length === 0) {
        return 0;
    }

    let k = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            nums[k++] = nums[i];
        }
    }

    return k;
};

let nums2 = [3,2,2,3];
let len = removeElement(nums2, 2);
document.getElementById("remove-element").innerHTML = [len, nums2];