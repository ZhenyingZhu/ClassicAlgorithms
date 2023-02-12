/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
    let rows = new Array(9);
    let cols = new Array(9);
    let blocks = new Array(9);

    for (let i = 0; i < 9; i++) {
        rows[i] = new Set();
        cols[i] = new Set();
        blocks[i] = new Set();
    }

    let empties = [];
    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length; j++) {
            if (board[i][j] === '.') {
                empties.push(i * 9 + j);
            } else {
                let n = Number(board[i][j]);
                rows[i].add(n);
                cols[j].add(n);
                blocks[Math.floor(i / 3) * 3 + Math.floor(j / 3)].add(n);
            }
        }
    }

    return solveSudokuNS.solveSudokuIter(board, empties, 0, rows, cols, blocks);
};

const solveSudokuNS = {
    solveSudokuIter: function(board, empties, idx, rows, cols, blocks) {
        if (idx === empties.length) {
            return true;
        }
    
        let cur = empties[idx];
        let i = Math.floor(cur / 9);
        let j = cur % 9;
        let b = Math.floor(i / 3) * 3 + Math.floor(j / 3);
        // console.log("cur: " + cur + ", i: " + i + ", j: " + j + ", b: " + b);

        for (let x = 1; x <= 9; x++) {
            if (rows[i].has(x) || cols[j].has(x) || blocks[b].has(x)) {
                continue;
            }
    
            board[i][j] = x.toString();
            rows[i].add(x);
            cols[j].add(x);
            blocks[b].add(x);
    
            if (solveSudokuNS.solveSudokuIter(board, empties, idx + 1, rows, cols, blocks)) {
                return true;
            }
    
            rows[i].delete(x);
            cols[j].delete(x);
            blocks[b].delete(x);
        }
    
        return false;
    }
};

// let board = [
//     ["5","3",".",".","7",".",".",".","."],
//     ["6",".",".","1","9","5",".",".","."],
//     [".","9","8",".",".",".",".","6","."],
//     ["8",".",".",".","6",".",".",".","3"],
//     ["4",".",".","8",".","3",".",".","1"],
//     ["7",".",".",".","2",".",".",".","6"],
//     [".","6",".",".",".",".","2","8","."],
//     [".",".",".","4","1","9",".",".","5"],
//     [".",".",".",".","8",".",".","7","9"]];
let board = [
    [".",".","9","7","4","8",".",".","."],
    ["7",".",".",".",".",".",".",".","."],
    [".","2",".","1",".","9",".",".","."],
    [".",".","7",".",".",".","2","4","."],
    [".","6","4",".","1",".","5","9","."],
    [".","9","8",".",".",".","3",".","."],
    [".",".",".","8",".","3",".","2","."],
    [".",".",".",".",".",".",".",".","6"],
    [".",".",".","2","7","5","9",".","."]];
solveSudoku(board);
document.getElementById("sudoku-solver").innerHTML = board;
