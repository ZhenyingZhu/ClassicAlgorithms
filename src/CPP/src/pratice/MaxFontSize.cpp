#include <iostream>
#include <unordered_map>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-226722-1-1.html

const int MIN = 1;
const int MAX = 10;

class API {
public:
    API() {
        for (int i = MIN; i <= MAX; ++i) {
            font2Size[i] = i;
        }
    }

    int getHeight(int fontSize) {
        return font2Size[fontSize];
    }

    int getWidth(char c, int fontSize) {
        return font2Size[fontSize];
    }

private:
    unordered_map<int, int> font2Size;
};

class Solution {
public:
    int maxFontSize(string s, int h, int w) {
        API api;

        int left = MIN, right = MAX;
        while (left + 1 < right) {
            int md = left + (right - left) / 2;
            if (canFit(s, md, h, w, api))
                left = md;
            else
                right = md;
        }

        if (canFit(s, right, h, w, api))
            return right;
        if (canFit(s, left, h, w, api))
            return left;
        return -1;
    }

    bool canFit(string &s, int fontSize, int h, int w, API &api) {
        int lines = 1, width = 0;
        int pt = 0;
        while (pt < (int)s.length()) {
            int charWidth = api.getWidth(s[pt++], fontSize);
            width += charWidth;
            if (width > w) {
                ++lines;
                width = charWidth;
            }
        }
        return lines * api.getHeight(fontSize) <= h;
    }
};

int main() {
    Solution sol;

    string s(11, 'a');
    cout << s << endl;
    cout << sol.maxFontSize(s, 6 * 2, 6 * 5) << endl;

    return 0;
}
