using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// A robot can move down or right. In a grid there are obstacle cells. From top left, find a path to go to bottom right.
    /// Uncertainties:
    /// 1. what if no path to return
    /// </summary>
    /// <remarks>
    /// CC189 6th 8.2
    /// </remarks>
    public class WaysForRobotMoveInGrid
    {
        // Solution 1: from top left to down right, find the previous cell that can move from top left to it.
        // Solution 2: convert to a graph, and use DFS
    }
}
