#include "MergeTwoSortedArrays.hpp"

#include <vector>
#include <iterator>
#include <iostream>
#include <stdexcept>

#include "../../MyUtils.h"

using std::vector;
using std::prev;
using std::cout;
using std::endl;
using myutils::vec_to_string;

namespace epi {
  namespace chapter14 {
    void MergeTwoSortedArrays::mergeTwoSortedArrays(int arr1[], int m, int arr2[], int n) {
        int *pe = arr1 + m + n - 1;
        int *p1 = arr1 + m - 1, *p2 = arr2 + n - 1;

        while (p1 >= arr1 && p2 >= arr2) {
            if (*p1 > *p2)
                *pe-- = *p1--;
            else
                *pe-- = *p2--;
        }

        while (p2 >= arr2)
            *pe-- = *p2--;
    }

    bool MergeTwoSortedArrays::test() {
        int array1[] = {5, 13, 17, 0, 0, 0, 0, 0};
        int array2[] = {3, 7, 11, 19};

        mergeTwoSortedArrays(array1, 3, array2, 4);

        vector<int> ans = {3, 5, 7, 11, 13, 17, 19};
        for (int i = 0; i != 7; ++i) {
            int res = *(array1 + i);
            if (res != ans[i]) {
                cout << "Should be " << ans[i] << endl;
                cout << "Result " << res << endl;
                return false;
            }
        }

        return true;
    }

  } // chapter14
} // epi
