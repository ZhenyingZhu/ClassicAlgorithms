#include "StableSortList.hpp"

#include <memory>
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <vector>
#include <algorithm>

#include "../../ListNode.h"
#include "../../MyUtils.h"

using myutils::ListNode;
using std::shared_ptr;
using std::make_shared;
using myutils::createList;
using myutils::vec_to_string;
using myutils::list_to_string;
using std::vector;
using std::sort;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter14 {
    shared_ptr<ListNode<int>> StableSortList::stableMerge
            (shared_ptr<ListNode<int>> list1, shared_ptr<ListNode<int>> list2) {
        shared_ptr<ListNode<int>> dummy = make_shared<ListNode<int>>(ListNode<int>(0));
        shared_ptr<ListNode<int>> cur = dummy;

        while (list1 && list2) {
            if (list1->data <= list2->data) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }

            cur = cur->next;
        }

        if (list1) {
            cur->next = list1;
        } else {
            cur->next = list2;
        }

        // cout << list_to_string(dummy->next) << endl;
        return dummy->next;
    }

    shared_ptr<ListNode<int>> StableSortList::stableSortList(shared_ptr<ListNode<int>> list) {
        if (list == nullptr || list->next == nullptr)
            return list;

        shared_ptr<ListNode<int>> dummy(new ListNode<int>(0));
        dummy->next = list;

        shared_ptr<ListNode<int>> slow = dummy, fast = list;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        shared_ptr<ListNode<int>> half = slow->next;
        slow->next = nullptr;

        return stableMerge( stableSortList(list), stableSortList(half) );
    }

    bool StableSortList::test() {
        vector<int> array = {8, 3, 4, 6, 2, 3, 7, 8};
        shared_ptr<ListNode<int>> list = createList(array);
        shared_ptr<ListNode<int>> res = stableSortList(list), tmp = res;
        sort(array.begin(), array.end());

        for (int val : array) {
            if (val != tmp->data) {
                cout << "Should be " << vec_to_string(array) << endl;
                cout << "Result " << list_to_string(res) << endl;
                return false;
            }
            tmp = tmp->next;
        }

        return true;
    }

  } // chapter14
} // epi
