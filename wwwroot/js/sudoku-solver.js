/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
    let rows = new Array[9];
    let cols = new Array[9];
    let blocks = new Array[9];
    let empties = [];

    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length; j++) {
            if (board[i][j] === '.') {
                empties.push(i * 9 + j);
            } else {
                createOrInsertVal(rows, i, board[i][j]);
                createOrInsertVal(cols, j, board[i][j]);
                createOrInsertVal(blocks, Math.floor(i / 3) * 3 + Math.floor(j / 3), board[i][j]);
            }
        }
    }

    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length; j++) {
            if (board[i][j] === '.') {
                possibles[i * 9 + j] = [];
            }
        }
    }
};

const createOrInsertVal = function(arr, idx, val) {
    if (arr[idx] === undefined) {
        arr[idx] = new Set();
    }
    arr[idx].add(val);
};

document.getElementById("search-insert-position").innerHTML =
    // searchInsert([1,3,5,6], 2);
    searchInsert([1,3,5,6], 7);
