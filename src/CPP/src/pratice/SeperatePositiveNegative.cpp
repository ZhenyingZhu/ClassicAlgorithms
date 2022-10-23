#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://en.wikipedia.org/wiki/Insertion_sort
// http://www.1point3acres.com/bbs/thread-223926-1-1.html

class Solution {
public:
    void partition(vector<int> &vec) {
        int len = vec.size();
        for (int i = 0; i < len; i++) {
            if (vec[i] >= 0)
                continue;

            int j = i;
            while (j < len && vec[j] < 0)
                ++j;

            if (j == len)
                return;

            int val = vec[j];
            for (int k = j; k > i; --k)
                vec[k] = vec[k - 1];
            vec[i] = val;
        }
    }
};

int main() {
    Solution sol;

    //vector<int> nums = {0, 1, -1, -2, 2, 3, -3, 4, -4};
    //vector<int> nums = {-1,-2,-3};
    vector<int> nums = {1,2,3};
    sol.partition(nums);
    for (int &num : nums)
        cout << num << ", ";
    cout << endl;

    return 0;
}
