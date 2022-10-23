/*
 * [Source] https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/
 * [Difficulty]: Hard
 * [Tag]: Binary Search
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Use binary search to find the furthest pixels
// [Corner Case]:
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int upX = binarySearchXUp(image, x), downX = binarySearchXDown(image, x);
        int leftY = binarySearchYLeft(image, y), rightY = binarySearchYRight(image, y);
cout << upX << " " << downX << " " << leftY << " " << rightY << endl;
        return (downX -upX - 1) * (rightY - leftY - 1);
    }

    int binarySearchXUp(vector<vector<char>> &image, int x) {
        int st = 0, ed = x;
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if (foundHorizental(image, md))
                ed = md;
            else
                st = md;
        }
        if (!foundHorizental(image, ed))
            return ed;
        if (!foundHorizental(image, st))
            return st;
        return st - 1;
    }

    int binarySearchXDown(vector<vector<char>> &image, int x) {
        int st = x, ed = image.size() - 1;
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if (foundHorizental(image, md))
                st = md;
            else
                ed = md;
        }
        if (!foundHorizental(image, st))
            return st;
        if (!foundHorizental(image, ed))
            return ed;
        return ed + 1;
    }

    bool foundHorizental(vector<vector<char>> &image, int x) {
        for (char &c : image[x]) {
            if (c == '1') {
                return true;
           }
        }
        return false;
    }

    int binarySearchYLeft(vector<vector<char>> &image, int y) {
        int st = 0, ed = y;
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if (foundVertical(image, md))
                ed = md;
            else
                st = md;
        }
        if (!foundVertical(image, ed))
            return ed;
        if (!foundVertical(image, st))
            return st;
        return st - 1;
    }

    int binarySearchYRight(vector<vector<char>> &image, int y) {
        int st = y, ed = image[0].size() - 1;
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if (foundVertical(image, md))
                st = md;
            else
                ed = md;
        }
        if (!foundVertical(image, st))
            return st;
        if (!foundVertical(image, ed))
            return ed;
        return ed + 1;
    }

    bool foundVertical(vector<vector<char>> &image, int y) {
cout << "Search " << y << endl;
        for (int i = 0; i < (int)image.size(); ++i) {
            if (image[i][y] == '1') {
                return true;
           }
        }
        return false;
    }
};

// [Solution]:

int main() {
    Solution sol;

    //vector<string> strs = {"0010", "0110", "0100"};
    vector<string> strs = {"01"};
    vector<vector<char>> image;
    for (string &str : strs)
        image.push_back(vector<char>(str.begin(), str.end()));

    cout << sol.minArea(image, 0, 1) << endl;

    return 0;
}
