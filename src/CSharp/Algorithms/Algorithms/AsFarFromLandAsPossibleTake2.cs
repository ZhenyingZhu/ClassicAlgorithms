using System;
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
    public class AsFarFromLandAsPossibleTake2
    {
        public static int MaxDistanceBFS(int[][] grid)
        {
            int n = grid.Length;
            bool[,] visited = new bool[n, n];

            Queue<Tuple<int, int>> visiting = new();
            for (int i  = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        visited[i, j] = true;
                        visiting.Enqueue(Tuple.Create(i, j));
                    }
                }
            }

            int[][] directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];

            int dist = -1;
            while (visiting.Any())
            {
                dist++;
                int size = visiting.Count;
                for (int i = 0; i < size; i++)
                {
                    Tuple<int, int> st = visiting.Dequeue();
                    foreach (var direction  in directions)
                    {
                        int x = st.Item1 + direction[0];
                        int y = st.Item2 + direction[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && !visited[x, y])
                        {
                            visiting.Enqueue(Tuple.Create(x, y));
                            visited[x, y] = true;
                        }
                    }
                }
            }

            return dist == 0 ? -1 : dist;
        }

        public static int MaxDistanceDP(int[][] grid)
        {
            int n = grid.Length;
            int max = 2 * n;
            int[,] distances = new int[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        distances[i, j] = 0;
                    }
                    else
                    {
                        int up = i == 0 ? max : distances[i - 1, j];
                        int left = j == 0 ? max : distances[i, j - 1];
                        distances[i, j] = Math.Min(left, up) == max ? max : Math.Min(left, up) + 1;
                    }
                }
            }

            int maxDistance = -1;
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if (grid[i][j] != 1)
                    {
                        int down = i == n - 1 ? max : distances[i + 1, j];
                        int right = j == n - 1 ? max : distances[i, j + 1];
                        distances[i, j] = Math.Min(distances[i, j], Math.Min(down, right) == max ? max : Math.Min(down, right) + 1);

                        maxDistance = Math.Max(maxDistance, distances[i, j]);
                    }
                }
            }

            return maxDistance == max ? -1 : maxDistance;
        }
    }
}
