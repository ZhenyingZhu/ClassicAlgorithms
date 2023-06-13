/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalRectangle = function(matrix) {
    // Use 2 DPs.
    let m = matrix.length;
    let n = matrix[0].length;

    let heights = new Array(m);
    for (let i = 0; i < m; i++) {
        heights[i] = new Array(n);
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === "0") {
                heights[i][j] = 0;
            } else if (i === 0) {
                heights[i][j] = 1;
            } else {
                heights[i][j] = heights[i - 1][j] + 1;
            }
        }
    }

    let maxArea = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            let minHeight = heights[i][j];
            if (minHeight === 0) {
                continue;
            }

            for (let k = j; k >= 0 && heights[i][k] > 0; k--) {
                minHeight = Math.min(minHeight, heights[i][k]);
                maxArea = Math.max(maxArea, minHeight * (j - k + 1));
            }
        }
    }

    return maxArea;
};

document.getElementById("maximal-rectangle").innerHTML =
    // maximalRectangle([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]);
    maximalRectangle([["1"]]);
