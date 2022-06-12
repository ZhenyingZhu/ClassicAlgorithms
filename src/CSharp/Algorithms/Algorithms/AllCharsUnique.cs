using System;
using System.Collections.Generic;

namespace Algorithms
{
    /// <summary>
    /// Whether all the chars in a string are unique.
    /// CC189 6th 1.1
    /// </summary>
    public class AllCharsUnique
    {
        // Solution 1: two for loops compare each char with another.

        // Solution 2: Use hash set.
        public static bool IsUniqueHashSet(string input)
        {
            HashSet<char> appearedChars = new HashSet<char>();
            foreach (char c in input)
            {
                if (appearedChars.Contains(c))
                {
                    return false;
                }

                appearedChars.Add(c);
            }

            return true;
        }

        // Solution 3: when input is ASCII, use a bool array.
        public static bool IsUniqueBoolArray(string input)
        {
            if (input.Length > 128)
            {
                return false;
            }

            bool[] charArray = new bool[128];
            foreach (char c in input)
            {
                if (charArray[c])
                {
                    return false;
                }

                charArray[c] = true;
            }

            return true;
        }

        // Solution 4: when input is ASCII alphabet and numbers, use int.
        public static bool IsUniqueInt(string input)
        {
            if (input.Length > 128)
            {
                return false;
            }

            int numBitSet = 0, upperBitSet = 0, lowerBitSet = 0;

            foreach (char c in input)
            {
                if (c <= 57)
                {
                    // 0 is 48. 9 is 57.
                    if (CheckBitSetOtherwiseSet(ref numBitSet, c - '0'))
                    {
                        return false;
                    }
                }
                else if (c <= 90)
                {
                    // A is 65. Z is 90.
                    if (CheckBitSetOtherwiseSet(ref upperBitSet, c - 'A'))
                    {
                        return false;
                    }
                }
                else if (c <= 122)
                {
                    // a is 97. z is 122.
                    if (CheckBitSetOtherwiseSet(ref lowerBitSet, c - 'a'))
                    {
                        return false;
                    }
                }
            }

            return true;
        }

        private static bool CheckBitSetOtherwiseSet(ref int bitset, int offset)
        {
            if ((bitset >> offset & 1) == 1)
            {
                return true;
            }

            bitset = bitset | (1 << offset);
            return false;
        }
    }
}
