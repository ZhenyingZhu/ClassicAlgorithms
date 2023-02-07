/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    if (nums.length === 0) {
        return 0;
    }

    let st = 0;
    let ed = nums.length - 1;
    while (st + 1 < ed) {
        let md = Math.floor((st + ed) / 2);
        if (nums[md] === target) {
            return md;
        } else if (nums[md] < target) {
            st = md;
        } else {
            ed = md;
        }
    }

    if (nums[st] >= target) {
        return st;
    } else if (nums[ed] >= target) {
        return ed;
    } else {
        return ed + 1;
    }
};

document.getElementById("search-insert-position").innerHTML =
    // searchInsert([1,3,5,6], 2);
    searchInsert([1,3,5,6], 7);
