/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function(n) {
    let left = new Array(2 * n - 1);
    let right = new Array(2 * n - 1);
    for (let i = 0; i < 2 * n - 1; i++) {
        left[i] = false;
        right[i] = false;
    }

    let res = [];
    let cur = []; // only record y.
    solveNQueensNS.helper(cur, n, left, right, res);
    return res;
};

const solveNQueensNS = {
    helper: function(cur, n, left, right, res) {
        if (cur.length === n) {
            res.push(this.craftRes(cur, n));
            return;
        }

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
            this.helper(cur, n, left, right, res);
            cur.pop();
            left[leftIdx] = false;
            right[rightIdx] = false;
        }
    },

    craftRes: function(cur, n) {
        let res = [];
        for (let i = 0; i < cur.length; i++) {
            let col = "";
            for (let j = 0; j < cur[i]; j++) {
                col += ".";
            }

            col += "Q";

            for (let j = cur[i] + 1; j < n; j++) {
                col += ".";
            }

            res.push(col);
        }
        return res;
    }
};

document.getElementById("n-queens").innerHTML =
    //solveNQueens(4);
    solveNQueens(6);
