using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Give a 4 Billion non-negative ints, 1G memory, generate an int not in the file.
    /// Follow up, if 1 billion non-negative distinct num, 10M memory, return the result.
    /// Uncertainties:
    /// 1. follow up question assume there is only 1 missing?
    /// </summary>
    /// <remarks>
    /// CC189 6th 10.7
    /// </remarks>
    public class ReturnIntNotInHugeFile
    {
        // Solution 1: external bucket sort the numbers, and binary search.
        // Solution 2: 1GB is 8 billion bits, so set the bit to hold an appeared int.
        // Follow up solution: first pass count numbers between a block (like x000 to x999) in an array, and find which one is not the expected length. second pass use a bit vector to find the num. The array size 2^31 non-negative int numbers/range size. 10MB is 2^23 bytes. int is 4 bytes.
    }
}
