using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;

namespace AlgorithmsTests
{
    [TestClass]
    public class CharArrayURLifyTest
    {
        [TestMethod]
        public void TestURLifyInplace()
        {
            char[] url = CreateCharArray(" a ", 9);
            CharArrayURLify.URLifyInplace(url, 3);
            string res = ConstructStringFromCharArray(url);
            Assert.AreEqual("%20a%20", res);
        }

        private char[] CreateCharArray(string input, int length)
        {
            char[] chars = new char[length];
            for (int i = 0; i < input.Length; i++)
            {
                chars[i] = input[i];
            }

            return chars;
        }

        private string ConstructStringFromCharArray(char[] array)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < array.Length && array[i] != '\0'; i++)
            {
                sb.Append(array[i]);
            }

            return sb.ToString();
        }

    }
}
