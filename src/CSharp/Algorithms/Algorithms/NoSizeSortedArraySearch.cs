using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// A listy data structure which doesn't have size(). Has elementAt(i). If i is bigger than the bound, return -1. It only contains sorted positive integers. Search for the index of element x.
    /// Uncertainties:
    /// 1. duplicates? Return any index is good.
    /// </summary>
    /// <remarks>
    /// CC189 6th 10.4
    /// </remarks>
    public class NoSizeSortedArraySearch
    {
        // Solution 1: use binary search. If index > element, search right. But since not know the size, try exponentially going further from 1,2,4,8.
    }
}
