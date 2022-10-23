/*
 * [Source] https://leetcode.com/problems/the-skyline-problem/
 * [Difficulty]: Hard
 * [Tag]: Binary Indexed Tree
 * [Tag]: Segment Tree
 * [Tag]: Heap
 * [Tag]: Divide and Conquer
 */

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

// [Solution]: Basically make end columns sort as high to low, first to last. When hit a start point, print all previous end columns. Print start column if it should print
// [Corner Case]:
class SolutionPriorityQueue {
public:
    struct EndHeight {
        int end;
        int height;
    };

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;

        priority_queue<EndHeight, vector<EndHeight>, function<bool(EndHeight, EndHeight)>> heights
            ( [](const EndHeight& h1, const EndHeight& h2) -> bool {return h1.height < h2.height;} );
        for (vector<int>& cur : buildings) {
            int st = cur[0], ed = cur[1], h = cur[2];

            // print dots that go down before the new start
            while (!heights.empty() && heights.top().end < st) { // end == st should not pop, otherwise leads to an unexpected {end, 0}
                int end = heights.top().end;
                heights.pop();
                int secondHeight = heights.empty() ? 0 : heights.top().height;
                pushRes(end, secondHeight, res, false);
            }

            // print the dot that goes up if necessary
            if (heights.empty() || heights.top().height < h) {
                pushRes(st, h, res, true);
            }

            // before insert the new building, clean up buildings that will not be print. Keeps the pq has buildings from tall to short, ends from eariler to later
            while (!heights.empty() && heights.top().height <= h && heights.top().end <= ed) {
                heights.pop();
            }

            // insert the new building end
            if (heights.empty() || heights.top().end < ed || heights.top().height < h) {
                heights.push({ed, h});
            }
        }

        while (!heights.empty()) {
            int end = heights.top().end;
            heights.pop();
            int secondHeight = heights.empty() ? 0 : heights.top().height;
            pushRes(end, secondHeight, res, false);
        }

        return res;
    }

    void pushRes(int coordinate, int height, vector<pair<int, int>>& res, bool isUp) {
        // 1. new up dot must after previous down dot
        // 2. in the last while loop, when printing remaining dots, since there is no start dot to clean those lower buildings end before, the res.back() should be keep
        // 3. while going up, if two dots has same coordinate, need print one
        if (!res.empty() && res.back().first >= coordinate) {
            if (isUp) {
                res.back().second = max(res.back().second, height);
            } else {
                res.back().second = min(res.back().second, height);
            }
        } else {
            res.push_back({coordinate, height});
        }
    }
};

// [Solution]: Scan line
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Point> points;
        for (vector<int> &building : buildings) {
            points.push_back( {building[0], -building[2]} );
            points.push_back( {building[1], building[2]} );
        }
        sort(points.begin(), points.end());

        map<int, int, greater<int>> heightCnt;
        heightCnt[0] = 1;

        vector<pair<int, int>> res;
        int preHeight = 0;
        for (Point &point : points) {
cout << point.x << "," << point.y << endl;
            if (point.y > 0) {
                heightCnt[point.y]--;
                if (heightCnt[point.y] == 0)
                    heightCnt.erase(point.y);
            } else {
                heightCnt[-point.y]++;
            }

            int curHeight = heightCnt.begin()->first;
            if (curHeight != preHeight) {
                res.push_back( {point.x, curHeight} );
                preHeight = curHeight;
            }
        }
        return res;
    }

private:
    struct Point {
        int x, y;
        bool operator<(const Point &other) const {
            // 1. if two points are all start, larger one should come first to cover the second one
            // 2. if two points are all end, smaller one should come first so that the larger one will deleted after it, and not create a dot of the smaller one
            // 3. if one start one end, start should come first, so that not goes to lower
            if (x < other.x)
                return true;
            if (x == other.x && y < other.y)
                return true;
            return false;
        }
    };
};

/* Java solution

 */

int main() {
    Solution sol;

    //vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> buildings = {{2, 9, 10}, {2, 7, 15}};
    //vector<vector<int>> buildings = {{3,10,20},{3,9,19},{3,8,18},{3,7,17},{3,6,16},{3,5,15},{3,4,14}};
    //vector<vector<int>> buildings = {{2,4,70},{3,8,30},{6,100,41},{7,15,70},{10,30,102},{15,25,76},{60,80,91},{70,90,72},{85,120,59}};
    vector<pair<int, int>> res = sol.getSkyline(buildings);
    for (pair<int, int>& p : res) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    return 0;
}
