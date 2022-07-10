using System;
using System.Collections.Generic;
using System.Text;
using Algorithms.Utils;

namespace Algorithms
{
    /// <summary>
    /// A directed graph. Find out if there is a route between two nodes.
    /// Uncertainties:
    /// </summary>
    /// <remarks>
    /// CC189 6th 4.1
    /// </remarks>
    public class RouteBetweenGraphNodes
    {
        // Solution 1: use BFS.
        public static bool RouteBetweenNodesBFS(DirectedGraph graph, GraphNode start, GraphNode end)
        {
            Queue<GraphNode> queue = new Queue<GraphNode>();
            HashSet<GraphNode> visited = new HashSet<GraphNode>();

            if (start == null || end == null || graph.Nodes.Count == 0)
            {
                return false;
            }

            visited.Add(start);
            queue.Enqueue(start);
            while(queue.Count > 0)
            {
                GraphNode node = queue.Dequeue();
                foreach (GraphNode neighbor in node.Neighbors)
                {
                    if (visited.Contains(neighbor))
                    {
                        continue;
                    }

                    if (neighbor == end)
                    {
                        return true;
                    }

                    visited.Add(neighbor);
                    queue.Enqueue(neighbor);
                }
            }

            return false;
        }

        // Solution 2: use Bidirectional search.
    }
}
