using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Implement a binary search tree, and support return a random node.
    /// Uncertainties:
    /// 1. are all nodes uniq?
    /// </summary>
    /// <remarks>
    /// CC189 6th 4.11
    /// </remarks>
    public class BSTSupportsRandomNode
    {
        // Solution 1: know how many nodes in total. Each node tracks the order in the tree. Return the nth node. But delete needs O(n)
        // Support insert, delete, getRandom node.

        // Solution 2: Each node keep track of the node counts of its left and right tree, so know the odd where to do.
    }
}
