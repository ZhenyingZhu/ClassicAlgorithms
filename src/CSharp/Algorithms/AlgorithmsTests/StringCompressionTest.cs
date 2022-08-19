using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Microsoft.VisualStudio.TestTools.UnitTesting;


namespace AlgorithmsTests
{
    [TestClass]
    public class StringCompressionTest
    {
        [TestMethod]
        public void Test()
        {
            Assert.AreEqual("a3b1", StringCompression.StringCompressionCraftWhileGoThrough("aaab"));
            Assert.AreEqual("abca", StringCompression.StringCompressionCraftWhileGoThrough("abca"));
        }
    }
}
