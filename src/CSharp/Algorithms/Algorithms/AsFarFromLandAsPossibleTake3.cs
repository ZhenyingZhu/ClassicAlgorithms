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
        public static int DFS(int[][] grid)
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

            return dist == 0 ? -1 : dist;
        }
    }
}