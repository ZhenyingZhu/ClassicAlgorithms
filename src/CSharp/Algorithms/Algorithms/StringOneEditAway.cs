using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Check two strings are 1 or 0 edit distance.
    /// Uncertainties:
    /// </summary>
    /// <remarks>
    /// CC189 6th 1.5
    /// </remarks>
    public class StringOneEditAway
    {
        // Solution 1: compare the length first, then predict what edit could be.
        public static bool OneAwayTwoChecks(string input1, string input2)
        {
            // Can use ? : to write below code block in 2 lines
            string shortStr, longStr;
            if (input1.Length < input2.Length)
            {
                shortStr = input1;
                longStr = input2;
            }
            else
            {
                shortStr = input2;
                longStr = input1;
            }

            // Can use the Math.Abs()
            if (shortStr.Length + 1 < longStr.Length)
            {
                return false;
            }
            else if (shortStr.Length + 1 == longStr.Length)
            {
                return CheckOneAdd(shortStr, longStr);
            }
            else
            {
                return CheckOneEdit(shortStr, longStr);
            }
        }

        // Solution 2: combine the two checks into one. When see a difference, check the string length difference.

        private static bool CheckOneAdd(string shortStr, string longStr)
        {
            bool diffFound = false;
            int j = 0;
            for (int i = 0; i < shortStr.Length; i++)
            {
                if (shortStr[i] == longStr[j])
                {
                    j++;
                }
                else if (!diffFound)
                {
                    diffFound = true;
                    j++;
                }
                else
                {
                    return false;
                }
            }

            return true;
        }

        private static bool CheckOneEdit(string str1, string str2)
        {
            bool diffFound = false;
            int j = 0;
            for (int i = 0; i < str1.Length; i++)
            {
                if (str1[i] == str2[j])
                {
                    j++;
                }
                else if (!diffFound)
                {
                    diffFound = true;
                    j++;
                }
                else
                {
                    return false;
                }
            }

            return true;
        }
    }
}
