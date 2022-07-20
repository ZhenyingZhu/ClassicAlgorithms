using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Check if a tree is a subtree of another, where the other tree is much bigger.
    /// Uncertainties:
    /// How much memory do we have
    /// </summary>
    /// <remarks>
    /// CC189 6th 4.10
    /// </remarks>
    public class CheckSmallTreeIsSubTree
    {
        // Solution 1: traverse tree big until find node that is the root of tree small, then check if left sub tree and right sub tree.
        //   time complexity: Big tree n nodes. O(n+km) where k is nodes matching small tree root.
        //   space complexity: O(log(n) + log(m))
        // Solution 2: when find the root, do a pre-order traverse of both tree, with leaf node count as null. Then compare the seq. O(m+n)
    }
}
