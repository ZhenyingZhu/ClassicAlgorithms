#ifndef SRC_EPI_CHAPTER14_STABLESORTLIST_HPP_
#define SRC_EPI_CHAPTER14_STABLESORTLIST_HPP_

#include "../../Solution.h"
#include "../../ListNode.h"
#include <memory>

namespace epi {
  namespace chapter14 {
    class StableSortList : myutils::Solution {
    public:
        StableSortList():
            Solution("EPI Chapter 14.9",
                     "Implement a fast sorting stable algorithm for lists",
                     "Merge sort: seperate the list into two halves, and then merge.") { }

        ~StableSortList() { }

        std::shared_ptr<myutils::ListNode<int>> stableSortList(std::shared_ptr<myutils::ListNode<int>> list);

        bool test();

    private:
        std::shared_ptr<myutils::ListNode<int>> stableMerge
                (std::shared_ptr<myutils::ListNode<int>> list1, std::shared_ptr<myutils::ListNode<int>> list2);

    };

  } // chapter14
} // epi

#endif /* SRC_EPI_CHAPTER14_STABLESORTLIST_HPP_ */
