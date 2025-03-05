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
    public class AsFarFromLandAsPossibleTake3
    {
        public int DFS(int[][] grid)
        {
            int n = grid.length;

            Queue<int[]> queue = new LinkedList<>();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        queue.enqueue(new int[] { i, j });
                    }
                }
            }

            bool[][] visited = new int[n][n];
            int[][] directions = new int[][] { new int[] { -1, 0 }, new int[] { 1, 0 }, new int[] { 0, -1 }, new int[] { 0, 1 } };
        }
    }
}