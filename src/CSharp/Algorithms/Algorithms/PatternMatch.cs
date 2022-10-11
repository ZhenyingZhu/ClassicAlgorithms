using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Given a pattern with only a and b, and a string, see if the string can match the pattern.
    /// 1. What if there are more two kinds of sub-strings?
    /// </summary>
    /// <remarks>
    /// CC189 6th 16.18
    /// </remarks>
    public class PatternMatch
    {
        // Solution 1: Check each substring and try match a and b.
        // Solution 2: gets all the "a"s from pattern, when matching a, predict b so no need to go over each substring for b.
    }
}
