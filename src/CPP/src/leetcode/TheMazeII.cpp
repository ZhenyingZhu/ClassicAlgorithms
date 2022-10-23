/*
 * [Source] https://leetcode.com/problems/the-maze-ii
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 */

#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

// [Corner Case]:
class Solution {
public:
    // [Solution]: TLE
    int shortestDistanceDFS(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty() || maze[0].empty())
            return 0;
        initStopPos(maze);

        vector<vector<int>> dp(maze.size(), vector<int>(maze[0].size(), INT_MAX)); // INT_MAX indicate not visited
        int res = dfs(start[0], start[1], dp, maze, destination);

        return res;
    }

    // Dijkstra
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        if (maze.empty() || maze[0].empty())
            return 0;
        initStopPos(maze);

        vector<vector<int>> dp(maze.size(), vector<int>(maze[0].size(), INT_MAX)); // INT_MAX indicate not visited
        priority_queue<Point> pq;
        pq.push( { start[0], start[1], 0, {0,1,2,3} } );
        int res = INT_MAX;
        while (!pq.empty()) {
            Point cur = pq.top();
cout << "checking " << cur.x << "," << cur.y << "=" << cur.path << endl;
            pq.pop();
            if (cur.x == destination[0] && cur.y == destination[1]) {
                res = cur.path;
                break;
            }

            if (dp[cur.x][cur.y] <= cur.path)
                continue;
            dp[cur.x][cur.y] = cur.path;

            for (int dir : cur.nextDir) {
                vector<int> next = getNext(cur.x, cur.y, dir);
                vector<int> nextDir;
                if (dir % 2 == 0) {
                    nextDir = {1, 3};
                } else {
                    nextDir = {0, 2};
                }
cout << nextDir[0] << nextDir[1] << next[0] << next[1] << next[2] << endl;
                pq.push( {next[0], next[1], cur.path + next[2], nextDir} );
            }
        }

        for (int i = 0; i < maze.size(); i++) {
            for (int j = 0; j < maze[0].size(); j++) {
                if (dp[i][j] == INT_MAX)
                    cout << "b, \t";
                else
                    cout << dp[i][j] << ",\t";
            }
            cout << endl;
        }


        return res == INT_MAX ? -1 : res;
    }

private:
    struct Point {
        int x, y;
        int path;
        vector<int> nextDir;
        bool operator<(const Point &other) const {
            return path > other.path;
        }
    };

private:
    // dir: 0 left, 1 down, 2 right, 3 up
    vector<vector<int>> up, down, left, right; // from a cell, where can it stop

    void initStopPos(vector<vector<int>> &maze) {
        int h = maze.size(), w = maze[0].size();
        up.resize(h, vector<int>(w));
        down.resize(h, vector<int>(w));
        left.resize(h, vector<int>(w));
        right.resize(h, vector<int>(w));

        // left
        for (int i = 0; i < h; i++) {
            int obstacle = -1;
            for (int j = 0; j < w; j++) {
                if (maze[i][j] == 1)
                    obstacle = j;
                else
                    left[i][j] = obstacle + 1;
            }
        }

        // right
        for (int i = 0; i < h; i++) {
            int obstacle = w;
            for (int j = w - 1; j >= 0; j--) {
                if (maze[i][j] == 1)
                    obstacle = j;
                else
                    right[i][j] = obstacle - 1;
            }
        }

        // up
        for (int j = 0; j < w; j++) {
            int obstacle = -1;
            for (int i = 0; i < h; i++) {
                if (maze[i][j] == 1)
                    obstacle = i;
                else
                    up[i][j] = obstacle + 1;
            }
        }

        // down
        for (int j = 0; j < w; j++) {
            int obstacle = h;
            for (int i = h - 1; i >= 0; i--) {
                if (maze[i][j] == 1)
                    obstacle = i;
                else
                    down[i][j] = obstacle - 1;
            }
        }
    }

    vector<int> getNext(int x, int y, int dir) {
        // return: {nextX, nextY, steps}
        // dir: 0 left, 1 down, 2 right, 3 up
        switch(dir) {
            case 0: return {x, left[x][y], y - left[x][y]};
            case 1: return {down[x][y], y, down[x][y] - x};
            case 2: return {x, right[x][y], right[x][y] - y};
            case 3: return {up[x][y], y, x - up[x][y]};
            default: cout << "Wrong dir: " << dir << endl;return {};
        }
    }

private: // For DFS solution
    int dfs(int x, int y, vector<vector<int>> &dp, vector<vector<int>> &maze, vector<int> &dest) {
        // The problem is here. Since DFS can reach a point without pick the shortest path, cannot use DP here
        //if (dp[x][y] != INT_MAX)
        //    return dp[x][y];

        if (x == dest[0] && y == dest[1]) {
            dp[x][y] = 0;
            return 0;
        }

        maze[x][y] = 2;
        for (int dir = 0; dir < 4; dir++) {
            vector<int> next = getNext(x, y, dir);
            if (maze[next[0]][next[1]] == 2) // cycle
                continue;

            int totalDis = dfs(next[0], next[1], dp, maze, dest);
            if (totalDis == -1)
                continue;
            totalDis += next[2];

            dp[x][y] = min(dp[x][y], totalDis);
        }
        maze[x][y] = 0;

        if (dp[x][y] == INT_MAX)
            dp[x][y] = -1;
        return dp[x][y];
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<vector<int>> maze = {
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,1,0},
        {1,1,0,1,1},
        {0,0,0,0,0}
    };
    vector<int> start = {0, 4}, dest = {4,4};

    cout << sol.shortestDistance(maze, start, dest) << endl;

    return 0;
}
