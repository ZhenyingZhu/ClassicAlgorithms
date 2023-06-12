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
        let jStack = [-1];
        let hStack = [-1];
        let j = 0;
        while (j < n) {

        }
    }
};

document.getElementById("maximal-rectangle").innerHTML =
    // largestRectangleArea([2,1,5,5,6,2,3]);
    // largestRectangleArea([2,4]);
    // largestRectangleArea([2,1,2]);
    // largestRectangleArea([0,9]);
    largestRectangleArea([0,1,0,1]);
