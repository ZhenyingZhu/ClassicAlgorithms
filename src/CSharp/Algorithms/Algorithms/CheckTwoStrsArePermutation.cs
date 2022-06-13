using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Check if one string is a permutation of another.
    /// Uncertainties:
    /// 1. Case sensitive?
    /// 2. whitespace is significant?
    /// </summary>
    /// <remarks>
    /// CC189 6th 1.2
    /// </remarks>
    public class CheckTwoStrsArePermutation
    {
        // Solution 1: Sort and compare. Time complexty: O(nlogn).
        public static bool CheckPermutationSort(string s1, string s2)
        {
            if (s1 == null || s2 == null)
            {
                return s1 == s2;
            }

            if (s1.Length != s2.Length)
            {
                return false;
            }

            char[] charsOfS1 = s1.ToCharArray(), charsOfS2 = s2.ToCharArray();
            Array.Sort(charsOfS1);
            Array.Sort(charsOfS2);

            return charsOfS1.ToString() == charsOfS2.ToString();
        }

        // Solution 2: build a map between char and appear times in one string, and compare the other. Time complexty: O(n).
        public static bool CheckPermutationCharCount(string s1, string s2)
        {
            if (s1 == null || s2 == null)
            {
                return s1 == s2;
            }

            if (s1.Length != s2.Length)
            {
                return false;
            }

            Dictionary<char, int> charCountsInS1 = new Dictionary<char, int>();
            foreach (char c in s1)
            {
                if (!charCountsInS1.ContainsKey(c))
                {
                    charCountsInS1[c] = 0;
                }
                charCountsInS1[c]++;
            }

            // To save space, not build a char count for s2.
            foreach (char c in s2)
            {
                if (!charCountsInS1.ContainsKey(c))
                {
                    return false;
                }

                charCountsInS1[c]--;
                if (charCountsInS1[c] < 0)
                {
                    return false;
                }
            }

            // this is un-necessary, because two strings are equal length.
            foreach (KeyValuePair<char, int> charCount in charCountsInS1)
            {
                if (charCount.Value != 0)
                {
                    return false;
                }
            }

            return true;
        }
    }
}
