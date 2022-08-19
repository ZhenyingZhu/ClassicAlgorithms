using System;
using System.Collections.Generic;
using System.Text;
using Algorithms.Utils;

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
        public static BinaryTreeNode FirstCommonAncestor(BinaryTree tree, BinaryTreeNode node1, BinaryTreeNode node2)
        {
            BinaryTreeNode commonAncestor;
            if (FindCommonAncestor(tree.Root, node1, node2, out commonAncestor))
            {
                return commonAncestor;
            }
            else
            {
                return null;
            }
        }

        private static bool FindCommonAncestor(BinaryTreeNode root, BinaryTreeNode node1, BinaryTreeNode node2, out BinaryTreeNode ancestorOrNode)
        {
            if (root == null)
            {
                ancestorOrNode = null;
                return false;
            }

            BinaryTreeNode findLeftNode;
            if (FindCommonAncestor(root.LeftChild, node1, node2, out findLeftNode))
            {
                ancestorOrNode = findLeftNode;
                return true;
            }

            BinaryTreeNode findRightNode;
            if (FindCommonAncestor(root.RightChild, node1, node2, out findRightNode))
            {
                ancestorOrNode = findRightNode;
                return true;
            }

            if (root == node1)
            {
                ancestorOrNode = root;
                return (findLeftNode == node2 || findRightNode == node2);
            }
            else if (root == node2)
            {
                ancestorOrNode = root;
                return (findLeftNode == node1 || findRightNode == node1);
            }
            else if ((findLeftNode == node1 && findRightNode == node2) || (findLeftNode == node2 && findRightNode == node1))
            {
                ancestorOrNode = root;
                return true;
            }
            else
            {
                ancestorOrNode = null;
                return false;
            }
        }
    }
}
