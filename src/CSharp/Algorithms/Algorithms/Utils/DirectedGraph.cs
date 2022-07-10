using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms.Utils
{
    public class DirectedGraph
    {
        public Dictionary<int, GraphNode> Nodes { get; private set; } = new Dictionary<int, GraphNode>();

        public static DirectedGraph GenerateGraph(Dictionary<int, List<int>> graphDict)
        {
            DirectedGraph graph = new DirectedGraph();
            Dictionary<int, GraphNode> nodeDict = graph.Nodes;
            foreach (KeyValuePair<int, List<int>> nodeDes in graphDict)
            {
                int id = nodeDes.Key;

                GraphNode node;
                if (!nodeDict.TryGetValue(id, out node))
                {
                    node = new GraphNode(id);
                    nodeDict.Add(id, node);
                }

                foreach (int neighbor in nodeDes.Value)
                {
                    GraphNode neighborNode;
                    if (!nodeDict.TryGetValue(neighbor, out neighborNode))
                    {
                        neighborNode = new GraphNode(neighbor);
                        nodeDict.Add(neighbor, neighborNode);
                    }
                    node.Neighbors.Add(neighborNode);
                }
            }

            return graph;
        }
    }
}
