using System;
using System.Collections.Generic;
using System.IO;
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
            if (str1 == null || str2 == null || str1.Length != str2.Length)
            {
                return false;
            }

            return IsSubstring(str1 + str1, str2);
        }

        public static bool IsSubstring(string super, string sub)
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

            // 0: is not subString
            // 1: is substring, and same chars so far
            // 2: is substring, but not same chars
            int[][] isSub = new int[m + 1][];
            isSub[m] = new int[n + 1];
            isSub[m][n] = 1;
            isSub[m][n - 1] = 0;

            for (int i = m - 1; i >= 0; i--)
            {
                isSub[i] = new int[n + 1];
                isSub[i][n] = 1;
                for (int j = n - 1; j >= 0; j--)
                {
                    if (m - i <= n - j)
                    {
                        // The super str is same or short than sub
                        isSub[i][j] = 0;

                        // No need to loop further. Previous cells are not in use.
                        continue;
                    }
                    else if (super[i] != sub[j])
                    {
                        if (isSub[i + 1][j] >= 1)
                        {
                            isSub[i][j] = 2;
                        }
                        else
                        {
                            isSub[i][j] = 0;
                        }
                    }
                    else
                    {
                        if (isSub[i + 1][j + 1] == 1)
                        {
                            isSub[i][j] = 1;
                        }
                        else if (isSub[i + 1][j] >= 1)
                        {
                            isSub[i][j] = 2;
                        }
                        else
                        {
                            isSub[i][j] = 0;
                        }
                    }
                }
            }

            /** For debugging purpose.
            using (StreamWriter file = new StreamWriter("IsSubstring.txt"))
            {
                for (int i = 0; i <= m; i++)
                {
                    file.WriteLine(string.Join(string.Empty, isSub[i]));
                }
            }
            **/

            return isSub[0][0] >= 1;
        }
    }
}
