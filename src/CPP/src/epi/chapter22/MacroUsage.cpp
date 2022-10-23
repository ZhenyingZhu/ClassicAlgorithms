#include "MacroUsage.hpp"

#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::cout;
using std::endl;

namespace epi {
  namespace chapter22 {
    bool MacroUsage::test() {
        int c = 2;
        if ( !compareTwice(--c) ) { // should be true
            return false;
        }

        c = 2;
        if ( macrocomparetwice(--c) ) { // it expands to --c > 0 && --c > 0, which is false
            return false;
        }

        // macro define number
#define macrodefnum 100
        cout << "print 100: " << macrodefnum << endl;
        // macro flow control
#if macrodefnum>50
#undef macrodefnum
#define macrodefnum 50
#elif macrodefnum<50
#undef macrodefnum
#define macrodefnum 100
#else
#define macrodefnum 0
#endif
        cout << "print 50: " << macrodefnum << endl;
        // macro convert string
#define macroconvertstr(x) #x
        cout << "print test: " << macroconvertstr(test) << endl;
#define macrogluestr(a,b) a ## b
        macrogluestr(c,out) << "use macro call cout" << endl;

        return true;
    }

  } // chapter22
} // epi
