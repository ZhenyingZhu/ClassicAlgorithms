#ifndef SRC_EPI_CHAPTER9_SETJUMPORDER_HPP_
#define SRC_EPI_CHAPTER9_SETJUMPORDER_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <stack>
#include <memory>

namespace epi {
  namespace chapter9 {

    class SetJumpOrder : public myutils::Solution {
        friend class myutils::SmartPtr;

    private:
        struct PostingListNode;
    public:
        SetJumpOrder():
            Solution("EPI Chapter 9.5",
                     "Search a postings list",
                     "Traverse the list. Check jump node first. If jump "
                     "to explored node, fall back to check next node.") { }

        ~SetJumpOrder() { }

        void setJumpOrderRecursive(const std::shared_ptr<PostingListNode> &list);

        void setJumpOrder(const std::shared_ptr<PostingListNode> &list);

        bool test();

    private:
        void setJumpOrderHelper(std::shared_ptr<PostingListNode> &node, int &order);
    };

  } // chapter9
} // epi

#endif /* SRC_EPI_CHAPTER9_SETJUMPORDER_HPP_ */
