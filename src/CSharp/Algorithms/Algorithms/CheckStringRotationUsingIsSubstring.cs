using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Check if a string is a rotation of another string by calling IsSubstring only once.
    /// Uncertainties:
    /// </summary>
    /// <remarks>
    /// CC189 6th 1.9
    /// </remarks>
    public class CheckStringRotationUsingIsSubstring
    {
        // Solution 1: not too many solutions. Just repeat the string twice and check if the other one is a substring.
        public static bool StringRotation(string str1, string str2)
        {

        }

        private static bool IsSubstring(string super, string sub)
        {
            // Use DP.
            if (super == null)
            {
                return sub == null;
            }

            if (sub == null)
            {
                return true;
            }

            int m = super.Length, n = sub.Length;
            if (m < n)
            {
                return false;
            }

            bool[][] isSub = new bool[m + 1][];
            for (int i = m; i >=0; i--)
            {
                isSub[i] = new bool[n + 1];
                for (int j = n; j >=0; j--)
                {
                    if (i == m)
                    {
                        isSub[i][j] = true;
                    }

                    if (super[i] == sub[j])
                    {
                        isSub[i][j] = (i == m - 1) || (j == n - 1) || isSub[i + 1][j + 1];
                    }
                }
            }
        }
    }
}
