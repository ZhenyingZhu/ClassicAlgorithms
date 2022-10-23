#ifndef SRC_EPI_CHAPTER8_ISLINKEDLISTAPALINDROME_HPP_
#define SRC_EPI_CHAPTER8_ISLINKEDLISTAPALINDROME_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../ListNode.h"

#include <memory>

namespace epi {
  namespace chapter8 {

    class IsLinkedListAPalindrome : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        IsLinkedListAPalindrome():
            Solution("EPI Chapter 8.11",
                     "Test whether a singly linked list is palindromic",
                     "Use iterative call.") { }

        ~IsLinkedListAPalindrome() { }

        bool isLinkedListAPalindrome(const std::shared_ptr<myutils::ListNode<int>> &list);

        bool test();

    private:
        std::shared_ptr<myutils::ListNode<int>> reverse(const std::shared_ptr<myutils::ListNode<int>> &list);
    };

  } // chapter8
} // epi

#endif /* SRC_EPI_CHAPTER8_ISLINKEDLISTAPALINDROME_HPP_ */
