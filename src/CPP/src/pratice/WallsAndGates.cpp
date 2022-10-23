#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// [Source]: https://leetcode.com/problems/walls-and-gates/
// http://www.1point3acres.com/bbs/thread-225124-1-1.html

class Solution {
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < (int)rooms.size(); ++i) {
            for (int j = 0; j < (int)rooms[0].size(); ++j) {
                if (rooms[i][j] == 0)
                    bfs(rooms, i, j);
            }
        }
    }

private:
    void bfs(vector<vector<int>> &rooms, int i, int j) {
        int height = rooms.size(), width = rooms[0].size();
        queue<Node> q;
        Node n{i, j, 0};
        q.push(n);

        while (!q.empty()) {
            Node cur = q.front();
            q.pop();
            rooms[cur.x][cur.y] = cur.depth;

            for (vector<int> &dir : dirs) {
                int x = cur.x + dir[0], y = cur.y + dir[1];
                if (x >= 0 && x < height && y >= 0 && y < width && rooms[x][y] > cur.depth + 1)
                    q.push( {x, y, cur.depth + 1} );
            }
        }
    }

private:
    struct Node {
        int x, y, depth;
    };

    vector<vector<int>> dirs;
};

int main() {
    Solution sol;

    vector<vector<int>> rooms = {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}
    };

    sol.wallsAndGates(rooms);
    for (vector<int> &vec : rooms) {
        for (int &i : vec)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
