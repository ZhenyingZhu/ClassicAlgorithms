/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    let directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    let bounds = [n - 1, n - 1, 0, 1];

    let matrix = new Array(n);
    for (let i = 0; i < n; i++) {
        matrix[i] = new Array(n);
    }

    let cur = 0;
    let x = 0;
    let y = 0;
    for (let i = 1; i <= n * n; i++) {
        matrix[x][y] = i;

        let direction = directions[cur];
        if (direction[0] === 0) {
            if (y === bounds[cur]) {
                if (cur < 2) {
                    bounds[cur]--;
                } else {
                    bounds[cur]++;
                }
                cur = (cur + 1) % 4;
            }
        } else {
            if (x === bounds[cur]) {
                if (cur < 2) {
                    bounds[cur]--;
                } else {
                    bounds[cur]++;
                }
                cur = (cur + 1) % 4;
            }
        }

        x += directions[cur][0];
        y += directions[cur][1];
    }

    return matrix;
};

document.getElementById("spiral-matrix-ii").innerHTML =
    generateMatrix(4);
