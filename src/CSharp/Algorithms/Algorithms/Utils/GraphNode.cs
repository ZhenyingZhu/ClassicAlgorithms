using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms.Utils
{
    public class GraphNode
    {
        public int Id { get; set; }

        public List<GraphNode> Neighbors { get; private set; } = new List<GraphNode>();

        public GraphNode(int id)
        {
            this.Id = id;
        }

        public override int GetHashCode() => this.Id;

        public override bool Equals(object other) => other is GraphNode n && n.Id == this.Id;
    }
}
