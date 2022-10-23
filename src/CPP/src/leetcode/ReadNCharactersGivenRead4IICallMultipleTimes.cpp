/*
 * [Source] https://leetcode.com/problems/
 * [Difficulty]: 
 * [Tag]: 
 */

#include <iostream>
#include <vector>

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

// [Solution]: Keep state between reads. Buff records the read4() result, and not cleared after read() finish. readPos records last read position to the input buf. writePos records the last pos of buff.
// [Corner Case]:
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        for (int i = 0; i < n; ++i) {
            if (readPos == writePos) {
                writePos = read4(buff);
cout << "buff " << string(buff, buff+writePos) << endl;
                readPos = 0;
                if (writePos == 0)
                    return i;
            }
            buf[i] = buff[readPos++];
cout << "buf " << string(buf, buf+i) << endl;
        }
        return n;
    }

private:
    int readPos = 0, writePos = 0;
    char buff[4];
};

int main() {
    Solution sol;

    char buf1[10];
    int len1 = sol.read(buf1, 3);
    cout << string(buf1, buf1 + len1) << endl;

    char buf2[10];
    int len2 = sol.read(buf2, 5);
    cout << string(buf2, buf2 + len2) << endl;

    return 0;
}
