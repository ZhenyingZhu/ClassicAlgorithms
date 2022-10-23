#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/utf-8-validation/
// http://www.1point3acres.com/bbs/thread-225639-1-1.html

class Solution {
public:
    bool validUtf8(vector<int> &data) {
        int cnt = 0;
        for (int i = 0; i < (int)data.size(); ++i) {
            int &num = data[i];
            if (cnt == 0) {
                if (num >> 7 == 0b0) {
                    cnt = 0;
                } else if (num >> 5 == 0b110) {
                    cnt = 1;
                } else if (num >> 4 == 0b1110) {
                    cnt = 2;
                } else if (num >> 3 == 0b11110) {
                    cnt = 3;
                } else {
                    return false;
                }
            } else {
                if (num >> 6 == 0b10) {
                    --cnt;
                } else {
                    return false;
                }
            }
        }
        return cnt == 0;
    }
};

int main() {
    Solution sol;

    //vector<int> data = {197, 130, 1};
    vector<int> data = {235, 140, 4};
    cout << sol.validUtf8(data) << endl;

    return 0;
}
