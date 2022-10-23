#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// [source]: http://www.1point3acres.com/bbs/thread-228718-3-1.html

// If water comes rain
class SolutionIfInside {
public:
    int countDays(vector<vector<int>> &matrix, int srcX, int srcY,  int destX, int destY) {
        int h = matrix.size(), w = matrix[0].size();
        vector<vector<int>> minHeights(h, vector<int>(w, INT_MAX));

        // bfs from src
        dirs = {1, 0, -1, 0, 1};
        queue<Point> visiting;
        visiting.push( {srcX, srcY, 0} );
        while (!visiting.empty()) {
            Point &p = visiting.front();
            visiting.pop();
            int prevHeight = max(p.prevHeight, matrix[p.x][p.y]);
            if (prevHeight >= minHeights[p.x][p.y])
                continue;

            minHeights[p.x][p.y] = prevHeight;

cout << p.x << "," << p.y << ": " << prevHeight << endl;
for (vector<int> &vec : minHeights) {
    for (int &num : vec)
        cout << num << ",";
    cout << endl;
}
cout << endl;

            for (int d = 0; d < 4; ++d) {
                int nextX = p.x + dirs[d], nextY = p.y + dirs[d + 1];
                if (nextX < 0 || nextX >= h || nextY < 0 || nextY >= w) {
                    continue;
                }
                visiting.push( {nextX, nextY, prevHeight} );
            }
        }

        return minHeights[destX][destY];
    }

private:
    struct Point {
        int x, y;
        int prevHeight;
    };

    vector<int> dirs;
};

// [source]: if water comes from outside
// need use trap rain water II.

int main() {
    Solution sol;

    vector<vector<int>> matrix = { {5,5,5},{4,5,2},{1,1,1} };
    cout << sol.countDays(matrix, 1, 2, 1, 0) << endl;

    return 0;
}
