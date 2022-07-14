using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Given two nodes in a binary tree, find the first commonAncestor of them. Don't store additional nodes in data structure.
    /// Uncertainties:
    /// 1. is it a BST?
    /// 2. Does it have link to parent?
    /// </summary>
    /// <remarks>
    /// CC189 6th 4.8
    /// </remarks>
    public class BinaryTreeFirstCommonAncestor
    {
        // Solution 1: If it is a BST, from the root can find the first node that diverge.
        // Solution 2: If there are links to parent, count the length to parent.
        // Solution 3: from one node, go up and check each parent node sub trees. If not find, check the other node.
        // Solution 4: Traverse the tree until nodes are on two sides. Queue the subtree where nodes are in.
    }
}
