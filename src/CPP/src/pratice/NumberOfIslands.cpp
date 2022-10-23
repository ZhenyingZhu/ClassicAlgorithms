#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// [Source]: https://leetcode.com/problems/number-of-islands/
// http://www.1point3acres.com/bbs/thread-224947-1-1.html

// [Solution]: Union find with path compression. Very easy to make mistake
class SolutionUnion {
public:
    int numberIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        dir = {1, 0, -1, 0, 1};

        int height = grid.size(), width =grid[0].size();
        vector<int> unionSet(height * width, -1);

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == '0')
                    continue;

                unionSet[i * width + j] = i * width + j;
                if (i > 0 && grid[i - 1][j] == '1')
                    unite(grid, i, j, i - 1, j, unionSet);
                if (j > 0 && grid[i][j - 1] == '1')
                    unite(grid, i, j, i, j - 1, unionSet);
            }
        }

        return countIsland(unionSet);
    }

    void unite(vector<vector<char>> &grid, int x1, int y1, int x2, int y2, vector<int> &unionSet) {
        int root1 = unionSet[x1 * grid[0].size() + y1];
        int root2 = unionSet[x2 * grid[0].size() + y2];
        if (root1 == root2) // to avoid cycle
            return;
        dfs(grid, x1, y1, root1, root2, unionSet); // set node 1 and its whole island to be root2
    }

    void dfs(vector<vector<char>> &grid, int x, int y, int root1, int root2, vector<int> &unionSet) {
        cout << x << "," << y << endl;
        int h = grid.size(), w = grid[0].size();
        if (x < 0 || x >= h || y < 0 || y >= w)
            return;
        if (unionSet[x * w + y] == root1) {
            unionSet[x * w + y] = root2;
            for (int i = 0; i < 4; ++i) {
                dfs(grid, x + dir[i], y + dir[i + 1], root1, root2, unionSet);
            }
        }
    }

    int countIsland(vector<int> &unionSet) {
        unordered_set<int> islands;
        for (int &root : unionSet) {
            cout << root << " ";
            if (root != -1)
                islands.insert(root);
        }
        cout << endl;
        return islands.size();
    }

    vector<int> dir;
};

// [Solution]: DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int h = grid.size(), w = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<char>> &grid, int x, int y) {
        int h = grid.size(), w = grid[0].size();

        if (x < 0 || x >= h || y < 0 || y >= w)
            return;
        if (grid[x][y] != '1')
            return;

        grid[x][y] = '*';

        vector<int> dir = {1, 0, -1, 0, 1};
        for (int d = 0; d < 4; ++d) {
            dfs(grid, x + dir[d], y + dir[d + 1]);
        }
    }
};

int main() {
    Solution sol;

    //vector<string> gridStr = {"111","010","111"};
    vector<string> gridStr = {"11110","11010","11000","00000"};
    vector<vector<char>> grid;
    for (string &str : gridStr)
        grid.push_back(vector<char>(str.begin(), str.end()));
    cout << sol.numIslands(grid) << endl;

    return 0;
}
