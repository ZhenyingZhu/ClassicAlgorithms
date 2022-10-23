#include "AddTwoNumbers.hpp"

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
    shared_ptr<ListNode<int>> AddTwoNumbers::addTwoNumbers(shared_ptr<ListNode<int>> list1, shared_ptr<ListNode<int>> list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        shared_ptr<ListNode<int>> dummy(new ListNode<int>());
        auto cur = dummy;
        int carry = 0;
        while (list1 && list2) {
            if (list1->data < 0 || list2->data < 0)
                throw invalid_argument("Lists contain negative value.");

            int sum = carry + list1->data + list2->data;
            shared_ptr<ListNode<int>> newNode(new ListNode<int>(sum % 10));
            carry = sum / 10;

            cur->next = newNode;
            cur = cur->next;
            list1 = list1->next, list2 = list2->next;
        }

        auto leftOver = list1 ? list1 : list2;
        cur->next = leftOver;

        while (carry == 1 && leftOver) {
            int sum = carry + leftOver->data;
            leftOver->data = sum % 10;
            carry = sum / 10;

            leftOver = leftOver->next;
        }

        if (carry == 1) { // leftOver reach end
            shared_ptr<ListNode<int>> newNode(new ListNode<int>(1));
            cur->next = newNode;
        }

        return dummy->next;
    }

    bool AddTwoNumbers::test() {
        vector<int> vec1 = {3, 1, 4};
        vector<int> vec2 = {7, 0, 9};
        vector<int> vec3 = {0, 2, 3, 1};
        shared_ptr<ListNode<int>> list1 = createList(vec1);
        shared_ptr<ListNode<int>> list2 = createList(vec2);
        shared_ptr<ListNode<int>> list3 = createList(vec3);

        auto head = addTwoNumbers(list1, list2);

        if ( !is_equal(head, list3) ) {
            cout << "Should be: " << list_to_string(list3) << endl;
            cout << "But result: " << list_to_string(head) << endl;

            return false;
        }

        return true;
    }

  } // chapter8
} // epi
