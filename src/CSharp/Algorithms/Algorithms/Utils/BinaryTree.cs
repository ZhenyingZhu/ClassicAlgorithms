using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms.Utils
{
    public class BinaryTree
    {
        public BinaryTreeNode Root { get; set; }

        public static BinaryTree GenerateBinaryTree(int[] preOrder, int[] inOrder)
        {
            if (preOrder == null || inOrder == null || preOrder.Length != inOrder.Length)
            {
                throw new ArgumentException("Wrong input");
            }

            BinaryTreeNode root = CreateTree(preOrder, 0, preOrder.Length - 1, inOrder, 0, inOrder.Length - 1);
            return new BinaryTree { Root = root };
        }

        private static BinaryTreeNode CreateTree(int[] preOrder, int preSt, int preEd, int[] inOrder, int inSt, int inEd)
        {
            if (preSt > preEd)
            {
                return null;
            }

            BinaryTreeNode root = new BinaryTreeNode(preOrder[preSt]);
            if (preSt == preEd)
            {
                return root;
            }

            for (int i = inSt; i <= inEd; i++)
            {
                if (inOrder[i] == preOrder[preSt])
                {
                    int len = i - inSt + 1;

                    BinaryTreeNode left = CreateTree(preOrder, preSt + 1, preSt + len, inOrder, inSt, i - 1);
                    BinaryTreeNode right = CreateTree(preOrder, preSt + len + 1, preEd, inOrder, i + 1, inEd);
                    root.LeftChild = left;
                    root.RightChild = right;
                    return root;
                }
            }

            throw new ApplicationException("Not expect.");
        }
    }
}
