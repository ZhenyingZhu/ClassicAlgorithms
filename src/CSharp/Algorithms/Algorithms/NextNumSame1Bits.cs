using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Give a positive int, find the next smallest and largest nums with same 1 bits
    /// </summary>
    /// <remarks>
    /// CC189 6th 5.4
    /// </remarks>
    public class NextNumSame1Bits
    {
        // Solution 1: next largest: find the first 1 after 0s, move right, then move 1s to the left; next smallest: find the first trailing 1, move left,.and move 1s to the right.
        // Solution 2: next smallest: c0 is the number of trailing 0s, c1 is the size of 1 blocks following, p = c0+c1, set pth bit to 1, then move 1s to right. n + (1 << c0) + (1 << (c1 - 1)) - 1.
    }
}
