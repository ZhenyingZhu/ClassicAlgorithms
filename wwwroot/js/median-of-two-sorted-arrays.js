const findKthNum = function(k, nums1, st1, nums2, st2) {
    // console.log("find " + k + " in nums1 " + st1 + ", nums2 " + st2);
    if (st1 == nums1.length) {
        return nums2[st2 + k - 1];
    } else if (st2 == nums2.length) {
        return nums1[st1 + k - 1];
    }

    if (k == 1) {
        return Math.min(nums1[st1], nums2[st2]);
    }

    let half = Math.min(Math.floor(k / 2), nums1.length - st1, nums2.length - st2);
    if (nums1[st1 + half - 1] < nums2[st2 + half - 1]) {
        return findKthNum(k - half, nums1, st1 + half, nums2, st2);
    } else if (nums1[st1 + half - 1] > nums2[st2 + half - 1]) {
        return findKthNum(k - half, nums1, st1, nums2, st2 + half);
    } else {
        return findKthNum(k - half, nums1, st1 + half, nums2, st2);
    }
};

const findMedianSortedArrays = function(nums1, nums2) {
    // if m+n is even, return (arr[(m+n)/2] + arr[(m+n)/2 + 1])/2
    // if m+n is odd, return arr[(m+n)/2 + 1]
    let half = Math.floor((nums1.length + nums2.length) / 2);
    if ((nums1.length + nums2.length) % 2 === 0) {
        let even = findKthNum(half, nums1, 0, nums2, 0);
        // console.log("even: " + even);
        let odd = findKthNum(half + 1, nums1, 0, nums2, 0);
        // console.log("odd: " + odd);
        return (even + odd) / 2;
    } else {
        return findKthNum(half + 1, nums1, 0, nums2, 0);
    }
};

let nums1 = [1];
let nums2 = [2,3,4,5,6];
document.getElementById("median-of-two-sorted-arrays").innerHTML = findMedianSortedArrays(nums1, nums2);