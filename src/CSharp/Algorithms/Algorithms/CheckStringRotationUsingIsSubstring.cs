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

            bool[][] isSub = new bool[m + 1][];
            isSub[m] = new bool[n + 1];
            isSub[m][n] = true;
            isSub[m][n - 1] = false;

            for (int i = m - 1; i >= 0; i--)
            {
                isSub[i] = new bool[n + 1];
                isSub[i][n] = true;
                for (int j = n - 1; j >= 0; j--)
                {
                    if (super[i] == sub[j])
                    {
                        if (i + 1 == m || j + 1 == n)
                        {
                            isSub[i][j] = true;
                        }
                        else
                        {
                            // Still not completely right. If the current char is same, it can still not be the continious substring.
                            isSub[i][j] = super[i + 1] == sub[j + 1] && isSub[i + 1][j + 1];
                        }
                    }
                    else if (m - i <= n - j)
                    {
                        // The super str is same or short than sub
                        isSub[i][j] = false;
                    }
                    else
                    {
                        isSub[i][j] = isSub[i + 1][j];
                    }
                }
            }

            using (StreamWriter file = new StreamWriter("WriteLines2.txt"))
            {
                for (int i = 0; i <= m; i++)
                {
                    StringBuilder sb = new StringBuilder();
                    for (int j = 0; j <= n; j++)
                    {
                        if (isSub[i][j])
                        {
                            sb.Append('T');
                        }
                        else
                        {
                            sb.Append('F');
                        }
                    }
                    file.WriteLine(sb.ToString());
                }
            }

            return isSub[0][0];
        }
    }
}
