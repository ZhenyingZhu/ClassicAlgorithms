using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// A peak is a num bigger or equals to all its adjacents. A valley is less or equal. Given an int array, sort it into an alternating seq of peaks and valleys.
    /// </summary>
    /// <remarks>
    /// CC189 6th 10.11
    /// </remarks>
    public class PeaksAndValleysInIntArray
    {
        // Solution 1: sort the array, and then swap every two numbers.
        // Solution 2: no need to sort. Move 2 numbers a time, between 3 numbers, swap the mid one with the largest one.
    }
}
