using System;
using System.Collections.Generic;

namespace Algorithms
{
    /// <summary>
    /// 
    /// </summary>
    /// <remarks>
    /// Leetcode 1162
    /// </remarks>
    public class AsFarFromLandAsPossible
    {
        public int MaxDistance(int[][] grid)
        {
            int n = grid.Length;

            int[][] dist = new int[n][];
            for (int i = 0; i < n; i++)
            {
                dist[i] = new int[n];
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = grid[i][j] == 1 ? 0 : int.MaxValue;
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        BFS(grid, dist, i, j);
                    }
                }
            }

            int maxDist = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0;j < n; j++)
                {
                    if (dist[i][j] > maxDist)
                    {
                        maxDist = dist[i][j];
                    }
                }
            }

            return maxDist == 0 ? - 1 : maxDist;
        }

        private void BFS(int[][] grid, int[][] dist, int i, int j)
        {
            int n = grid.Length;

            Queue<int> xQueue = new();
            Queue<int> yQueue = new();
            xQueue.Enqueue(i);
            yQueue.Enqueue(j);

            int curDist = 0;
            while (xQueue.Count > 0)
            {
                int x = xQueue.Dequeue();
                int y = yQueue.Dequeue();

                if (x < 0 || x >= n || y < 0 || y >= n)
                {
                    continue;
                }

                if (dist[x][y] <= curDist)
                {
                    continue;
                }

                // ?
                dist[x][y] = curDist;

                xQueue.Enqueue(x - 1);
                yQueue.Enqueue(y);

                xQueue.Enqueue(x + 1);
                yQueue.Enqueue(y);

                xQueue.Enqueue(x);
                yQueue.Enqueue(y - 1);

                xQueue.Enqueue(x);
                yQueue.Enqueue(y + 1);
            }
        }
    }
}
