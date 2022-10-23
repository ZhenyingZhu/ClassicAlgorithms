#include "WeakPtrUsage.hpp"

#include <memory>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter22 {
    struct WeakPtrUsage::Cycle1 {
        ~Cycle1() {
            cout << "~Cycle1" << endl;
        }

        shared_ptr<Cycle2> next;

    };

    struct WeakPtrUsage::Cycle2 {
        ~Cycle2() {
            cout << "~Cycle2" << endl;
        }

        weak_ptr<Cycle1> next; // if it is shared_ptr, then Cycle1 and Cycle2 cannot be destoryed

    };

    bool WeakPtrUsage::test() {
        weak_ptr<Cycle1> gw;
        {
            auto head = make_shared<Cycle1>();
            shared_ptr<Cycle2> tail = make_shared<Cycle2>();
            gw = head;

            head->next = tail;
            tail->next = gw;
        } // out of scope here

        if ( gw.lock() ) { // return shared_ptr or nullptr of this weak_ptr
            return false;
        }

        return true;
    }

  } // chapter22
} // epi
