using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Give an int, flip one digit so that there are longest sequence of 1s. Return the length.
    /// Uncertainties:
    /// </summary>
    /// <remarks>
    /// CC189 6th 5.3
    /// </remarks>
    public class FlipIntOneBitToGetLongest1s
    {
        // Solution 1: Brute force flip all 0 and count. No need to count 1s all from start
        // Solution 2: Count conseq 0 and 1s and record the count. then brute force
        // Solution 3: to save space, just record previous 1s length and count current length, then update the longest

    }
}
