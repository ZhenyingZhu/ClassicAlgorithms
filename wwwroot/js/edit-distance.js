/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    let m = word1.length;
    let n = word2.length;
    let matrix = new Array(m + 1);
    for (let i = 0; i <= m; i++) {
        matrix[i] = new Array(n + 1);
        matrix[i][0] = i;
    }
    for (let j = 1; j <= n; j++) {
        matrix[0][j] = j;
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (word1[i] === word2[j]) {
                matrix[i + 1][j + 1] = matrix[i][j];
            } else {
                matrix[i + 1][j + 1] = Math.min(matrix[i][j], Math.min(matrix[i][j + 1], matrix[i + 1][j])) + 1;
            }
        }
    }

    return matrix[m][n];
};

document.getElementById("edit-distance").innerHTML =
    // minDistance("horse", "ros");
    minDistance("intention", "execution");
