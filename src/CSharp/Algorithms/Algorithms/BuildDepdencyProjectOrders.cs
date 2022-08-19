using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Give a list of projects, where each project can have a dependent project, find an order where all the projects can be run.
    /// Uncertainties:
    /// 1. how to present the depdendency?
    /// 2. what to return when there is no working order?
    /// </summary>
    /// <remarks>
    /// CC189 6th 4.7
    /// </remarks>
    public class BuildDepdencyProjectOrders
    {
        // Solution 1: topology sort
        // Solution 2: use DFS and build the order backward
    }
}
