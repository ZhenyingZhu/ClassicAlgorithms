#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <functional>

using namespace std;

struct Point {
    int x, y;
};

// [Source]: https://leetcode.com/problems/max-points-on-a-line/?tab=Solutions
// http://www.1point3acres.com/bbs/thread-223433-1-1.html

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.empty())
            return 0;
        int size = points.size();

        int maxNum = 1;
        for (int st = 0; st < size - 1; ++st) {
            unordered_map<Slope, int, SlopeHash> slopeCnt;
            int sameStPoints = 1;

            Point &stPt = points[st];
            for (int cur = st + 1; cur < size; ++cur) {
                Point &curPt = points[cur];
                if (curPt.x == stPt.x && curPt.y == stPt.y) {
                    ++sameStPoints;
                } else {
                    Slope s = getSlope(stPt, curPt);
                    cout << s.xDiff << "," << s.yDiff << endl;
                    slopeCnt[getSlope(stPt, curPt)]++;
                }
            }

            int maxNumRun = 0;
            for (auto it = slopeCnt.begin(); it != slopeCnt.end(); ++it)
                maxNumRun = max(maxNumRun, it->second);
            maxNum = max(maxNumRun + sameStPoints, maxNum);
        }

        return maxNum;
    }

private:
    struct Slope {
        int xDiff, yDiff;
        bool operator==(const Slope &other) const {
            return (xDiff == other.xDiff && yDiff == other.yDiff);
        }
    };

    struct SlopeHash {
        size_t operator()(const Slope &slope) const {
            return hash<int>()(slope.xDiff * 1337 + slope.yDiff);
        }
    };

    Slope getSlope(Point &p1, Point &p2) {
        if (p1.x == p2.x)
            return {0, 1};
        if (p1.y == p2.y)
            return {1, 0};

        int xDiff = p2.x - p1.x, yDiff = p2.y - p1.y;
        if (xDiff < 0) {
            xDiff = -xDiff;
            yDiff = -yDiff;
        }

        int gdc = getGDC(abs(xDiff), abs(yDiff));
        return {xDiff / gdc, yDiff / gdc};
    }

    int getGDC(int a, int b) {
        if (a > b)
            swap(a, b);
        if (a == 0)
            return b;

        return getGDC(b % a, a);
    }
};

int main() {
    Solution sol;

    vector<Point> points = {
        //{0,0},{1,1},{2,2},{0,1},{1,0},{0,0}
        //{0,0},{94911151,94911150},{94911152,94911151}
        {0,0},{-1,-1},{2,2}
    };

    cout << sol.maxPoints(points) << endl;

    return 0;
}
