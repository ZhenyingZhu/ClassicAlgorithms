using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Algorithms.Utils;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmsTests
{
    [TestClass]
    public class RouteBetweenGraphNodesTest
    {
        [TestMethod]
        public void TestRouteBetweenNodesBFS()
        {
            Dictionary<int, List<int>> graphNodes = new Dictionary<int, List<int>>()
            {
                { 0, new List<int>() { 1 } },
                { 1, new List<int>() { 2 } },
                { 2, new List<int>() { 0 } },
                { 3, new List<int>() { 2 } }
            };
            DirectedGraph graph = DirectedGraph.GenerateGraph(graphNodes);

            Assert.IsTrue(RouteBetweenGraphNodes.RouteBetweenNodesBFS(graph, graph.Nodes[0], graph.Nodes[2]));
            Assert.IsTrue(RouteBetweenGraphNodes.RouteBetweenNodesBFS(graph, graph.Nodes[3], graph.Nodes[1]));
            Assert.IsFalse(RouteBetweenGraphNodes.RouteBetweenNodesBFS(graph, graph.Nodes[1], graph.Nodes[3]));
        }
    }
}
