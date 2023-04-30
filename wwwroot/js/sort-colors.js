/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    let left = 0;
    let right = nums.length - 1;
    let i = 0;
    while (i <= right) {
        if (nums[i] === 0) {
            if (i === left) {
                i++;
            } else {
                sortColorsNS.swap(nums, i, left);
            }
            left++;
        } else if (nums[i] === 1) {
            i++;
        } else {
            sortColorsNS.swap(nums, i, right);
            right--;
        }
    }
};

const sortColorsNS = {
    swap: function(nums, i, j) {
        if (nums[i] === nums[j]) {
            return;
        }

        let k = nums[i];
        nums[i] = nums[j];
        nums[j] = k;
    }
};

const sortColorsNSTest = {
    sortColorsTest: function() {
        let nums =
            // [2,0,2,1,1,0];
            [2,0,1];
        sortColors(nums);
        return nums;
    }
};

document.getElementById("sort-colors").innerHTML =
    sortColorsNSTest.sortColorsTest();
