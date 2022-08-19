using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms.Utils
{
    public class BinaryTreeNode
    {
        public int Id { get; set; }
        public BinaryTreeNode LeftChild { get; set; }
        public BinaryTreeNode RightChild { get; set; }

        public BinaryTreeNode(int id)
        {
            Id = id;
        }
    }
}
