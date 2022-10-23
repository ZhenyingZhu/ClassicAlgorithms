#include "ISBNCache.hpp"

#include <string>
#include <unordered_map>
#include <cctype>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::string;
using std::unordered_map;
using std::isalnum;
using std::runtime_error;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter13 {
    bool ISBNCache::test() {
        LRUCache<3> isbnCache;

        isbnCache.insert(111, 1);
        int price1 = 0;
        if (!isbnCache.lookup(111, &price1)) {
            cout << "Cannot find 111" << endl;
            return false;
        }
        if (price1 != 1) {
            cout << "111 price is " << price1 << endl;
            return false;
        }

        isbnCache.insert(222, 2);
        int price2 = 0;
        if (!isbnCache.lookup(222, &price2)) {
            cout << "Cannot find 222" << endl;
            return false;
        }
        if (price2 != 2) {
            cout << "222 price is " << price2 << endl;
            return false;
        }
        if (!isbnCache.lookup(111, &price1)) {
            cout << "Cannot find 111 after insert 222" << endl;
            return false;
        }
        if (price1 != 1) {
            cout << "111 price is " << price1 << " after insert 222" << endl;
            return false;
        }

        isbnCache.insert(333, 3);
        isbnCache.insert(444, 4);
        if (isbnCache.lookup(222, &price2)) {
            cout << "222 should already be rotated" << endl;
            return false;
        }

        if (isbnCache.erase(222)) {
            cout << "Can erase 222" << endl;
        }

        if (!isbnCache.erase(333)) {
            cout << "Can not erase 333" << endl;
        }

        int price3 = 0;
        if (isbnCache.lookup(333, &price3)) {
            cout << "333 should already be erased" << endl;
            return false;
        }

        if (!isbnCache.lookup(111, &price1)) {
            cout << "Cannot find 111 after insert 222" << endl;
            return false;
        }
        if (price1 != 1) {
            cout << "111 price is " << price1 << " after insert 222" << endl;
            return false;
        }

        return true;
    }

  } // chapter13
} // epi
