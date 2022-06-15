using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace Algorithms
{
    /// <summary>
    /// Check if a string can be a permutation of a palindrome.
    /// Uncertainties:
    /// 1. Does case matter? No
    /// 2. Does space count in? No.
    /// 3. Does number count in? No.
    /// </summary>
    /// <remarks>
    /// CC189 6th 1.4
    /// </remarks>
    public class StringIsPalindromePermutation
    {
        // Solution 1: Count the chars that are alphabets or numbers. If there are no more than one odd count char,
        // the string is palindrome. Otherwise not. Time complexity: O(n).
        public static bool PalindromePermutation(string input)
        {
            Dictionary<char, int> charCounts = new Dictionary<char, int>();
            foreach (char c in input)
            {
                char? lowerC = ToLower(c);
                if (lowerC == null)
                {
                    continue;
                }

                if (!charCounts.ContainsKey(lowerC.Value))
                {
                    charCounts[lowerC.Value] = 0;
                }

                charCounts[lowerC.Value]++;
            }

            bool oddChar = false;
            foreach (KeyValuePair<char, int> charCount in charCounts)
            {
                if (charCount.Value % 2 == 1)
                {
                    if (oddChar)
                    {
                        return false;
                    }

                    oddChar = true;
                }
            }

            return true;
        }

        // Solution 2: While processing each char, check if the count is odd. If so, increase the odd count by one,
        // otherwise decrease by 1.

        // Solution 3: use a bit set, and flip the cell of the char when see it. Then convert it into an integer and compare to 0.

        private static bool IsAlphabetOrNumber(char c)
        {
            return Regex.IsMatch(c.ToString(), @"[a-z|0-9]", RegexOptions.IgnoreCase);
        }

        /// <summary>
        /// If the char is upper case, return its lower case. If the char is lower case, return as is.
        /// 
        /// </summary>
        /// <param name="c">The char.</param>
        /// <returns>The lower case.</returns>
        private static char? ToLower(char c)
        {
            if (c >= 'A' && c <= 'Z')
            {
                return (char)(c - 'A' + 'a');
            }

            if (c >= 'a' && c <= 'z')
            {
                return c;
            }

            return null;
        }
    }
}
