#include "RemoveDuplicates.hpp"

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
    shared_ptr<ListNode<int>> RemoveDuplicates::removeDuplicates(const shared_ptr<ListNode<int>> &head) {
        auto fast = head, slow = head;
        while (fast) {
            if (fast->data != slow->data) {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }

        if (slow) { // head could be nullptr
            slow->next = nullptr;
        }

        return head;
    }
    bool RemoveDuplicates::test() {
        vector<int> vec1 = {2, 2, 3, 5, 7, 11, 11};
        vector<int> vec2 = {2, 3, 5, 7, 11};
        shared_ptr<ListNode<int>> list1 = createList(vec1);
        shared_ptr<ListNode<int>> list2 = createList(vec2);

        auto head = removeDuplicates(list1);

        if ( !is_equal(head, list2) ) {
            cout << "Should be: " << list_to_string(list2) << endl;
            cout << "But result: " << list_to_string(head) << endl;

            return false;
        }

        return true;
    }

  } // chapter8
} // epi
