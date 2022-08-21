using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Given 25, 10, 5 and 1 cents coins, return num of ways to represent n cents.
    /// Uncertainties:
    /// </summary>
    /// <remarks>
    /// CC189 6th 8.11
    /// </remarks>
    public class CoinsForNCents
    {
        // Solution 1: DP. O(n) = sum(O(n-1) + O(n-5) + O(n-10) + O(n-25)). O(0)=1, O(-x)=0.
    }
}
