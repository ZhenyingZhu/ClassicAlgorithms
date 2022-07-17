using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Give a BST with all distinct value, return all possible sequences that can lead to the tree, when there is no rotate.
    /// Uncertainties:
    /// </summary>
    /// <remarks>
    /// CC189 6th 4.9
    /// </remarks>
    public class SequencesToCreateACertainBST
    {
        // Solution 1: First element must be to root. Left subtree seq and right subtree seq weave together recursively.
        // Instead of dup the result, remove the latest added ones and append the new numbers.
    }
}
