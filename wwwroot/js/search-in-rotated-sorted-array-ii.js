/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target) {
    let st = 0;
    let ed = nums.length - 1;
    while (st + 1 < ed) {
        let md = Math.floor((st + ed) / 2);
        if (nums[md] === target || nums[st] === target || nums[ed] === target) {
            return true;
        }

        if (nums[st] === nums[ed]) {
            st++;
            ed--;
        } else if (nums[st] < nums[ed]) {
            // definitely no rotate in between.
            if (nums[md] > target) {
                ed = md;
            } else {
                st = md;
            }
        } else if (nums[st] < nums[md]) {
            // definitely no rotate in first half.
            if (nums[md] < target) {
                st = md;
            } else if (nums[st] < target) {
                ed = md;
            } else {
                st = md;
            }
        } else if (nums[md] < nums[ed]) {
            // definitely no rotate in second half.
            if (target < nums[md]) {
                ed = md;
            } else if (nums[ed] < target) {
                ed = md;
            } else {
                st = md;
            }
        } else {
            st++;
            ed--;
        }
    }

    return nums[st] === target || nums[ed] === target;
};

document.getElementById("search-in-rotated-sorted-array-ii").innerHTML =
    // search([2,5,6,0,0,1,2], 0);
    // search([2,5,6,0,0,1,2], 3);
    search([3,1,1], 0);