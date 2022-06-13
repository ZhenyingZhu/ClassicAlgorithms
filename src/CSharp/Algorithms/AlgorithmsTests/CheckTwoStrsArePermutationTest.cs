using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmsTests
{
    [TestClass]
    public class CheckTwoStrsArePermutationTest
    {
        [TestMethod]
        public void TestCheckPermutationSort()
        {
            Assert.IsTrue(CheckTwoStrsArePermutation.CheckPermutationSort("abc", "bca"));
        }

        [TestMethod]
        public void TestCheckPermutationCharCount()
        {
            Assert.IsTrue(CheckTwoStrsArePermutation.CheckPermutationCharCount("aba", "baa"));
            Assert.IsFalse(CheckTwoStrsArePermutation.CheckPermutationCharCount("abc", "baa"));
            Assert.IsFalse(CheckTwoStrsArePermutation.CheckPermutationCharCount("aba", "bac"));
        }
    }
}
