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
        if (nums[md] === target) {
            return true;
        }

        if (nums[st] < nums[ed]) {
            if (nums[md] > target) {
                ed = md;
            } else {
                st = md;
            }
        } else if (nums[st] > nums[ed]) {
            if (nums[md] > nums[st]) {
                if (nums[md])
            }
        }
    }
};

document.getElementById("search-in-rotated-sorted-array-ii").innerHTML =
    search([2,5,6,0,0,1,2], 0);
