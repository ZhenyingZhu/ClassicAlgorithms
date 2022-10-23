#include "OverlappingNoCycleLists.hpp"

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
    size_t OverlappingNoCycleLists::listLen(const shared_ptr<ListNode<int>> &list) {
        auto head = list;
        size_t len = 0;

        while (head) {
            ++len;
            head = head->next;
        }

        return len;
    }

    shared_ptr<ListNode<int>> OverlappingNoCycleLists::overlappingNoCycleLists
      (shared_ptr<ListNode<int>> list1, shared_ptr<ListNode<int>> list2) {
        size_t len1 = listLen(list1), len2 = listLen(list2);

        size_t diff = 0;
        if (len1 < len2) {
            diff = len2 - len1;
            auto tmp = list1;
            list1 = list2;
            list2 = tmp;
        } else {
            diff = len1 - len2;
        }

        for (size_t i = 0; i != diff; ++i) {
            list1 = list1->next;
        }

        while (list1 && list2) {
            if (list1 == list2) {
                return list1;
            }

            list1 = list1->next;
            list2 = list2->next;
        }

        return nullptr;
    }

    bool OverlappingNoCycleLists::test() {
        vector<int> vec1 = {5, 4, 3, 2, 1};
        vector<int> vec2 = {8, 7, 6};
        shared_ptr<ListNode<int>> list1 = createList(vec1);
        shared_ptr<ListNode<int>> list2 = createList(vec2);

        auto ptr1 = list1;
        while (ptr1->data != 4)
            ptr1 = ptr1->next;

        auto ptr2 = list2;
        while (ptr2->next)
            ptr2 = ptr2->next;
        ptr2->next = ptr1;

        shared_ptr<ListNode<int>> res = overlappingNoCycleLists(list1, list2);

        if ( res->data != 4 ) {
            cout << "Should be overlapped at node 4" << endl;
            cout << "But result: " << (!res ? "null" : to_string(res->data)) << endl;

            return false;
        }

        return true;
    }

  } // chapter8
} // epi
