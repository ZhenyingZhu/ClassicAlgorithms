/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let rightMax = 0;
    let rightMaxs = new Array(height.length);
    for (let i = height.length - 1; i >= 0; i--) {
        rightMax = Math.max(rightMax, height[i]);
        rightMaxs[i] = rightMax;
    }

    let leftMax = 0;
    let res = 0;
    for (let i = 0; i < height.length; i++) {
        leftMax = Math.max(leftMax, height[i]);
        let heightMin = Math.min(leftMax, rightMaxs[i]);
        if (heightMin > height[i]) {
            res += heightMin - height[i];
        }
    }

    return res;
};

document.getElementById("trapping-rain-water").innerHTML =
    // trap([0,1,0,2,1,0,1,3,2,1,2,1]);
    trap([4,2,0,3,2,5]);
