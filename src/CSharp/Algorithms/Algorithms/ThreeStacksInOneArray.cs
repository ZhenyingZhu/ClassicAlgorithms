using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Implement 3 stacks in one array.
    /// Uncertenties:
    /// </summary>
    /// <remarks>
    /// CC189 6th 3.1
    /// </remarks>
    public class ThreeStacksInOneArray<T>
    {
        List<T> list;

        // Solution 1: divide the array into 3 equal size pieces.
        // Solution 2: one stack exceed its cap, shift elements and give it more spaces
        public ThreeStacksInOneArray()
        {
            list = new List<T>(30);
        }
    }
}
