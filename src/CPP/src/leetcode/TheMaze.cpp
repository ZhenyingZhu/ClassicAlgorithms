/*
 * [Source] https://leetcode.com/problems/the-maze/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// [Solution]:
// [Corner Case]:
class SolutionTLE {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int> start, vector<int> destination) {
        // dir: 0: left, 1: down, 2: right, 3: up
        return dfs(maze, start[0], start[1], destination[0], destination[1]);
    }

private:
    bool dfs(vector<vector<int>> &maze, int curX, int curY, int desX, int desY) {
        if (maze[curX][curY] == 2)
            return false;
        maze[curX][curY] = 2; // visited

        for (int i = 0; i < 4; i++) {
            vector<int> next = findNext(maze, curX, curY, i, desX, desY);
            if (next[0] == desX && next[1] == desY)
                return true;
            if (next[0] == -1 && next[1] == -1)
                continue;

            if (dfs(maze, next[0], next[1], desX, desY)) {
                cout << "(" << next[0] << "," << next[1] << ")" << endl;
                return true;
            }
        }

        maze[curX][curY] = 0;
        return false;
    }

    vector<int> findNext(vector<vector<int>> &maze, int x, int y, int dir, int desX, int desY) {
        int preX = x, preY = y;
        while (x >= 0 && x < (int)maze.size() && y >= 0 && y < (int)maze[0].size() && maze[x][y] != 1) {
            preX = x;
            preY = y;
            x += dirs[dir];
            y += dirs[dir + 1];
        }
        if ( (x == preX && y == preY) || maze[preX][preY] == 2 )
            return {-1, -1};
        return {preX, preY};
    }

    vector<int> dirs = {-1, 0, 1, 0, -1};
};

// [Solution]:
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int> start, vector<int> destination) {
        preprocess(maze);
        return bfs(start[0], start[1], maze, destination[0], destination[1]);
    }

    bool bfs(int srcX, int srcY, vector<vector<int>> &maze, int desX, int desY) {
        queue<int> q;
        q.push(getCode(srcX, srcY));
        while (!q.empty()) {
            vector<int> cur = getCoor(q.front());
            q.pop();

            int x = cur[0], y = cur[1];
            maze[x][y] = 2; // tag

            for (int i = 0; i < 4; ++i) {
                vector<int> next = getNext(x, y, i);
                if (next[0] == x && next[1] == y)
                    continue;
                if (maze[next[0]][next[1]] == 2)
                    continue;
                if (next[0] == desX && next[1] == desY)
                    return true;
                q.push(getCode(next[0], next[1]));
            }
        }
        return false;
    }

private:
    vector<int> dirs;
    vector<vector<vector<int>>> stopPoint;
    int w;

    void preprocess(vector<vector<int>> &maze) {
        int h = maze.size();
        w = maze[0].size();
        dirs = {-1, 0, 1, 0, -1}; // up, right, down, left
        stopPoint.resize(4, vector<vector<int>>(h, vector<int>(w)));

        // left
        for (int i = 0; i < h; ++i) {
            int stop = 0;
            for (int j = 0; j < w; ++j) {
                if (maze[i][j] == 1) {
                    stop = j + 1;
                    stopPoint[3][i][j] = -1;
                } else {
                    stopPoint[3][i][j] = stop;
                }
            }
        }
        // down
        for (int i = 0; i < w; ++i) {
            int stop = h - 1;
            for (int j = h - 1; j >= 0; --j) {
                if (maze[j][i] == 1) {
                    stop = j - 1;
                    stopPoint[2][j][i] = -1;
                } else {
                    stopPoint[2][j][i] = stop;
                }
            }
        }
        // right
        for (int i = 0; i < h; ++i) {
            int stop = w - 1;
            for (int j = w - 1; j >= 0; --j) {
                if (maze[i][j] == 1) {
                    stop = j - 1;
                    stopPoint[1][i][j] = -1;
                } else {
                    stopPoint[1][i][j] = stop;
                }
            }
        }
        // up
        for (int i = 0; i < w; ++i) {
            int stop = 0;
            for (int j = 0; j < h; ++j) {
                if (maze[j][i] == 1) {
                    stop = j + 1;
                    stopPoint[0][j][i] = -1;
                } else {
                    stopPoint[0][j][i] = stop;
                }
            }
        }
    }

    vector<int> getNext(int x, int y, int dir) {
        if (dir % 2 == 0) {
            // up or down
            return {stopPoint[dir][x][y], y};
        } else {
            // left or right
            return {x, stopPoint[dir][x][y]};
        }
    }

    int getCode(int x, int y) {
        return x * w + y;
    }

    vector<int> getCoor(int code) {
        return {code / w, code % w};
    }
};

int main() {
    Solution sol;

    vector<vector<int>> maze = {
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,1,0},
        {1,1,0,1,1},
        {0,0,0,0,0}
    };
    cout << sol.hasPath(maze, {0,4}, {3,2}) << endl;
    //cout << sol.hasPath(maze, {0,4}, {4,2}) << endl;

    return 0;
}
