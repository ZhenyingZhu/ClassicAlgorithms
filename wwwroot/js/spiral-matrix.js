/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    let m = matrix.length;
    let n = matrix[0].length;

    let up = 1; // edge case.
    let down = m - 1;
    let left = 0;
    let right = n - 1;

    let directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    let curDirection = 0;

    let res = [];
    let x = 0;
    let y = 0;
    for (let step = 0; step < m * n; step++) {
        res.push(matrix[x][y]);
        if (curDirection === 0 && y === right) {
            right -= 1;
            curDirection = 1;
        } else if (curDirection === 1 && x === down) {
            down -= 1;
            curDirection = 2;
        } else if (curDirection === 2 && y === left) {
            left += 1;
            curDirection = 3;
        } else if (curDirection === 3 && x === up) {
            up += 1;
            curDirection = 0;
        }
        x += directions[curDirection][0];
        y += directions[curDirection][1];
    }

    return res;
};

document.getElementById("spiral-matrix").innerHTML =
    // spiralOrder([[1,2,3],[4,5,6],[7,8,9]]);
    spiralOrder([[1,2,3,4],[5,6,7,8],[9,10,11,12]]);
