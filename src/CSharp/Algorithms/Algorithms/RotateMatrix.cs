using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// Rotate a NxN metrix 90 degree. Each pixel is 4 bytes.
    /// Uncertainties:
    /// </summary>
    /// <remarks>
    /// CC189 6th 1.7
    /// </remarks>
    public class RotateMatrix
    {
        public static int[][] RotateMatrixBruteForce(int[][] matrix)
        {
            int n = matrix.Length;
            int[][] newMatrix = new int[n][];
            for (int i = 0; i < n; i++)
            {
                newMatrix[i] = new int[n];
                for (int j = 0; j < n; j++)
                {
                    newMatrix[i][j] = matrix[n - j - 1][i];
                }
            }
            return newMatrix;
        }

        // Solution 1: Swap two cells to rotate it in place.
        // [x][y] moves to [n-y-1][x]
        // [x][y] gets the value from [y][n-x-1]
        public static void RotateMatrixInPlace(int[][] matrix)
        {
            if (matrix == null || matrix[0] == null || matrix.Length != matrix[0].Length)
            {
                return;
            }

            for (int i = 0; i < matrix.Length / 2; i++)
            {
                for (int j = i; j < matrix.Length - i - 1; j++)
                {
                    SwapFourCells(matrix, i, j);
                }
            }
        }

        private static void SwapFourCells(int[][] matrix, int x, int y)
        {
            int cur = matrix[x][y];

            for (int i = 0; i < 3; i++)
            {
                Tuple<int, int> getFrom = CellToGetTheValue(x, y, matrix.Length);
                matrix[x][y] = matrix[getFrom.Item1][getFrom.Item2];
                x = getFrom.Item1;
                y = getFrom.Item2;
            }

            matrix[x][y] = cur;
        }

        private static Tuple<int, int> CellToGetTheValue(int x, int y, int n)
        {
            return new Tuple<int, int>(n - y - 1, x);
        }
    }
}
