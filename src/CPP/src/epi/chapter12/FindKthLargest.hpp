#ifndef SRC_EPI_CHAPTER12_FINDKTHLARGEST_HPP_
#define SRC_EPI_CHAPTER12_FINDKTHLARGEST_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>
#include <cassert>
#include <utility>
#include <random>
#include <iostream>

namespace epi {
  namespace chapter12 {
    class FindKthLargest : myutils::Solution {
    public:
        FindKthLargest():
            Solution("EPI Chapter 12.8",
                     "Find the kth largest element",
                     "Randomly pick a number, seperate the array "
                     "into larger or smaller than it sub arrays. "
                     "See if it is the kth element. If it is larger"
                     " than kth element, search the smaller sub array.") { }

        ~FindKthLargest() { }

        int findKthLargest(std::vector<int> &vec, int k);

        template <typename Compare>
        int partitionAroundPivot(int st, int ed, int pivotIdx, std::vector<int> &vec, Compare comp) {
            assert(st <= pivotIdx && pivotIdx <= ed && st >= 0 && ed <= (int)vec.size());

            int pivot = vec[pivotIdx];
            std::swap( vec[pivotIdx], vec[ed] );

            int newPivotIdx = st;
            for (int i = st; i != ed; ++i) {
                if ( comp(vec[i], pivot) ) {
                    std::swap( vec[i], vec[newPivotIdx++] );
                }
            }

            std::swap(vec[newPivotIdx], vec[ed]);
            return newPivotIdx;
        }

        template <typename Compare>
        int findKthHelper(int st, int ed, std::vector<int> &vec, int k, Compare comp) {
            assert(st <= ed && st >= 0 && ed < (int)vec.size());
            assert(k >= 1 && k <= (int)vec.size());

            std::default_random_engine gen( (std::random_device())() );
            while (st <= ed) {
                int pivotIdx = std::uniform_int_distribution<int>{st, ed}(gen);
                int newPivotIdx = partitionAroundPivot(st, ed, pivotIdx, vec, comp);

                if (newPivotIdx == k - 1)
                    return vec[newPivotIdx];
                else if (newPivotIdx > k - 1)
                    ed = newPivotIdx - 1;
                else
                    st = newPivotIdx + 1;
            }

            assert(true); // shouldn't reach here.
            return st;
        }

        bool test();

    };

  } // chapter12
} // epi

#endif /* SRC_EPI_CHAPTER12_FINDKTHLARGEST_HPP_ */
