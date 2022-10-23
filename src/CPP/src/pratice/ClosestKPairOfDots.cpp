#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-228718-1-1.html

// Better solution: http://www.geeksforgeeks.org/closest-pair-of-points/

struct Point {
    int x, y;
};

class Solution {
public:
    vector<pair<Point, Point>> closestKPairs(vector<Point> &points, int k) {
        priority_queue<PointPair, vector<PointPair>, Smaller> pq;
        for (int i = 0; i < (int)points.size() - 1; ++i) {
            for (int j = i + 1; j < (int)points.size(); ++j) {
                pq.push( PointPair(points[i], points[j]) );
                if ((int)pq.size() > k) {
                    pq.pop();
                }
            }
        }

        vector<pair<Point, Point>> res;
        while(!pq.empty()) {
            PointPair pointPair = pq.top();
            pq.pop();
            res.push_back( {pointPair.point1, pointPair.point2} );
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    struct PointPair {
        PointPair(Point &p1, Point &p2):
            point1(p1), point2(p2) {
            distance = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
        }

        Point point1, point2;
        int distance;
    };

    struct Smaller {
        bool operator()(const PointPair &pair1, const PointPair &pair2) {
            return pair1.distance < pair2.distance;
        }
    };
};

int main() {
    Solution sol;

    vector<Point> points = { {0,0}, {0,1}, {1,0}, {1,1}, {2,2} };
    for (auto pointPair : sol.closestKPairs(points, 20)) {
        cout << "(" << pointPair.first.x << "," << pointPair.first.y << ") " << "(" << pointPair.second.x << "," << pointPair.second.y << ") " << endl;
    }

    return 0;
}
