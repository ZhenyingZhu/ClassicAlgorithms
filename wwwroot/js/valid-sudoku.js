/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    let rows = new Array(9);
    let cols = new Array(9);
    let cells = new Array(9);
    for (let i = 0; i < 9; i++) {
        rows[i] = new Set();
        cols[i] = new Set();
        cells[i] = new Set();
    }

    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            let cur = board[i][j];
            if (cur === '.') {
                continue;
            }

            if (rows[i].has(cur) || cols[j].has(cur)) {
                return false;
            }

            let cell = Math.floor(i / 3) * 3 + Math.floor(j / 3);
            if (cells[cell].has(cur)) {
                return false;
            }

            rows[i].add(cur);
            cols[j].add(cur);
            cells[cell].add(cur);
        }
    }

    return true;
};

document.getElementById("valid-sudoku").innerHTML =
    //isValidSudoku([["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]);
    isValidSudoku([["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]);
