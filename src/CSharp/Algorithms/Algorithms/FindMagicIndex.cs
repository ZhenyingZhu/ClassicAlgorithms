using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Magic index is A[i]=i. Given a sorted array, find magic index.
    /// Uncertainties:
    /// 1. is the interger distinct?
    /// </summary>
    /// <remarks>
    /// CC189 6th 8.3
    /// </remarks>
    public class FindMagicIndex
    {
        // Solution 1: binary search. If A[i]>i, cannot find in the right; if A[i]<i, search right. When allow dup, iterate to the last val when index could be same as val
    }
}
