/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let cur = m + n - 1;
    let i = m - 1;
    let j = n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[cur--] = nums1[i--];
        } else {
            nums1[cur--] = nums2[j--];
        }
    }

    while (j >= 0) {
        nums1[cur--] = nums2[j--];
    }
};

const mergeNS = {
    testMain: function() {
        //let nums1 = [1,2,3,0,0,0];
        //merge(nums1, 3, [2,5,6], 3);
        let nums1 = [1];
        merge(nums1, 1, [], 0);
        return nums1;
    }
};

document.getElementById("merge-sorted-array").innerHTML =
    mergeNS.testMain();