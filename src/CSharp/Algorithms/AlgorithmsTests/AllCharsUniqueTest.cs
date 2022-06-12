using Microsoft.VisualStudio.TestTools.UnitTesting;
using Algorithms;

namespace AlgorithmsTests
{
    [TestClass]
    public class AllCharsUniqueTest
    {
        [TestMethod]
        public void TestIsUniqueBitSet()
        {
            Assert.IsTrue(AllCharsUnique.IsUniqueInt("012"));
            Assert.IsFalse(AllCharsUnique.IsUniqueInt("a0a"));
            Assert.IsTrue(AllCharsUnique.IsUniqueInt("aA"));
            Assert.IsFalse(AllCharsUnique.IsUniqueInt("11"));
        }
    }
}
