using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Given a stream of integers, repeatly getting the rank of a num x (the # of nums <= x not include x itself). track(x) puts the number in the stream. getRankOfNum(x).
    /// Uncertainties:
    /// 1. what if the target is less than the min num?
    /// </summary>
    /// <remarks>
    /// CC189 6th 10.10
    /// </remarks>
    public class GetRankFromStream
    {
        // Solution 1: A linked list record count of each num. When get the rank, linear search to it.
        // Solution 2: use a binary search tree instead of linked list. The tree node is updated when insert.
    }
}
