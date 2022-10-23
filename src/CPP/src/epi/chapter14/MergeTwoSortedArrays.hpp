#ifndef SRC_EPI_CHAPTER14_MERGETWOSORTEDARRAYS_HPP_
#define SRC_EPI_CHAPTER14_MERGETWOSORTEDARRAYS_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter14 {
    class MergeTwoSortedArrays : public myutils::Solution {
    public:
        MergeTwoSortedArrays():
            Solution("EPI Chapter 14.2",
                     "Merge two sorted arrays",
                     "Compare two pointers from the end of "
                     "arrays. Use a pointer to indicate "
                     "where to insert.") { }

        ~MergeTwoSortedArrays() { }

        void mergeTwoSortedArrays(int arr1[], int m, int arr2[], int n);

        bool test();

    };

  } // chapter14
} // epi

#endif /* SRC_EPI_CHAPTER14_MERGETWOSORTEDARRAYS_HPP_ */
