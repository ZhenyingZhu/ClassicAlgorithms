/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    let matrix = new Array(m);
    for (let i = 0; i < m; i++) {
        matrix[i] = new Array(n);
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 || j === 0) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }
    }

    return matrix[m - 1][n - 1];
};

document.getElementById("unique-paths").innerHTML =
    // uniquePaths(3, 2);
    uniquePaths(3, 7);
