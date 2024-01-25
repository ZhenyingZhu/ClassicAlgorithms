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
        public static int MaxDistance(int[][] grid)
        {
            int n = grid.Length;

            if (n == 0) return 0;

            int[][] dist = new int[n][];
            for (int i = 0; i < n; i++)
            {
                dist[i] = new int[n];
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = int.MaxValue;
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

            return (maxDist == int.MaxValue || maxDist == 0) ? - 1 : maxDist;
        }

        private static void BFS(int[][] grid, int[][] dist, int i, int j)
        {
            int n = grid.Length;

            Queue<int> xQueue = new();
            Queue<int> yQueue = new();
            Queue<int> dQueue = new();
            xQueue.Enqueue(i);
            yQueue.Enqueue(j);

            int curDist = 0;
            dQueue.Enqueue(curDist);

            while (xQueue.Count > 0)
            {
                int x = xQueue.Dequeue();
                int y = yQueue.Dequeue();
                int d = dQueue.Dequeue();

                if (x < 0 || x >= n || y < 0 || y >= n)
                {
                    continue;
                }

                if (dist[x][y] <= d + 1)
                {
                    continue;
                }

                // ?
                dist[x][y] = d;

                xQueue.Enqueue(x - 1);
                yQueue.Enqueue(y);
                dQueue.Enqueue(d + 1);

                xQueue.Enqueue(x + 1);
                yQueue.Enqueue(y);
                dQueue.Enqueue(d + 1);

                xQueue.Enqueue(x);
                yQueue.Enqueue(y - 1);
                dQueue.Enqueue(d + 1);

                xQueue.Enqueue(x);
                yQueue.Enqueue(y + 1);
                dQueue.Enqueue(d + 1);
            }
        }
    }
}
