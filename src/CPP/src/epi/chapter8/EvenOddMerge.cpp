#include "EvenOddMerge.hpp"

#include "../../ListNode.h"
#include "../../MyUtils.h"
#include "HasCycle.hpp"

#include <memory>
#include <iostream>
#include <vector>
#include <stdexcept>

using std::shared_ptr;
using std::cout;
using std::endl;
using std::vector;
using std::to_string;
using myutils::ListNode;
using myutils::createList;
using myutils::is_equal;
using myutils::list_to_string;
using myutils::find_node;
using std::invalid_argument;

namespace epi {
  namespace chapter8 {
    shared_ptr<ListNode<int>> EvenOddMerge::evenOddMerge(const shared_ptr<ListNode<int>> &list) {
        shared_ptr<ListNode<int>> oddDummy(new ListNode<int>()), evenDummy(new ListNode<int>());

        auto cur = list, evenTail = evenDummy, oddTail = oddDummy;
        size_t cnt = 0;
        while (cur) {
            if (cnt % 2 == 0) {
                evenTail->next = cur;
                evenTail = evenTail->next;
            } else {
                oddTail->next = cur;
                oddTail = oddTail->next;
            }
            cur = cur->next;
            ++cnt;
        }

        oddTail->next = nullptr;
        evenTail->next = oddDummy->next;
        return evenDummy->next;
    }

    bool EvenOddMerge::test() {
        vector<int> vec1 = {0, 1, 2, 3, 4, 5, 6};
        vector<int> vec2 = {0, 2, 4, 6, 1, 3, 5};
        shared_ptr<ListNode<int>> list1 = createList(vec1);
        shared_ptr<ListNode<int>> list2 = createList(vec2);

        auto head = evenOddMerge(list1);

        if ( !is_equal(head, list2) ) {
            cout << "Should be: " << list_to_string(list2) << endl;
            cout << "But result: " << list_to_string(head) << endl;

            return false;
        }

        return true;
    }

  } // chapter8
} // epi
