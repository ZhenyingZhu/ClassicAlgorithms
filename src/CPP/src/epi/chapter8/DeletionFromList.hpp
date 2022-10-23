#ifndef SRC_EPI_CHAPTER8_DELETIONFROMLIST_HPP_
#define SRC_EPI_CHAPTER8_DELETIONFROMLIST_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../ListNode.h"

#include <memory>

namespace epi {
  namespace chapter8 {

    class DeletionFromList : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        DeletionFromList():
            Solution("EPI Chapter 8.6",
                     "Delete a node from a singly linked list",
                     "Copy data from next node and delete next node.") { }

        ~DeletionFromList() { }

        void deletionFromList(std::shared_ptr<myutils::ListNode<int>> &node);

        bool test();
    };

  } // chapter8
} // epi

#endif /* SRC_EPI_CHAPTER8_DELETIONFROMLIST_HPP_ */
