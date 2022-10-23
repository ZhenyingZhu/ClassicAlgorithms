/*
 * [Source] https://leetcode.com/problems/utf-8-validation/
 * [Difficulty]: Medium
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Use masks to first isolate unrelated digits, then check the right one.
// [Corner Case]:
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if (data.empty())
            return true;

        int idx = 0;
        while (idx < (int)data.size()) {
            int bytes = getBytes(data[idx]);
            // validate bytes count is right
            if (bytes == -1)
                return false;

            // validate total length
            if (idx + bytes > (int)data.size())
                return false;

            // validate following number
            for (int i = 1; i < bytes; ++i) {
                if ( !isValidFollowing(data[idx + i]) )
                    return false;
            }

            idx += bytes;
        }

        return idx == (int)data.size();
    }

    int getBytes(int number) {
        if ((number & byte1Mask) == 0)
            return 1;
        if ((number & byte2Mask) == 0xC0) // 110xxxxx
            return 2;
        if ((number & byte3Mask) == 0xE0) // 1110xxxx
            return 3;
        if ((number & byte4Mask) == 0xF0) // 11110xxx
            return 4;
        return -1;
    }

    bool isValidFollowing(int number) {
        return (number & 0xC0) == 0x80; // 10xxxxxx
    }

    static const int byte1Mask = 0x80, byte2Mask = 0xE0, byte3Mask = 0xF0, byte4Mask = 0xF8;
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<int> data = {197, 130, 1};
    //vector<int> data = {235, 140, 4};
    vector<int> data = {255};
    cout << sol.validUtf8(data) << endl;

    return 0;
}
