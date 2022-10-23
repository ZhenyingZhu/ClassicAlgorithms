/*
 * [Source] https://leetcode.com/problems/read-n-characters-given-read4/
 * [Difficulty]: Easy
 * [Tag]: String
 */

#include <iostream>

using namespace std;

char stream[] = "abcdef";
char *pos = stream;

int read4(char *buf) {
    int cnt = 0;
    for (; cnt < 4; ++cnt) {
        if (*pos == '\0')
            break; // Mock an EOF

        buf[cnt] = *pos;
        ++pos;
    }
    return cnt;
}

// [Solution]: The question is asking how many times we should call the read4 func to load chars into a buff. The return value is to split the buff with the right length.
// [Corner Case]:
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int readCnt = 0;
        while (readCnt < n) {
            int chars = min(read4(buf), n - readCnt);
            readCnt += chars;
            buf += chars;
            if (chars < 4)
                break;
        }
        return readCnt;
    }
};

int main() {
    Solution sol;

    char buf1[10];
    int len = sol.read(buf1, 5);
    cout << string(buf1, buf1 + len) << endl;

    return 0;
}
