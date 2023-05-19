/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let st = 1;
    let pre = nums[0];
    let second = false;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] !== pre) {
            nums[st++] = nums[i];
            pre = nums[i];
            second = false;
        } else if (!second) {
            nums[st++] = nums[i];
            second = true;
        }
    }

    return st;
};

const removeDuplicatesTest = {
    test: function() {
        let nums =
            // [1,1,1,2,2,3];
            [0,0,1,1,1,1,2,3,3];
        let k = removeDuplicates(nums);
        return nums.slice(0, k);
    }
};

document.getElementById("remove-duplicates-from-sorted-array-ii").innerHTML =
    removeDuplicatesTest.test();
