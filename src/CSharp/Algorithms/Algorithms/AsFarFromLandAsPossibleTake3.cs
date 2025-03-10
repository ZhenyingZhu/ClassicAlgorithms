using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithms
{
    /// <summary>
    /// Find the max of the closest distances to islands.
    /// In the ocean, put rescue ships on every island. What is the longest distance a ship need to sail to cover any points?
    /// </summary>
    /// <remarks>
    /// Leetcode 1162
    /// </remarks>
    public class AsFarFromLandAsPossibleTake3
    {
        public static int MaxDistanceBFS(int[][] grid)
        {
            int n = grid.Length;

            bool[][] visited = new bool[n][];
            for (int i = 0; i < n; i++)
            {
                visited[i] = new bool[n];
            }

            Queue<int[]> queue = new ();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        queue.Enqueue(new int[] { i, j });
                        visited[i][j] = true;
                    }
                }
            }

            int dist = -1;
            int[] directions = { -1, 0, 1, 0, -1 };
            while (queue.Any())
            {
                int size = queue.Count;
                for (int k = 0; k < size; k++)
                {
                    int[] point = queue.Dequeue();
                    for (int i = 0; i < 4; i++)
                    {
                        int x = point[0] + directions[i];
                        int y = point[1] + directions[i + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y])
                        {
                            queue.Enqueue(new int[] { x, y });
                            visited[x][y] = true;
                        }
                    }
                }
                dist++;
            }

            // -1 can happen when no island
            // 0 can happen all islands
            return dist == 0 ? -1 : dist;
        }

        public static int MaxDistanceDP(int[][] grid)
        {
            int n = grid.Length;
            int[,] topLeft = new int[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        topLeft[i, j] = 0;
                    }
                    else
                    {
                        int top = i > 0 ? topLeft[i - 1, j] : int.MaxValue;
                        int left = j > 0 ? topLeft[i, j - 1] : int.MaxValue;
                        int min = Math.Min(top, left);
                        topLeft[i, j] = min == int.MaxValue ? int.MaxValue : min + 1;
                    }
                }
            }

            int[,] bottomRight = new int[n, n];
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if (grid[i][j] == 1)
                    {
                        bottomRight[i, j] = 0;
                    }
                    else
                    {
                        int bottom = i < n - 1 ? bottomRight[i + 1, j] : int.MaxValue;
                        int right = j < n - 1 ? bottomRight[i, j + 1] : int.MaxValue;
                        int min = Math.Min(bottom, right);
                        bottomRight[i, j] = min == int.MaxValue ? int.MaxValue : min + 1;
                    }
                }
            }

            int max = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (topLeft[i, j] != 0)
                    {
                        max = Math.Max(max, Math.Min(topLeft[i, j], bottomRight[i, j]));
                    }
                }
            }

            return max == int.MaxValue || max == 0 ? -1 : max;
        }
    }
}