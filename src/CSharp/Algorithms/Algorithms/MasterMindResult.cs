using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Master mind: give a solution with 4 slots that can be any one of RYGB, computer tells whether a hit or a pseudo-hit. Return the result.
    /// Uncertainties:
    /// 1. whether pseudo-hit can also be a hit?
    /// </summary>
    /// <remarks>
    /// CC189 6th 16.15
    /// </remarks>
    public class MasterMindResult
    {
        // Solution 1: Scan once and count the slot and hit. Then count again.
        // Solution 2: scan only once, and minus the hit.
    }
}
