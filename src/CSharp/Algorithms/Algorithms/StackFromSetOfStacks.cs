using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// When the stack exceed certain threshold, internally start a new stack. Support popAt(stackId).
    /// Uncertainties:
    /// 1. When popAt(stackId), should we shift the elements from later stack?
    /// </summary>
    /// <remarks>
    /// CC189 6th 3.3
    /// </remarks>
    public class StackFromSetOfStacks
    {
        // Solution 1: Create an array of stacks. Track the top one. When a stack is empty, skip over.
        // Solution 2: popAt(stackId) moves later stack elements to it. Use linkedList to implement it.
    }
}
