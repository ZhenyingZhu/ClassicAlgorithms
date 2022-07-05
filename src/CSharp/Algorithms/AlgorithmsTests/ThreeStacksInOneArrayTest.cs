using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmsTests
{
    [TestClass]
    public class ThreeStacksInOneArrayTest
    {
        [TestMethod]
        public void TestThreeStacksInOneArray()
        {
            ThreeStacksInOneArray<int> stacks = new ThreeStacksInOneArray<int>();

            stacks.Push(5, 0);
            stacks.Push(6, 1);
            stacks.Push(1, 2);
            stacks.Push(2, 2);
            stacks.Push(3, 2);
            stacks.Push(4, 2);

            Assert.AreEqual(4, stacks.Pop(2));
            Assert.AreEqual(3, stacks.Pop(2));
            Assert.AreEqual(5, stacks.Peek(0));
            Assert.AreEqual(6, stacks.Peek(1));
        }
    }
}
