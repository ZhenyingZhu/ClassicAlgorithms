#include "PassByValue.hpp"

#include <string>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter22 {
    class PassByValue::Base {
    public:
        virtual string msg() {
            return "It's Base";
        }

    };

    class PassByValue::Child : public Base {
    public:
        virtual string msg() {
            return "It's Child";
        }

    };

    void PassByValue::castByValue(Base obj) {
        cout << obj.msg() << endl;
    }

    void PassByValue::castByRef(Base &ref) {
        cout << ref.msg() << endl;
    }

    bool PassByValue::test() {
        Base b;
        Child c;
        castByValue(b);
        cout << "Call child override function by passing value: ";
        castByValue(c);
        cout << endl;
        cout << "Call child override function by passing ref: ";
        castByRef(c);
        cout << endl;

        return true;
    }

  } // chapter22
} // epi
