using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Give a boolean expression with {0, 1, &, |, ^}, and a target bool value, return the number of ways to parenthesizing
    /// Uncertainties:
    /// Can not add parenthesize a solution? It makes the duplicate cases more complicate
    /// </summary>
    /// <remarks>
    /// CC189 6th 8.14
    /// </remarks>
    public class NumOfWaysForParenBoolExpression
    {
        // Solution 1: break down in each op to find a value.
        // Make code consise: totalWays = (leftEvalTrue + leftEvalFalse) * (rightEvalTrue + rightEvalFalse). After cal TotalEvalTrue, TotalEvalFalse = TotalWays - TotalEvalTrue
        // But it do useless calcuation

        // Solution 2: Use DP. Save the string and its eval result when computed. Better than mem the index because same string can appear in both left and right.
    }
}
