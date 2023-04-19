/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let m = matrix.length;
    let n = matrix[0].length;
    let st = 0;
    let ed = m * n - 1;
    while (st + 1 < ed) {
        let md = Math.floor((st + ed) / 2);
        let val = searchMatrixNS.getIdxVal(matrix, md);
        if (val === target) {
            return true;
        }

        if (val > target) {
            ed = md;
        } else {
            st = md;
        }
    }

    if (searchMatrixNS.getIdxVal(matrix, st) === target) {
        return true;
    }

    return (searchMatrixNS.getIdxVal(matrix, ed) === target);
};

const searchMatrixNS = {
    getIdxVal: function(matrix, idx) {
        let n = matrix[0].length;
        let x = Math.floor(idx / n);
        let y = idx % n;
        return matrix[x][y];
    }
};

document.getElementById("search-a-2d-matrix").innerHTML =
    // searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 3);
    searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 13);
