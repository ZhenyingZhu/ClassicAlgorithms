/*
 * [Source] https://leetcode.com/problems/reverse-bits/
 * [Difficulty]: Easy
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <bitset>

using namespace std;

// [Solution]: Shift left the input, shift right the result
// [Corner Case]: 
class SolutionShift {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 31; ++i) { // can only shift 31 times
bitset<32> r(res);
bitset<32> x(n);
cout << x << " " << r << endl;
            res |= n & 1;
            n = n >> 1;
            res = res << 1;
        }
        res |= n & 1; // The last digit should done here to avoid res << 1
        return res;
    }
};

// [Solution]: swap two bits: first check if they are diff use xor, then use a mask with two 1s and xor with the original number
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
bitset<32> bn(n);
cout << bn << endl;
        for (int i = 0; i < 16; ++i)
            swapBit(n, i, 31 - i);
bitset<32> br(n);
cout << br << endl;
        return n;
    }

private:
    void swapBit(uint32_t& num, size_t i, size_t j) {
        uint32_t bi = num >> i & 1, bj = num >> j & 1;
        if ((bi ^ bj) != 0)
            num ^= (1 << i) | (1 << j);
    }
};

int main() {
    Solution sol;

    cout << sol.reverseBits(43261596u) << endl;
    cout << sol.reverseBits(2147483648u) << endl;

    return 0;
}
