/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length; j++) {
            if (existNS.helper(board, i, j, word, 0)) {
                return true;
            }
        }
    }

    return false;
};

const existNS = {
    helper: function(board, i, j, word, x) {
        let c = board[i][j];
        if (x === word.length - 1) {
            return (c === word[x]);
        }

        if (c !== word[x]) {
            return false;
        }

        board[i][j] = '.';

        if (i > 0 && existNS.helper(board, i - 1, j, word, x + 1)) {
            return true;
        }

        if (i < board.length - 1 && existNS.helper(board, i + 1, j, word, x + 1)) {
            return true;
        }

        if (j > 0 && existNS.helper(board, i, j - 1, word, x + 1)) {
            return true;
        }

        if (j < board[0].length - 1 && existNS.helper(board, i, j + 1, word, x + 1)) {
            return true;
        }

        board[i][j] = c;

        return false;
    }
};

document.getElementById("word-search").innerHTML =
    // exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCCED");
    // exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "SEE");
    exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCB");
    // exist([["a"]], "a");
