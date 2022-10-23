#include "OverlappingLists.hpp"

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
    shared_ptr<ListNode<int>> OverlappingLists::hasCycle(const shared_ptr<ListNode<int>> &list) {
        auto slow = list, fast = list;
        do {
            slow = slow->next, fast = fast->next->next;
        } while (fast && fast->next && slow != fast);

        if (slow != fast)
            return nullptr;

        auto ptr = list;
        while (fast != ptr) {
            ptr = ptr->next, fast = fast->next;
        }

        return ptr;
    }

    shared_ptr<ListNode<int>> OverlappingLists::overlappingLists
      (shared_ptr<ListNode<int>> list1, shared_ptr<ListNode<int>> list2) {
        auto cycleEntrance1 = hasCycle(list1); // could be nullptr
        auto cycleEntrance2 = hasCycle(list2);

        size_t len1 = 0, len2 = 0;
        auto ptr1 = list1, ptr2 = list2;
        while(ptr1 != cycleEntrance1) {
            ++len1;
            ptr1 = ptr1->next;
        }

        // If cycle1 and cycle2 are not same cycle, need break the while
        bool secondCycle = false;
        while (ptr2 && ptr2 != cycleEntrance1) {
            if (ptr2 == cycleEntrance2) {
                if (secondCycle)
                    return nullptr;
                secondCycle = true;
            }

            ++len2;
            ptr2 = ptr2->next;
        }

        size_t diff = 0;
        if (len1 < len2) {
            diff = len2 - len1;
            auto tmp = list1;
            list1 = list2;
            list2 = tmp;
        } else {
            diff = len1 - len2;
        }

        while (--diff)
            list1 = list1->next;

        while (ptr1 && ptr2) {
            if (ptr1 == ptr2)
                return ptr1;

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return nullptr;
    }

    bool OverlappingLists::test() {
        vector<int> vec1 = {5, 6};
        vector<int> vec2 = {1, 2, 3, 4};
        shared_ptr<ListNode<int>> list1 = createList(vec1);
        shared_ptr<ListNode<int>> list2 = createList(vec2);
        auto end1 = find_node(list1, 6);
        auto enter2 = find_node(list2, 2);
        auto end2 = find_node(list2, 4);
        end1->next = enter2;
        end2->next = list2;

        shared_ptr<ListNode<int>> res = overlappingLists(list1, list2);

        if ( !res || res->data != 2 ) {
            cout << "Should be overlapped at 2" << endl;
            cout << "But result: " << (!res ? "null" : to_string(res->data)) << endl;

            return false;
        }


        return true;
    }

  } // chapter8
} // epi
