/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    let steps = new Array(nums.length);
    steps[0] = 0;

    for (let i = 0; i < nums.length - 1; i++) {
        let step = steps[i] + 1;
        for (let j = i + 1; j <= i + nums[i] && j < nums.length; j++) {
            if (steps[j] === undefined) {
                steps[j] = step;
            } else {
                steps[j] = Math.min(steps[j], step);
            }
        }
    }

    return steps[nums.length - 1];
};

document.getElementById("jump-game-ii").innerHTML =
    // jump([2,3,1,1,4]);
    jump([3,3,1,1,4]);
