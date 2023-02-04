/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    if (nums.length === 0) {
        return [-1, -1];
    }

    let st = searchRangeWithBound(nums, target, true);
    if (st === -1) {
        return [-1, -1];
    }

    let ed = searchRangeWithBound(nums, target, false);
    return [st, ed];
};

const searchRangeWithBound = function(nums, target, isLower) {
    let st = 0;
    let ed = nums.length - 1;
    while (st + 1 < ed) {
        let md = Math.floor((st + ed) / 2);
        if (isLower) {
            if (nums[md] >= target) {
                ed = md;
            } else {
                st = md;
            }
        } else {
            if (nums[md] > target) {
                ed = md;
            } else {
                st = md;
            }
        }
    }

    if (isLower) {
        if (nums[st] === target) {
            return st;
        } else if (nums[ed] === target) {
            return ed;
        } else {
            return -1;
        }
    } else {
        if (nums[ed] === target) {
            return ed;
        } else if (nums[st] === target) {
            return st;
        } else {
            return -1;
        }
    }
};

document.getElementById("find-first-and-last-position-of-element-in-sorted-array").innerHTML =
    // searchRange([5,7,7,8,8,10], 8);
    // searchRange([5,7,7,8,8,10], 6);
    searchRange([], 0);
