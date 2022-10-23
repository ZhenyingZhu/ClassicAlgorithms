/*
 * [Source] https://leetcode.com/problems/perfect-rectangle/
 * [Difficulty]: Hard
 * [Tag]: 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <functional>

using namespace std;

// [Solution]: Use 1, 2, 4, 8 to indicate the type fo a corner. It could be LD, or RU, or both. So if no overlapping corners present, and there are in total 4 corners that are verticals, and total areas are same to the cover rectangle, it is true
// [Corner Case]:
class Solution {
public:
    struct Corner {
        bool operator==(const Corner &other) const {
            return other.x == x && other.y == y;
        }

        int x, y;
    };

    struct CornerHash {
        size_t operator()(const Corner &corner) const {
            return hash<string>()( to_string(corner.x) + "," + to_string(corner.y) );
        }
    };

    const int LD = 1, LU = 2, RU = 4, RD = 8;

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // the result rectangle corners
        Corner coverRecLeftDown{INT_MAX, INT_MAX}, coverRecRightUp{INT_MIN, INT_MIN};

        int totalArea = 0;
        unordered_map<Corner, int, CornerHash> cornerType;
        for (vector<int> &rectangle : rectangles) {
            Corner leftDown{rectangle[0], rectangle[1]}, leftUp{rectangle[0], rectangle[3]},
                   rightUp{rectangle[2], rectangle[3]}, rightDown{rectangle[2], rectangle[1]};

            if (! ( updateType(leftDown, cornerType, LD) &&
                    updateType(leftUp, cornerType, LU) &&
                    updateType(rightUp, cornerType, RU) &&
                    updateType(rightDown, cornerType, RD) )
               ) {
                return false;
            }

            totalArea += computeArea(leftDown, rightUp);
            coverRecLeftDown.x = min(leftDown.x, coverRecLeftDown.x);
            coverRecLeftDown.y = min(leftDown.y, coverRecLeftDown.y);
            coverRecRightUp.x = max(rightUp.x, coverRecRightUp.x);
            coverRecRightUp.y = max(rightUp.y, coverRecRightUp.y);
        }

        int coverRecVerticalCnt = 0;
        for (auto it = cornerType.begin(); it != cornerType.end(); ++it) {
            int type = it->second;
            if (type == LD || type == LU || type == RU || type == RD)
                ++coverRecVerticalCnt;
        }

        return coverRecVerticalCnt == 4 && computeArea(coverRecLeftDown, coverRecRightUp) == totalArea;
    }

    bool updateType(Corner &corner, unordered_map<Corner, int, CornerHash> &cornerType, int type) {
        // each corner map to a type which is a combination of LD, LU, RU, RD.
        // a corner that previous is a LD cannot be LD again.
        int &previousType = cornerType[corner];
        if ( (type & previousType) > 0 ) {
            return false;
        }
        // update type
        previousType |= type;

        return true;
    }

    int computeArea(Corner &leftDown, Corner &rightUp) {
        int width = rightUp.x - leftDown.x;
        int height = rightUp.y - leftDown.y;
        return width * height;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    /*
    */
    vector<vector<int>> rectangles = {
        {1,1,3,3},
        {3,1,4,2},
        {3,2,4,4},
        {1,3,2,4},
        {2,3,3,4}
    };

    /*
    vector<vector<int>> rectangles = {
      {1,1,2,3},
      {1,3,2,4},
      {3,1,4,2},
      {3,2,4,4}
    };

    vector<vector<int>> rectangles = {
      {1,1,3,3},
      {3,1,4,2},
      {1,3,2,4},
      {3,2,4,4}
    };

    vector<vector<int>> rectangles = {
      {1,1,3,3},
      {3,1,4,2},
      {1,3,2,4},
      {2,2,4,4}
    };
    */

    cout << sol.isRectangleCover(rectangles) << endl;

    return 0;
}
