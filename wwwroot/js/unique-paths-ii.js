/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    let m = obstacleGrid.length;
    let n = obstacleGrid[0].length;
    let matrix = new Array(m);
    for (let i = 0; i < m; i++) {
        matrix[i] = new Array(n);
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (obstacleGrid[i][j] === 1) {
                matrix[i][j] = 0;
            } else if (i === 0 && j === 0) {
                matrix[i][j] = 1;
            } else if (i === 0) {
                matrix[i][j] = matrix[i][j - 1];
            } else if (j === 0) {
                matrix[i][j] = matrix[i - 1][j];
            } else {
                matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j];
            }
        }
    }

    return matrix[m - 1][n - 1];
};

document.getElementById("unique-paths-ii").innerHTML =
    // uniquePathsWithObstacles([[0,0,0],[0,1,0],[0,0,0]]);
    uniquePathsWithObstacles([[0,1],[0,0]]);
