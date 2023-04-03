/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    let m = grid.length;
    let n = grid[0].length;

    let matrix = new Array(m);
    for (let i = 0; i < m; i++) {
        matrix[i] = new Array(n);
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 && j === 0) {
                matrix[i][j] = grid[i][j];
            } else if (i === 0) {
                matrix[i][j] = matrix[i][j - 1] + grid[i][j];
            } else if (j === 0) {
                matrix[i][j] = matrix[i - 1][j] + grid[i][j];
            } else {
                matrix[i][j] = grid[i][j] + Math.min(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }

    return matrix[m - 1][n - 1];
};

document.getElementById("minimum-path-sum").innerHTML =
    // minPathSum([[1,3,1],[1,5,1],[4,2,1]]);
    minPathSum([[1,2,3],[4,5,6]]);
