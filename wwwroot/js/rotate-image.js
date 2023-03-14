/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let n = matrix.length;
    for (let i = 0; i < Math.floor(n / 2); i++) {
        for (let j = i; j < n - i - 1; j++) {
            let ru = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = matrix[i][j];

            let rd = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = ru;

            let ld = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = rd;

            matrix[i][j] = ld;
        }
    }
};

// let matrix = [[1,2,3],[4,5,6],[7,8,9]];
let matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]];
rotate(matrix);
document.getElementById("rotate-image").innerHTML = matrix;
