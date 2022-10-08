using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Given an array of ints, find the min-length indices m and n, so that sort elements m through n sorts the entire array.
    /// Uncertainties:
    /// 1. what if the array is already sorted?
    /// 2. how to deal with dups?
    /// </summary>
    /// <remarks>
    /// CC189 6th 16.16
    /// </remarks>
    public class SubArraySortsTheWholeArray
    {
        // Solution 1: Sort the array and compare
        // Solution 2: scan from beginning, if find an element small than previous elements, start record the smallest element. Then start from begining again use binary search.
    }
}
