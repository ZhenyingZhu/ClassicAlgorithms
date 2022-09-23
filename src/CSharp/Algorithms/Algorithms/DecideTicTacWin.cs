using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Check if someone has won a game of tic tac toe.
    /// Uncertainties:
    /// 1. what if game not finished
    /// </summary>
    /// <remarks>
    /// CC189 6th 16.4
    /// </remarks>
    public class DecideTicTacWin
    {
        // Solution 1: brute force.
        // Solution 2: pre-processing: a hashmap records all the possible results
        // Solution 3: record the board in a way that is easy to get result
        // Solution 4: if know the last move, just check the target row/col/diag
        // Solution 5: implement an iterator to go over each direction.
    }
}
