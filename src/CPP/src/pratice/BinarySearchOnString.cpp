#include <iostream>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-226373-1-1.html

class Solution {
public:
    int binarySearch(string s, int target) {
        int left = 0, right = s.length();
        while (left < right) {
            // if mid is a space, find left
            int mid = left + (right - left) / 2;
            int st = findLeftSpace(s, mid);
            int ed = findRightSpace(s, mid);
            int num = stoi(s.substr(st, ed - st + 1));
            if (num == target)
                return st;
            if (num < target)
                left = ed + 1;
            else
                right = st - 1;
        }
        return -1;
    }

    int findLeftSpace(string &s, int mid) {
        for (int i = mid - 1; i >= 0; --i) {
            if (s[i] == ' ')
                return i + 1;
        }
        return 0;
    }

    int findRightSpace(string &s, int mid) {
        for (int i = mid; i < (int)s.length(); ++i) {
            if (s[i] == ' ')
                return i - 1;
        }
        return s.length() - 1;
    }
};

int main() {
    Solution sol;

    string s = "1 3 6 8 99 123 1234157";
    vector<int> nums = {1,3,6,8,99,123,1234157};
    for (int num : nums) {
        int st = sol.binarySearch(s, num);
        cout << st << " " << s.substr(st, sol.findRightSpace(s, st) - st + 1) << endl;
    }

    return 0;
}
