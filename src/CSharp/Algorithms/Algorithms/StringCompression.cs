using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Compress a string as char and its repeat count. If the string is not shorter after compression, return its original form.
    /// Uncertainties:
    /// 1. Special chars?
    /// 2. Could string length exceed int max?
    /// </summary>
    /// <remarks>
    /// CC189 6th 1.6
    /// </remarks>
    public class StringCompression
    {
        // Solution 1: Count and append.
        public static string StringCompressionCraftWhileGoThrough(string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                return str;
            }

            StringBuilder sb = new StringBuilder();
            char current = str[0];
            int count = 1;
            for (int i = 1; i < str.Length; i++)
            {
                if (str[i] != current)
                {
                    AppendCharCount(current, count, sb);
                    if (sb.Length > str.Length)
                    {
                        return str;
                    }

                    current = str[i];
                    count = 1;
                }
                else
                {
                    count++;
                }
            }

            AppendCharCount(current, count, sb);
            if (sb.Length > str.Length)
            {
                return str;
            }

            return sb.ToString();
        }

        private static void AppendCharCount(char c, int count, StringBuilder sb)
        {
            sb.Append(c);

            // Can just use string function.
            List<int> list = new List<int>();
            while (count > 0)
            {
                list.Add(count % 10);
                count /= 10;
            }

            for (int i = list.Count - 1; i >= 0; i--)
            {
                sb.Append(list[i]);
            }
        }
    }
}
