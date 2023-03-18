/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
    let left = new Array(2 * n - 1);
    let right = new Array(2 * n - 1);
    for (let i = 0; i < 2 * n - 1; i++) {
        left[i] = false;
        right[i] = false;
    }

    return totalNQueensNS.helper([], n, left, right);
};

const totalNQueensNS = {
    helper: function(cur, n, left, right) {
        if (cur.length === n) {
            return 1;
        }

        let res = 0;
        let x = cur.length;
        for (let y = 0; y < n; y++) {
            if (cur.includes(y)) {
                continue;
            }

            let leftIdx = x - y + n - 1;
            let rightIdx = x + y;
            if (left[leftIdx] || right[rightIdx]) {
                continue;
            }

            left[leftIdx] = true;
            right[rightIdx] = true;
            cur.push(y);
            res += this.helper(cur, n, left, right);
            cur.pop();
            left[leftIdx] = false;
            right[rightIdx] = false;
        }

        return res;
    }
};

document.getElementById("n-queens-ii").innerHTML =
    //totalNQueens(4);
    totalNQueens(6);
