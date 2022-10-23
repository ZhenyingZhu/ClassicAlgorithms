/*
 * [Source] https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 * [Difficulty]: Medium
 * [Tag]: Binary Search
 * [Tag]: Heap
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// [Solution]: Use a heap for tracking smallest number. Every time get a number, push it's two next numbers into the heap, if they are not pushed.
// [Corner Case]:
class SolutionHeap {
public:
    struct Cell {
        int x, y;
        int num;
    };

    struct Cmp {
        bool operator()(const Cell &c1, const Cell &c2) {
            return c1.num > c2.num;
        }
    };

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int size = matrix.size();

        vector<vector<bool>> pushed(size, vector<bool>(size, false));
        priority_queue<Cell, vector<Cell>, Cmp> pq;
        pq.push( {0, 0, matrix[0][0]} );
        int cnt = 0;
        while (cnt < k - 1 && !pq.empty()) {
            ++cnt;
            Cell cur = pq.top();
            pq.pop();

            int x1 = cur.x + 1, y1 = cur.y;
            if (x1 < size && !pushed[x1][y1]) {
                pq.push( {x1, y1, matrix[x1][y1]} );
                pushed[x1][y1] = true;
            }
            int x2 = cur.x, y2 = cur.y + 1;
            if (y2 < size && !pushed[x2][y2]) {
                pq.push( {x2, y2, matrix[x2][y2]} );
                pushed[x2][y2] = true;
            }
        }

        return pq.top().num;
    }
};

// [Solution]: Binary search. Find the middle value by left up element and right down element. Then find the last smaller value in each line, and eliminate numbers before them, to see how many numbers are smaller than the middle. Then move left up index or right down index.

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    for (int i = 1; i <= 9; ++i)
        cout << sol.kthSmallest(matrix, i) << endl;

    return 0;
}
