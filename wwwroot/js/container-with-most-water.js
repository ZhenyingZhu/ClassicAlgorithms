/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    // For each height, find the furtherest height that is longer than it.
    let max = 0;
    for (let i = 0; i < height.length - 1; i++) {
        for (let j = i + 1; j < height.length; j++) {
            let area = (j - i) * Math.min(height[i], height[j]);
            max = Math.max(area, max);
        }
    }

    return max;
};

document.getElementById("container-with-most-water").innerHTML = maxArea([1,8,6,2,5,4,8,3,7]);