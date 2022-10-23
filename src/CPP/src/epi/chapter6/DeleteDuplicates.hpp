#ifndef SRC_EPI_CHAPTER6_DELETEDUPLICATES_HPP_
#define SRC_EPI_CHAPTER6_DELETEDUPLICATES_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
namespace chapter6 {

class DeleteDuplicates : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    DeleteDuplicates():
            Solution("EPI Chapter 6.5",
                     "Delete duplicates from a sorted array",
                     "Two pointers.") { }

    bool test();

    ~DeleteDuplicates() { }

    int deleteDuplicates(std::vector<int> *);
};

} // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_DELETEDUPLICATES_HPP_ */
