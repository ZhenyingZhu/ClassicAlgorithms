using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmsTests
{
    [TestClass]
    public class CheckStringRotationUsingIsSubstringTest
    {
        [TestMethod]
        public void TestStringRotation()
        {
            Assert.IsTrue(CheckStringRotationUsingIsSubstring.StringRotation("abcde", "cdeab"));
            Assert.IsTrue(CheckStringRotationUsingIsSubstring.StringRotation("abcde", "abcde"));
            Assert.IsTrue(CheckStringRotationUsingIsSubstring.StringRotation("ababc", "abcab"));
            Assert.IsFalse(CheckStringRotationUsingIsSubstring.StringRotation("ababc", "abcba"));
        }

        [TestMethod]
        public void TestIsSubstring()
        {
            Assert.IsTrue(CheckStringRotationUsingIsSubstring.IsSubstring("abc", "ab"));
            Assert.IsFalse(CheckStringRotationUsingIsSubstring.IsSubstring("abc", "ba"));
            Assert.IsTrue(CheckStringRotationUsingIsSubstring.IsSubstring("abac", "ba"));
            Assert.IsFalse(CheckStringRotationUsingIsSubstring.IsSubstring("ababcababc", "abcba"));
            Assert.IsTrue(CheckStringRotationUsingIsSubstring.IsSubstring("abcdeabcde", "cdeab"));
        }
    }
}
