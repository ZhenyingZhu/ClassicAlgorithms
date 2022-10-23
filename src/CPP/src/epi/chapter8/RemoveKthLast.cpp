#include "RemoveKthLast.hpp"

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
    shared_ptr<ListNode<int>> RemoveKthLast::removeKthLast(const shared_ptr<ListNode<int>> &head, size_t k) {
        shared_ptr<ListNode<int>> dummy(new ListNode<int>());
        dummy->next = head;

        auto fast = dummy, slow = dummy;
        while (fast && k--) {
            fast = fast->next;
        }

        while (fast->next) {
            slow = slow->next, fast = fast->next;
        }

        if (fast->next)
            slow->next = slow->next->next;

        return dummy->next;
    }

    bool RemoveKthLast::test() {
        vector<int> vec1 = {5, 4, 3, 2, 1};
        vector<int> vec2 = {5, 4, 3, 2, 1};
        shared_ptr<ListNode<int>> list1 = createList(vec1);
        shared_ptr<ListNode<int>> list2 = createList(vec2);

        auto head = removeKthLast(list1, 0);

        if ( !is_equal(head, list2) ) {
            cout << "Should be: " << list_to_string(list2) << endl;
            cout << "But result: " << list_to_string(head) << endl;

            return false;
        }


        return true;
    }

  } // chapter8
} // epi
