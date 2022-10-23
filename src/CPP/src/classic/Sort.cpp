#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myGreater(const int &a, const int &b) {
    return a > b;
}

void quickSort(vector<int> &nums, int st, int ed) {
    if (ed <= st)
        return;

    int md = (st + ed) / 2;
    swap(nums[ed], nums[md]);
    int idx = st - 1;
    for (int i = st; i < ed; ++i) {
        if (nums[i] > nums[ed])
            swap(nums[++idx], nums[i]);
    }
    swap(nums[ed], nums[++idx]);
    quickSort(nums, st, idx - 1);
    quickSort(nums, idx + 1, ed);
}

void mergeSort(vector<int> &nums, int st, int ed) {
    if (st == ed)
        return;

    int md = (st + ed) / 2;
    mergeSort(nums, st, md);
    mergeSort(nums, md + 1, ed);

    vector<int> firstPart(nums.begin() + st, nums.begin() + md + 1);
    int idx = st; // in the origin vector
    int pt1 = 0, pt2 = md + 1; // notice first part is store outside
    while (pt1 <= md - st && pt2 <= ed) {
        if (firstPart[pt1] > nums[pt2])
            nums[idx++] = firstPart[pt1++];
        else
            nums[idx++] = nums[pt2++];
    }
    while (pt1 <= md - st)
        nums[idx++] = firstPart[pt1++];
}

int main() {
    vector<int> nums = {3, 5, 4, 1, 7, 6, 8, 9, 0, 2};

    // when provide a greater, sort sorts elements in desc order
    // sort accept a function class such as greater<int>()
    //sort(nums.begin(), nums.end(), myGreater);
    // lambda
    //sort(nums.begin(), nums.end(), [](const int &a, const int &b) {return a > b;});

    //quickSort(nums, 0, nums.size() - 1);
    mergeSort(nums, 0, nums.size() - 1);

    for (int &num : nums)
        cout << num << " ";
    cout << endl;
}
