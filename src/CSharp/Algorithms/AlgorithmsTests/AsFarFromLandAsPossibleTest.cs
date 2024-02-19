using Algorithms;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmsTests
{
    [TestClass]
    public class AsFarFromLandAsPossibleTest
    {
        [TestMethod]
        public void TestMaxDistance()
        {
            Assert.AreEqual(2, AsFarFromLandAsPossibleTake2.MaxDistanceDP([[1, 0, 1], [0, 0, 0], [1, 0, 1]]));
            Assert.AreEqual(4, AsFarFromLandAsPossibleTake2.MaxDistanceDP([[1, 0, 0], [0, 0, 0], [0, 0, 0]]));
            Assert.AreEqual(-1, AsFarFromLandAsPossibleTake2.MaxDistanceDP([[1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1]]));
            Assert.AreEqual(-1, AsFarFromLandAsPossibleTake2.MaxDistanceDP([[0, 0],[0, 0]]));
            Assert.AreEqual(-1, AsFarFromLandAsPossibleTake2.MaxDistanceDP([[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]));
        }
    }
}
