/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    nums.sort(function(a, b) {
        return a - b
    });

    let diff = Number.MAX_SAFE_INTEGER;
    let res = Number.MAX_SAFE_INTEGER;
    for (let i = 0; i < nums.length - 2; i++) {
        let st = i + 1;
        let ed = nums.length - 1;
        while (st < ed) {
            // overflow? But since JS is not type safe, it might not be a problem.
            let val = nums[i] + nums[st] + nums[ed];
            if (Math.abs(val - target) < diff) {
                diff = Math.abs(val - target);
                res = val;
            }

            if (val === target) {
                return target;
            } else if (val > target) {
                ed--;
            } else {
                st++;
            }
        }
    }

    return res;
};

document.getElementById("3sum-closest").innerHTML = threeSumClosest([-1, 2, 1, -4], 1);