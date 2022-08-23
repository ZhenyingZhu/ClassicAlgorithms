using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Given a stack of boxes. One can only be placed on another when all its dimensions are strickly shorter. Cannot rotate, what is the max hight?
    /// Uncertainties:
    /// When dimension is same, can it be placed?
    /// </summary>
    /// <remarks>
    /// CC189 6th 8.13
    /// </remarks>
    public class MaxHeightForStackOfBoxes
    {
        // Solution 1: sort by height, then start DFS.
        // Solution 2: use DP. From small to big, memorize the max height.
        // Solution 3: for each box, decide whether to put it in or not, also use DP.
    }
}
