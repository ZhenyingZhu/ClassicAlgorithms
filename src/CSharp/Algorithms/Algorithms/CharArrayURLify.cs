using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Replace space with %20 in place.
    /// </summary>
    /// <remarks>
    /// CC189 6th 1.3
    /// </remarks>
    public class CharArrayURLify
    {
        // Solution 1: Get the total URLify length, then use two pointers backwards.
        public static void URLifyInplace(char[] urlCharArray, int oriLen)
        {
            // Need to deal with oriLen is actually larger than array length.
            oriLen = Math.Min(urlCharArray.Length, oriLen);

            // Instead of use for loop, just count the space and use math. It is quicker.
            int totalLen = 0;
            for (int i = 0; i < oriLen; i++)
            {
                if (urlCharArray[i] == ' ')
                {
                    totalLen += 3;
                }
                else
                {
                    totalLen++;
                }
            }

            int writer = totalLen - 1;
            for (int processor = oriLen - 1; processor >= 0; processor--)
            {
                if (urlCharArray[processor] == ' ')
                {
                    urlCharArray[writer - 2] = '%';
                    urlCharArray[writer - 1] = '2';
                    urlCharArray[writer - 0] = '0';
                    writer -= 3;
                }
                else
                {
                    urlCharArray[writer--] = urlCharArray[processor];
                }
            }
        }
    }
}
