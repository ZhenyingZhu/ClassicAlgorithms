using System;
using System.Collections.Generic;
using System.Net.NetworkInformation;

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
        public static int MaxDistanceBFS(int[][] grid)
        {
            int n = grid.Length;
            bool[][] visited = new bool[n][];
            for (int i = 0; i < n; i++)
            {
                visited[i] = new bool[n];
            }

            Queue<Tuple<int, int>> queue = new();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        visited[i][j] = true;
                        queue.Enqueue(Tuple.Create(i, j));
                    }
                }
            }

            int[][] directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
            int distance = -1;
            while (queue.Count > 0)
            {
                int size = queue.Count;
                distance++;
                for (int i = 0; i < size; i++)
                {
                    Tuple<int, int> tuple = queue.Dequeue();
                    foreach (var direction in directions)
                    {
                        int x = tuple.Item1 + direction[0];
                        int y = tuple.Item2 + direction[1];
                        if (x >= 0 && y >= 0 && x < n && y < n && !visited[x][y])
                        {
                            queue.Enqueue(Tuple.Create(x, y));
                            visited[x][y] = true;
                        }
                    }
                }
            }

            return distance == 0 ? -1 : distance;
        }

        // Solution 2: DP from top-left and down-right twice.
        public static int MaxDistanceDP(int[][] grid)
        {
            int n = grid.Length;
            int[][] distances = new int[n][];
            for (int i = 0; i < n; i++)
            {
                distances[i] = new int[n];
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        distances[i][j] = 0;
                    }
                    else if (i == 0 && j == 0)
                    {
                        distances[i][j] = 2 * n;
                    }
                    else if (i == 0)
                    {
                        distances[i][j] = distances[i][j - 1] + 1;
                    }
                    else if (j == 0)
                    {
                        distances[i][j] = distances[i - 1][j] + 1;
                    }
                    else
                    {
                        distances[i][j] = Math.Min(distances[i - 1][j], distances[i][j - 1]) + 1;
                    }
                }
            }

            int maxDist = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if (i == n - 1 && j == n - 1)
                    {
                    }
                    else if (i == n - 1)
                    {
                        distances[i][j] = Math.Min(distances[i][j], distances[i][j + 1] + 1);
                    }
                    else if (j == n - 1)
                    {
                        distances[i][j] = Math.Min(distances[i][j], distances[i + 1][j] + 1);
                    }
                    else
                    {
                        distances[i][j] = Math.Min(distances[i][j], Math.Min(distances[i][j + 1] + 1, distances[i + 1][j] + 1));
                    }

                    maxDist = Math.Max(maxDist, distances[i][j]);
                }
            }

            if (maxDist == 0 || maxDist >= 2 * n)
            {
                return -1;
            }
            else
            {
                return maxDist;
            }
        }

        // Solution 3: use negative value to update the original input.
        public static int MaxDistanceSpaceOptimized(int[][] grid) {
            int n = grid.Length;

            if (n == 0) return 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        // the negative value is the distance to the close land.
                        BFSSpaceOpt(grid, i, j);
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

        private static void BFSSpaceOpt(int[][] grid, int i, int j)
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
