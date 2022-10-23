#include "CyclicallyRightShiftList.hpp"

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
    shared_ptr<ListNode<int>> CyclicallyRightShiftList::cyclicallyRightShiftList
      (const shared_ptr<ListNode<int>> &head, unsigned k) {
        if (!head || !head->next)
            return head;

        auto slow = head, fast = head;

        while (k--) {
            if (!fast)
                fast = head;
            fast = fast->next;
        }

        while (fast->next) {
            slow = slow->next, fast = fast->next;
        }

        auto res = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return res;
    }

    bool CyclicallyRightShiftList::test() {
        vector<int> vec1 = {4, 3, 2, 1};
        vector<int> vec2 = {2, 1, 4, 3};
        shared_ptr<ListNode<int>> list1 = createList(vec1);
        shared_ptr<ListNode<int>> list2 = createList(vec2);

        auto head = cyclicallyRightShiftList(list1, 6);

        if ( !is_equal(head, list2) ) {
            cout << "Should be: " << list_to_string(list2) << endl;
            cout << "But result: " << list_to_string(head) << endl;

            return false;
        }

        return true;
    }

  } // chapter8
} // epi
