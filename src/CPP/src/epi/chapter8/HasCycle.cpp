#include "HasCycle.hpp"

#include "../../ListNode.h"

#include <memory>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "../../MyUtils.h"

using std::shared_ptr;
using std::cout;
using std::endl;
using std::vector;
using std::to_string;
using myutils::ListNode;
using myutils::createList;
using myutils::is_equal;
using myutils::list_to_string;
using std::invalid_argument;

namespace epi {
  namespace chapter8 {
    shared_ptr<ListNode<int>> HasCycle::hasCycle(const shared_ptr<ListNode<int>> &head) {
        auto fast = head, slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                auto iter = head;
                while (fast != iter) {
                    fast = fast->next;
                    iter = iter->next;
                }

                return iter;
            }
        }

        return nullptr;
    }

    bool HasCycle::test() {
        vector<int> vec = {1, 2, 3, 4, 5};
        shared_ptr<ListNode<int>> list = createList(vec);
        shared_ptr<ListNode<int>> res = hasCycle(list);

        if ( res ) {
            cout << "Should be no cycle" << endl;
            cout << "But result: " << res->data << endl;
            return false;
        }

        auto node3 = list, nodeend = list;
        for (size_t i = 0; i != vec.size() - 1; ++i) {
            if (i == 2)
                node3 = nodeend;

            nodeend = nodeend->next;
        }

        nodeend->next = node3;

        res = hasCycle(list);
        if ( !res || res->data != 3 ) {
            cout << "Should be cycle from 3" << endl;
            cout << "But result: " << (!res ? "null" : to_string(res->data)) << endl;

            return false;
        }


        return true;
    }

  } // chapter8
} // epi
