using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;

namespace AlgorithmsTests
{
    [TestClass]
    public class StringIsPalindromePermutationTest
    {
        [TestMethod]
        public void TestPalindromePermutation()
        {
            Assert.IsTrue(StringIsPalindromePermutation.PalindromePermutation("Ac1 1a1c"));
        }
    }
}
