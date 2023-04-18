/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    let m = matrix.length;
    let n = matrix[0].length;
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (matrix[i][j] === 0) {
                matrix[i][0] = (matrix[i][0] === 0 ? 0 : 'd');
                matrix[0][j] = (matrix[0][j] === 0 ? 0 : 'd');
            }
        }
    }

    console.log(JSON.parse(JSON.stringify(matrix)));

    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (matrix[i][0] === 'd' || matrix[i][0] === 0 || matrix[0][j] === 'd' || matrix[0][j] === 0) {
                matrix[i][j] = 0;
            }
        }
    }

    let firstCol = false;
    for (let i = 0; i < m; i++) {
        if (matrix[i][0] === 0) {
            firstCol = true;
            break;
        }
    }
    for (let i = 1; i < m; i++) {
        if (firstCol || matrix[i][0] === 'd') {
            matrix[i][0] = 0;
        }
    }

    let firstRow = false;
    for (let j = 0; j < n; j++) {
        if (matrix[0][j] === 0) {
            firstRow = true;
            break;
        }
    }
    for (let j = 1; j < n; j++) {
        if (firstRow || matrix[0][j] === 'd') {
            matrix[0][j] = 0;
        }
    }

    if (firstRow || firstCol) {
        matrix[0][0] = 0;
    }
};

const setZeroesNS = {
    setZeroesTest: function() {
        let matrix =
            [[0,1,2,0],[3,4,5,2],[1,3,1,5]];
            // [[1,2,3,4],[5,0,7,8],[0,10,11,12],[13,14,15,0]];

        setZeroes(matrix);
        return matrix;
    },
};

document.getElementById("set-matrix-zeroes").innerHTML =
    setZeroesNS.setZeroesTest();
