/**
 * @param {number[]} height
 * @return {number}
 */
const maxAreaBruteForce = function(height) {
    let max = 0;
    for (let i = 0; i < height.length - 1; i++) {
        for (let j = i + 1; j < height.length; j++) {
            let area = (j - i) * Math.min(height[i], height[j]);
            max = Math.max(area, max);
        }
    }

    return max;
};

/**
 * @param {number[]} height
 * @return {number}
 */
 const maxArea = function(height) {
    // For each height, find the furtherest height that is longer than it.
    // Use two pointers.
    if (height=== null || height.length <= 1) {
        return 0;
    }

    let max = 0;
    let i = 0;
    let j = height.length - 1;
    while (i < j) {
        let area = (j - i) * Math.min(height[i], height[j]);
        max = Math.max(max, area);

        if (height[i] > height[j]) {
            j--;
        } else {
            i++;
        }
    }

    return max;
};

document.getElementById("container-with-most-water").innerHTML = maxArea([1,3,2,5,25,24,5]);