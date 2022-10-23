#include "MergeTwoSortedLists.hpp"

#include "../../ListNode.h"

#include <memory>
#include <iostream>
#include <vector>

#include "../../MyUtils.h"

using std::shared_ptr;
using std::cout;
using std::endl;
using std::vector;
using myutils::ListNode;
using myutils::createList;
using myutils::is_equal;
using myutils::list_to_string;

namespace epi {
  namespace chapter8 {
    shared_ptr<ListNode<int>> MergeTwoSortedLists::mergeTwoSortedLists(shared_ptr<ListNode<int>> list1,
                                                                       shared_ptr<ListNode<int>> list2) {
        shared_ptr<ListNode<int>> dummy(new ListNode<int>);

        shared_ptr<ListNode<int>> cur = dummy;

        while (list1 && list2) {
            if (list1->data < list2->data) {
                cur->next = list1;
                cur = cur->next;
                list1 = list1->next;
            } else {
                cur->next = list2;
                cur = cur->next;
                list2 = list2->next;
            }
        }

        if (list1)
            cur->next = list1;
        else
            cur->next = list2;

        return dummy->next;
    }

    bool MergeTwoSortedLists::test() {
        vector<int> v1 = {2, 5, 7};
        vector<int> v2 = {3, 11};
        vector<int> sv = {2, 3, 5, 7, 11};
        shared_ptr<ListNode<int>> l1 = createList(v1);
        shared_ptr<ListNode<int>> l2 = createList(v2);
        shared_ptr<ListNode<int>> shouldBe = createList(sv);
        shared_ptr<ListNode<int>> res = mergeTwoSortedLists(l1, l2);

        if ( !is_equal(res, shouldBe) ) {
            cout << "Should be: " << list_to_string(shouldBe) << endl;
            cout << "But result: " << list_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter8
} // epi
