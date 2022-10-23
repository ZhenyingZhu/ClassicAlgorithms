/*
 * [Source] https://leetcode.com/problems/max-sum-of-sub-matrix-no-larger-than-k/
 * [Difficulty]: Hard
 * [Tag]: Binary Search
 * [Tag]: Dynamic Programming
 * [Tag]: Queue
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

// [Solution]: Brute force, but since it use array instead of vector; not use sential cells to indicate smaller than 0 sums; not use sub function, it can pass the leetcode OJ(which means leetcode OJ set the time bound too tight)
// [Corner Case]:
class SolutionBF {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int height = matrix.size(), width = matrix[0].size();
        int areas[height][width];

        int closest = INT_MIN;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                // compute area of (0,0) to (i,j)
                int area = matrix[i][j];
                if (i > 0)
                    area += areas[i - 1][j];
                if (j > 0)
                    area += areas[i][j - 1];
                if (i > 0 && j > 0)
                    area -= areas[i - 1][j - 1];
                areas[i][j] = area;

                // compute area of (x,y) to (i,j)
                for (int x = 0; x <= i; ++x) {
                    for (int y = 0; y <= j; ++y) {
                        int sum = area;
                        if (x > 0)
                            sum -= areas[x - 1][j];
                        if (y > 0)
                            sum -= areas[i][y - 1];
                        if (x > 0 && y > 0)
                            sum += areas[x - 1][y - 1];

cout << "(" << x << "," << y << ") - " << "(" << i << "," << j << ") = " << sum << endl;

                        if (sum <= k && sum > closest)
                            closest = sum;
                    }
                }
            }
        }
        return closest;
    }
};

// [Solution]: traverse between all combination of cols. Then use difference sums.
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int res = INT_MIN;

        int height = matrix.size(), width = matrix[0].size();
        for (int startCol = 0; startCol < width; ++startCol) {
            vector<int> areas(height, 0);
            for (int endCol = startCol; endCol < width; ++endCol) {
                for (int row = 0; row < height; ++row) {
                    areas[row] += matrix[row][endCol]; // sum from (row, startCol) to (row, endCol)
                }

                set<int> sums;
                sums.insert(0);

                int sum = 0;
                for (int &area : areas) {
                    sum += area; // sum from (0, startCol) to (row, endCol)
                    auto it = sums.lower_bound(sum - k); // sum - pre <= k, find smallest pre
                    if (it != sums.end()) {
                        res = max(sum - *it, res);
                    }

                    sums.insert(sum);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    /*
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {0, -2, 3}
    };
    */
    vector<vector<int>> matrix = {{2, 2, -1}};

    cout << sol.maxSumSubmatrix(matrix, 3) << endl;

    return 0;
}
