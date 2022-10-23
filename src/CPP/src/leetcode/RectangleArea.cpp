/*
 * [Source] https://leetcode.com/problems/rectangle-area/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap = 0;
        if (C <= A || C <= E || G <= E || G <= A || D <= B || D <= F || H <= F || H <= B) {
            overlap = 0;
        } else {
            int w = min( min(C - A, C - E), min(G - E, G - A) );
            int h = min( min(D - B, D - F), min(H - F, H - B) );
            overlap =  w * h;
        }

        int totalArea = (C - A) * (D - B) + (G - E) * ( H - F);
        return totalArea - overlap;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
