#include "DutchFlagPartition.hpp"

#include <vector>
#include <iostream>
#include <stdint.h>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;
using myutils::vec_to_string;

namespace epi {
namespace chapter6 {

void DutchFlagPartition::swap(Color *a, Color *b) {
    Color tmp = *a;
    *a = *b;
    *b = tmp;
}

void DutchFlagPartition::bruteForceTwoThrough(int pivotIndex, vector<Color> &arr) {
    Color pivot = arr[pivotIndex];
    for (vector<Color>::size_type i = 0; i != arr.size(); ++i) {
        for (vector<Color>::size_type j = i + 1; j != arr.size(); ++j) {
            if (arr[j] < pivot) {
                swap(&arr[i], &arr[j]);
                break;
            }
        }
    }
    for (vector<Color>::size_type i = arr.size() - 1; i != UINT32_MAX && arr[i] >= pivot; --i) {
        for (vector<Color>::size_type j = i - 1; j != UINT32_MAX && arr[j] >= pivot; --j) {
            if (arr[j] > pivot) {
                swap(&arr[i], &arr[j]);
                break;
            }
        }
    }
}

void DutchFlagPartition::dutchFlagTwoThrough(int pivotIndex, vector<Color> &arr) {
    Color pivot = arr[pivotIndex];
    int smaller = 0;
    for (vector<Color>::size_type i = 0; i != arr.size(); ++i) {
        if (arr[i] < pivot)
            swap(&arr[i], &arr[smaller++]);
    }

    int larger = arr.size() - 1;
    for (int i = arr.size() - 1; i >= 0 && arr[i] >= pivot; --i) {
        if (arr[i] > pivot)
            swap(&arr[i], &arr[larger--]);
    }
}

void DutchFlagPartition::dutchFlagPartition(int pivotIndex, vector<Color> &arr) {
    int pivot = arr[pivotIndex];

    int smaller = 0, equal = 0, larger = arr.size() - 1;
    while (equal <= larger) {
        if (arr[equal] < pivot)
            swap(&arr[equal++], &arr[smaller++]);
        else if (arr[equal] == pivot)
            ++equal;
        else
            swap(&arr[equal], &arr[larger--]);
    }
}

bool DutchFlagPartition::test() {
    vector<Color> arr;
    arr.push_back(WHITE);
    arr.push_back(WHITE);
    arr.push_back(BLUE);
    arr.push_back(BLUE);
    arr.push_back(RED);
    arr.push_back(RED);

    vector<Color> shouldBe(arr), res(arr);
    bruteForceTwoThrough(1, shouldBe);
    dutchFlagPartition(1, res);

    if (shouldBe != res) {
        cout << "Original: " << vec_to_string(arr) << endl;
        cout << "Should be: " << vec_to_string(shouldBe) << endl;
        cout << "Result: " << vec_to_string(res) << endl;
        return false;
    }

    return true;
}

} // chapter6
} // epi

