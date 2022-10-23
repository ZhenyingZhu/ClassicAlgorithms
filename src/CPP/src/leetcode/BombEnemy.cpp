/*
 * [Source] https://leetcode.com/problems/bomb-enemy/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// [Solution]: Use queues to store ememies on rows and cols before walls.
// [Corner Case]:
class Solution {
public:
    struct PosEnemy {
        int pos;
        int enemy;
    };

    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int m = grid.size(), n = grid[0].size();
        vector<queue<PosEnemy>> rows(m);
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'E') {
                    ++cnt;
                } else if (grid[i][j] == 'W') {
                    rows[i].push( {j, cnt} );
                    cnt = 0;
                }
            }
            rows[i].push( {n, cnt} );
        }
        vector<queue<PosEnemy>> cols(n);
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 'E') {
                    ++cnt;
                } else if (grid[i][j] == 'W') {
                    cols[j].push( {i, cnt} );
                    cnt = 0;
                }
            }
            cols[j].push( {m, cnt} );
        }

        int maxRes = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != '0')
                    continue;

                while (rows[i].front().pos < j)
                    rows[i].pop();
                int rowEnemy = rows[i].front().enemy;

                while (cols[j].front().pos < i)
                    cols[j].pop();
                int colEnemy = cols[j].front().enemy;

                maxRes = max(rowEnemy + colEnemy, maxRes);
            }
        }
        return maxRes;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<string> gridStr = {"0E00","E0WE","0E00"};
    vector<vector<char>> grid;
    for (string &str : gridStr)
        grid.push_back( vector<char>(str.begin(), str.end()) );

    cout << sol.maxKilledEnemies(grid) << endl;

    return 0;
}
