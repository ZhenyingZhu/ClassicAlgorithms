/*
 * [Source] https://leetcode.com/problems/max-points-on-a-line/
 * [Difficulty]: Hard
 * [Tag]: Hash Table
 * [Tag]: Math
 */

#include <iostream>
#include <vector>
#include <cfloat>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <climits>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

// [Solution]: use a starter point and slope to present lines. So a hash table record slope <-> nodes num for each starter points can do the job
// [Corner Case]: if two pointers are at same location, they count as two nodes
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int len = points.size();
        if (len <= 1)
            return len;

        int maxNum = 2;

        unordered_map<double, vector<int>> slopeNumMap;
        for (int i = 0; i < len - 1; ++i) {
            slopeNumMap.clear();
            vector<int> sameNodes = {i};

            for (int j = i + 1; j < len; ++j) {
                if (samePoints(points[i], points[j])) {
                    sameNodes.push_back(j);
                    continue;
                }

                double slope = getSlope(points[i], points[j]);
                unordered_map<double, vector<int>>::iterator it = slopeNumMap.find(slope);
                if (it == slopeNumMap.end()) {
                    slopeNumMap[slope] = {j};
                } else {
                    it->second.push_back(j); // here deal with if all nodes are same nodes
                }
            }

            maxNum = max((int)sameNodes.size(), maxNum);
            for (auto it = slopeNumMap.begin(); it != slopeNumMap.end(); ++it) {
                int size = it->second.size() + sameNodes.size();
// helper start
if (size == 25) {
    for (int idx : sameNodes)
        cout << "(" << points[idx].x << "," << points[idx].y << "),";
    for (int idx : it->second)
        cout << "(" << points[idx].x << "," << points[idx].y << "),";
    cout << endl;
}
// helper end
                maxNum = max(size, maxNum);
            }
        }

        return maxNum;
    }

private:
    bool samePoints(const Point& p1, const Point& p2) {
        return (p1.x == p2.x && p1.y == p2.y);
    }

    double getSlope(const Point& p1, const Point& p2) {
        if (p1.x == p2.x)
            return DBL_MAX;
        return double(p2.y - p1.y) / double(p2.x - p1.x);
    }
};

// Wrong
// [Solution]: This design has a big mistake that where previous same nodes of the start node will not show on later slope checks.
// [Corner Case]: if two pointers are at same location, they count as two nodes
class SolutionWrong {
public:
    int maxPoints(vector<Point>& points) {
        int len = points.size();
        if (len <= 1)
            return len;

        int maxNum = 2;
        for (int i = 0; i < len - 2; ++i) {
if (i != 4)
    continue;
            for (int j = i + 1; j < len - 1; ++j) {
cout << "j" << j << endl;
                vector<int> nodesOnLine = {i};
                int tmp = j;
                while (tmp < len - 1 && samePoints(points[i], points[tmp])) {
cout << tmp << "(" << points[tmp].x << "," << points[tmp].y << ")" << endl;
                    nodesOnLine.push_back(tmp++);
                }

                Slope slope = getSlope(points[i], points[tmp]);
                nodesOnLine.push_back(tmp); // here deal with if all nodes are same nodes

                for (int k = tmp + 1; k < len; ++k) {
                    if (samePoints(points[i], points[k]) || slope == getSlope(points[i], points[k])) {
                        nodesOnLine.push_back(k);
                    }
                }
                maxNum = max((int)nodesOnLine.size(), maxNum);
// helper st
if (nodesOnLine.size() == 24) {
    for (int idx : nodesOnLine)
        cout << idx << "(" << points[idx].x << "," << points[idx].y << "),";
    cout << endl;
}
// helper ed
            }
        }

        return maxNum;
    }

private:
    struct Slope {
        Slope(bool v, double s):
            isVertical(v), slopeRate(s) { }

        bool operator==(const Slope& other) const {
            if (isVertical) {
                if (other.isVertical)
                    return true;
                return false;
            }
            return abs(slopeRate - other.slopeRate) <= 0.01;
        }

        bool isVertical;
        double slopeRate;
    };

    Slope getSlope(const Point& p1, const Point& p2) {
        if (p2.x == p1.x)
            return Slope(true, 0.0);
        double s = double(p2.y - p1.y) / double(p2.x - p1.x);
        return Slope(false, s);
    }

    bool samePoints(const Point& p1, const Point& p2) {
        return (p1.x == p2.x && p1.y == p2.y);
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/MaxPointsOnALine.java
 */

/* Java solution
public class Solution {
    public int maxPoints(Point[] points) {
        if(points.length<=2) return points.length;
        int max=0;
        for(int i=0; i<points.length; i++){
			int maxi=1;
            HashMap<Double, Integer> slopes=new HashMap<Double, Integer>();
            for(int j=0; j<points.length; j++){
                if(i==j) continue;
                if(points[j].x==points[i].x && points[j].y==points[i].y){
                    maxi++;
                    Set<Double> allSlope=slopes.keySet();
                    for(double s:allSlope){
                        int num=slopes.get(s)+1;
                        slopes.put(s, num);
                    }
                }else{
                    double slope=computeSlope(points[j], points[i]);
                    if(slopes.containsKey(slope)){
                        int num=slopes.get(slope)+1;
                        if(num>maxi) maxi=num;
                        slopes.put(slope, num);
                    }else{
                        maxi=2;
                        slopes.put(slope, 2);
                    }
                }
				if(maxi>max) max=maxi;
            }
        }
        return max;
    }
    public double computeSlope(Point a, Point b){
        if(b.x==a.x) return Double.MAX_VALUE;
        double fac=(double)(b.y-a.y);
        double dem=(double)(b.x-a.x);
        return dem/fac;
    }
}
 */

int main() {
    Solution sol;

    //vector<Point> points = { Point(0, 0), Point(1, 1), Point(2, 2) };
    //vector<Point> points = { Point(0, 0), Point(0, 1), Point(0, 2), Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4) };
    //vector<Point> points = { Point(0, 0), Point(1, 1), Point(0, 0) };
    //vector<Point> points = { Point(1, 1), Point(1, 1), Point(2, 2), Point(2, 2) };
    //vector<Point> points = { Point(1, 1), Point(1, 1), Point(1, 1) };
    vector<Point> points = {
        {40,-23},{9,138},{429,115},{50,-17},{-3,80},
        {-10,33},{5,-21},{-3,80},{-6,-65},{-18,26},
        {-6,-65},{5,72},{0,77},{-9,86},{10,-2},
        {-8,85},{21,130},{18,-6},{-18,26},{-1,-15},
        {10,-2},{8,69},{-4,63},{0,3},{-4,40},
        {-7,84},{-8,7},{30,154},{16,-5},{6,90},
        {18,-6},{5,77},{-4,77},{7,-13},{-1,-45},
        {16,-5},{-9,86},{-16,11},{-7,84},{1,76},
        {3,77},{10,67},{1,-37},{-10,-81},{4,-11},
        {-20,13},{-10,77},{6,-17},{-27,2},{-10,-81},
        {10,-1},{-9,1},{-8,43},{2,2},{2,-21},
        {3,82},{8,-1},{10,-1},{-9,1},{-12,42},
        {16,-5},{-5,-61},{20,-7},{9,-35},{10,6},
        {12,106},{5,-21},{-5,82},{6,71},{-15,34},
        {-10,87},{-14,-12},{12,106},{-5,82},{-46,-45},
        {-4,63},{16,-5},{4,1},{-3,-53},{0,-17},
        {9,98},{-18,26},{-9,86},{2,77},{-2,-49},
        {1,76},{-3,-38},{-8,7},{-17,-37},{5,72},
        {10,-37},{-4,-57},{-3,-53},{3,74},{-3,-11},
        {-8,7},{1,88},{-12,42},{1,-37},{2,77},
        {-6,77},{5,72},{-4,-57},{-18,-33},{-12,42},
        {-9,86},{2,77},{-8,77},{-3,77},{9,-42},
        {16,41},{-29,-37},{0,-41},{-21,18},{-27,-34},
        {0,77},{3,74},{-7,-69},{-21,18},{27,146},
        {-20,13},{21,130},{-6,-65},{14,-4},{0,3},
        {9,-5},{6,-29},{-2,73},{-1,-15},{1,76},
        {-4,77},{6,-29}};
    cout << sol.maxPoints(points) << endl;

    return 0;
}
