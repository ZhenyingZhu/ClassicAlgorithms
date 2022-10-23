#ifndef SRC_EPI_CHAPTER6_APPLYPERMUTATION_HPP_
#define SRC_EPI_CHAPTER6_APPLYPERMUTATION_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter6 {

    class ApplyPermutation : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        ApplyPermutation():
            Solution("EPI Chapter 6.9",
                     "Permute the elements of an array",
                     "Use while loop to permute. Then continue to the next unpermuted element") { }

        bool test();

        ~ApplyPermutation() { }

        void applyPermutationMutatePerm(std::vector<int> &perm, std::vector<int> &vec);

        void applyPermutation(const std::vector<int> &perm, std::vector<int> &vec);

    private:
        void swap(int&, int&);
    };

  } // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_APPLYPERMUTATION_HPP_ */
