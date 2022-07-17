using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms.Utils
{
    public class BinaryTree
    {
        public BinaryTreeNode Root { get; set; }

        private Dictionary<int, BinaryTreeNode> idToNode = new Dictionary<int, BinaryTreeNode>();

        public BinaryTreeNode GetNodeById(int id)
        {
            if (this.idToNode.ContainsKey(id))
            {
                return this.idToNode[id];
            }

            return null;
        }

        private bool AddNode(BinaryTreeNode node)
        {
            if (this.idToNode.ContainsKey(node.Id))
            {
                return false;
            }

            this.idToNode.Add(node.Id, node);
            return true;
        }

        public static BinaryTree GenerateBinaryTree(int[] preOrder, int[] inOrder)
        {
            if (preOrder == null || inOrder == null || preOrder.Length != inOrder.Length)
            {
                throw new ArgumentException("Wrong input");
            }

            BinaryTree tree = new BinaryTree();
            BinaryTreeNode root = CreateTree(tree, preOrder, 0, preOrder.Length - 1, inOrder, 0, inOrder.Length - 1);
            tree.Root = root;
            return tree;
        }

        private static BinaryTreeNode CreateTree(
            BinaryTree tree, int[] preOrder, int preSt, int preEd, int[] inOrder, int inSt, int inEd)
        {
            if (preSt > preEd)
            {
                return null;
            }

            BinaryTreeNode root = new BinaryTreeNode(preOrder[preSt]);
            tree.AddNode(root);

            if (preSt == preEd)
            {
                return root;
            }

            for (int i = inSt; i <= inEd; i++)
            {
                if (inOrder[i] == preOrder[preSt])
                {
                    int len = i - inSt;

                    BinaryTreeNode left = CreateTree(tree, preOrder, preSt + 1, preSt + len, inOrder, inSt, i - 1);
                    BinaryTreeNode right = CreateTree(tree, preOrder, preSt + len + 1, preEd, inOrder, i + 1, inEd);
                    root.LeftChild = left;
                    root.RightChild = right;
                    return root;
                }
            }

            throw new ApplicationException("Not expect.");
        }
    }
}
