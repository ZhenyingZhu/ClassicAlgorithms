using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Give a real number between 0 and 1, return the binary form in string format.
    /// Uncertainties:
    /// 1. When cannot accurately represent, what to return
    /// 2. can it exceed 32 bits?
    /// </summary>
    /// <remarks>
    /// CC189 6th 5.2
    /// </remarks>
    public class RealNumToBinaryString
    {
        // Solution 1: keep multiple the real number with 2 and check if it is > 1. If so, the digit is 1. Otherwise 0.
        // Solution 2: compare to 0.5, 0.25, ... to decide if the digit should be 1 or 0.
    }
}
