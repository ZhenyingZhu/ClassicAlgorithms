/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    // First find the rotated point.
    let st = 0;
    let ed = nums.length - 1;
    let offset = -1;
    while (st + 1 < ed) {
        let md = Math.floor((st + ed) / 2);
        // console.log("st: " + st + " ed: " + ed + " md: " + md);
        if (nums[st] < nums[ed]) {
            offset = st;
            break;
        } else if (nums[md] < nums[st]) {
            ed = md;
        } else {
            st = md;
        }
    }
    if (nums[st] > nums[ed]) {
        offset = ed;
    } else {
        offset = st;
    }

    // console.log("offset: " + offset);

    // Use offset to change the index
    st = 0;
    ed = nums.length - 1;
    while (st + 1 < ed) {
        let md = Math.floor((st + ed) / 2);
        let val = nums[convertIdx(md, offset, nums.length)];
        if (val === target) {
            return convertIdx(md, offset, nums.length);
        } else if (val > target) {
            ed = md;
        } else {
            st = md;
        }
    }

    if (nums[convertIdx(st, offset, nums.length)] === target) {
        return convertIdx(st, offset, nums.length);
    } else if (nums[convertIdx(ed, offset, nums.length)] === target) {
        return convertIdx(ed, offset, nums.length);
    } else {
        return -1;
    }
};

const convertIdx = function(idx, offset, totalLength) {
    return (idx + offset) % totalLength;
};

document.getElementById("search-in-rotated-sorted-array").innerHTML =
    search([4,5,6,7,0,1], 6);
