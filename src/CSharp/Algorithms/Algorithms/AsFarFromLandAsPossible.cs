using System;
using System.Collections.Generic;

namespace Algorithms
{
    /// <summary>
    /// Find the max of the closest distances to islands.
    /// In the ocean, put rescue ships on every island. What is the longest distance a ship need to sail to cover any points?
    /// </summary>
    /// <remarks>
    /// Leetcode 1162
    /// </remarks>
    public class AsFarFromLandAsPossible
    {
        // Solution 1: multi source BFS from 1s. Use a matrix to store visited cells.
        // Solution 2: DP from top-left and down-right twice.

        public static int MaxDistance(int[][] grid) {
            int n = grid.Length;

            if (n == 0) return 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        // the negative value is the distance to the close land.
                        BFS(grid, i, j);
                    }
                }
            }

            int maxDist = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0;j < n; j++)
                {
                    if (grid[i][j] < 0)
                    {
                        maxDist = Math.Max(maxDist, -grid[i][j]);
                    }
                }
            }

            return maxDist == 0 ? - 1 : maxDist;
        }

        private static void BFS(int[][] grid, int i, int j)
        {
            int n = grid.Length;

            Queue<int> xQueue = new();
            Queue<int> yQueue = new();
            Queue<int> dQueue = new();
            xQueue.Enqueue(i);
            yQueue.Enqueue(j);

            dQueue.Enqueue(0);

            while (xQueue.Count > 0)
            {
                int x = xQueue.Dequeue();
                int y = yQueue.Dequeue();
                int d = dQueue.Dequeue();

                if (d != 0 && grid[x][y] != 0 && -grid[x][y] <= d)
                {
                    continue;
                }

                grid[x][y] = d == 0 ? 1 : -d;

                d++;
                if (x > 0)
                {
                    xQueue.Enqueue(x - 1);
                    yQueue.Enqueue(y);
                    dQueue.Enqueue(d);
                }

                if (x < n - 1)
                {
                    xQueue.Enqueue(x + 1);
                    yQueue.Enqueue(y);
                    dQueue.Enqueue(d);
                }

                if (y > 0)
                {
                    xQueue.Enqueue(x);
                    yQueue.Enqueue(y - 1);
                    dQueue.Enqueue(d);
                }

                if (y < n - 1)
                {
                    xQueue.Enqueue(x);
                    yQueue.Enqueue(y + 1);
                    dQueue.Enqueue(d);
                }
            }
        }
    }
}
