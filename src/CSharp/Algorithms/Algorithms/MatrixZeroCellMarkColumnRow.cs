using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms
{
    /// <summary>
    /// For a cell that is zero, mark the whole row and column as zero.
    /// Uncertainties:
    /// 1. In place?
    /// </summary>
    /// <remarks>
    /// CC 189 6th 1.8
    /// </remarks>
    public class MatrixZeroCellMarkColumnRow
    {
        // Solution 1: Use two arrays to indicate whether a row and a column needs to mark as 0.
        public static void ZeroMatrixTwoIndicators(int[][] matrix)
        {
            if (matrix == null || matrix[0] == null)
            {
                return;
            }

            int[] rows = new int[matrix.Length];
            int[] colums = new int[matrix[0].Length];

            for (int i = 0; i < matrix.Length; i++)
            {
                if (matrix[i].Length != matrix[0].Length)
                {
                    return;
                }

                for (int j = 0; j < matrix[i].Length; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        rows[i] = 1;
                        colums[j] = 1;
                    }
                }
            }

            // Instead of traverse through the whole matrix, can just visit rows and columns that needs to be
            // marked as 0.
            for (int i = 0; i < matrix.Length; i++)
            {
                for (int j = 0; j < matrix[i].Length; j++)
                {
                    if (rows[i] == 1 || colums[j] == 1)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // Solution 2: A little more complicate, but save two new arrays.
        public static void ZeroMatrixInPlace(int[][] matrix)
        {
            if (matrix == null || matrix[0] == null)
            {
                return;
            }

            bool firstRowHasZero = false, firstColumnHasZero = false;
            for (int i = 0; i < matrix.Length; i++)
            {
                if (matrix[i][0] == 0)
                {
                    // can break the loop already.
                    firstColumnHasZero = true;
                }
            }

            for (int j = 0; j < matrix[0].Length; j++)
            {
                if (matrix[0][j] == 0)
                {
                    firstRowHasZero = true;
                }
            }

            for (int i = 1; i < matrix.Length; i++)
            {
                if (matrix[i].Length != matrix[0].Length)
                {
                    return;
                }

                for (int j = 1; j < matrix[i].Length; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            for (int i = 1; i < matrix.Length; i++)
            {
                for (int j = 1; j < matrix[i].Length; j++)
                {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }

            if (firstRowHasZero)
            {
                for (int j = 0; j < matrix[0].Length; j++)
                {
                    matrix[0][j] = 0;
                }
            }

            if (firstColumnHasZero)
            {
                for (int i = 0; i < matrix.Length; i++)
                {
                    matrix[i][0] = 0;
                }
            }
        }
    }
}
