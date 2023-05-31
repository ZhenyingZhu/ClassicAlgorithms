/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
    // area = minHeight(x, y) * (y - x + 1)
    // minHeight(x, y) = min(minHeight(x, y - 1), height(y))
    let m = heights.length;
    if (m === 0) {
        return 0;
    }

    let matrix = new Array(m);
    for (let i = 0; i < m; i++) {
        matrix[i] = new Array(m);
    }

    let maxArea = 0;
    for (let i = 0; i < m; i++) {
        for (let j = i; j < m; j++) {
            if (j === i) {
                matrix[i][j] = heights[i];
            } else {
                matrix[i][j] = Math.min(matrix[i][j - 1], heights[j]);
            }

            maxArea = Math.max(maxArea, matrix[i][j] * (j - i + 1));
        }
    }

    return maxArea;
};

document.getElementById("largest-rectangle-in-histogram").innerHTML =
    // largestRectangleArea([2,1,5,6,2,3]);
    largestRectangleArea([2,4]);
