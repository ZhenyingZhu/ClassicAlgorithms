using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;

namespace AlgorithmsTests
{
    [TestClass]
    public class StringOneEditAwayTest
    {
        [TestMethod]
        public void TestOneAway()
        {
            Assert.IsTrue(StringOneEditAway.OneAwayTwoChecks("ab", "ac"));
            Assert.IsTrue(StringOneEditAway.OneAwayTwoChecks("aac", "ac"));
            Assert.IsTrue(StringOneEditAway.OneAwayTwoChecks("ac", "abc"));
            Assert.IsFalse(StringOneEditAway.OneAwayTwoChecks("acb", "abc"));
        }
    }
}
