using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// A sorted array of strings, but contains empty strings between. Find the location of a string.
    /// Uncertainties:
    /// 1. If search for empty string?
    /// 2. how many times to search?
    /// </summary>
    /// <remarks>
    /// CC189 6th 10.5
    /// </remarks>
    public class SortedSparseArraySearch
    {
        // Solution 1: Linear search until next string, then binary search.
        // Solution 2: pre-process to compress empty strings so repeat search can be quicker.
    }
}
