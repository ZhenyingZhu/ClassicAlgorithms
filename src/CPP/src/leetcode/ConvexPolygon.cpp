/*
 * [Source] https://leetcode.com/problems/convex-polygon/
 * [Difficulty]: Medium
 * [Tag]: Math
 */

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// [Solution]: Use the clockwise to indicate if all three points pair are same direction
// [Corner Case]: when 0 or 180.
class Solution {
public:
    struct Slope {
        double slope;
        int area; // 1234
    };

    bool isConvex(vector<vector<int>>& points) {
        int size = points.size();

        vector<int> &point0 = points[0], &point1 = points[1], &point2 = points[2];
        Slope s1 = computeSlope(point0, point1), s2 = computeSlope(point1, point2);
        int relation = checkSlope(s1, s2);
        int clockwise = relation;

        Slope preSlope = s2;
        for (int i = 3; i < size + 2; ++i) {
            vector<int> &pointSt = points[(i - 1) % size], &pointCur = points[i % size];
            Slope curSlope = computeSlope(pointSt, pointCur);
            int relation = checkSlope(preSlope, curSlope); // when 0, continue, when 180, fail
cout << i << " " << relation << endl;
            if (clockwise == 0 && relation != 0 && relation != 4)
                clockwise = relation;
            if (relation == 4 || (relation != 0 && relation != clockwise)) {
                return false;
            }
            preSlope = curSlope;
        }

        return true;
    }

    Slope computeSlope(vector<int> &point1, vector<int> &point2) {
        double slope;
        int area;

        int yAxis = point2[1] - point1[1], xAxis = point2[0] - point1[0];
        if (xAxis == 0)
            slope = numeric_limits<double>::max();
        else
            slope = (double)yAxis / (double)xAxis;

        if (yAxis > 0 && xAxis >= 0)
            area = 1;
        else if (yAxis <= 0 && xAxis > 0)
            area = 2;
        else if (yAxis < 0 && xAxis <= 0)
            area = 3;
        else
            area = 4;
        return {slope, area};
    }

    int checkSlope(Slope &s1, Slope &s2) {
        if (s1.slope == s2.slope) {
            if (s1.area == s2.area)
                return 0; // 0
            else
                return 4; // 180
        }

        if (s1.area == s2.area) {
            if (s1.slope > s2.slope)
                return 1; // clockwise
            else
                return 2; // counter clockwise when slope same
        } else {
            int diff = (s2.area + 4 - s1.area) % 4;
            if (diff == 1)
                return 1;
            if (diff == 3)
                return 2;

            if (s1.slope > s2.slope) // over 180 defined as counter clockwise
                return 2;
            else
                return 1;
        }
    }
};

// [Solution]: Use (p1[0]-p0[0])(p2[1]-p0[1])-(p2[0]-p0[0])(p1[1]-p0[1]) to decide if clockwise or anti-clockwise

int main() {
    Solution sol;
    //vector<vector<int>> points = {{0,0},{1,2},{2,0}};
    //vector<vector<int>> points = {{0,0},{0,1},{1,1},{1,0}};
    //vector<vector<int>> points = {{0,0},{0,10},{10,10},{10,0},{5,5}};
    //vector<vector<int>> points = {{0,0},{1,0},{1,1},{-1,1},{-1,0}};
    vector<vector<int>> points = {{-2,2},{-1,2},{0,2},{1,2},{2,2}, {2,1},{2,0},{2,-1},{2,-2},{1,-2},{0,-2},{-1,-2}};
    cout << sol.isConvex(points) << endl;

    return 0;
}
