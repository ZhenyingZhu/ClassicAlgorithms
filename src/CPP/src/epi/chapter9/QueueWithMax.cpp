#include "QueueWithMax.hpp"

#include <vector>
#include <iostream>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;
using myutils::test_same;

namespace epi {
  namespace chapter9 {
    bool QueueWithMax::test() {
        MaxQueue<int> q;

        vector<int> input = {3, 1, 3, 2, 0, 1};
        for (int i : input)
            q.enqueue(i);

        if ( !test_same(3, q.max()) ) {
            cout << 1 << endl;
            return false;
        }
        if (! test_same(3, q.dequeue()) ) {
            cout << 2 << endl;
            return false;
        }
        if (! test_same(1, q.dequeue()) ) {
            cout << 3 << endl;
            return false;
        }
        if ( !test_same(3, q.max()) ) {
            cout << 4 << endl;
            return false;
        }

        q.enqueue(2);
        q.enqueue(4);

        if ( !test_same(4, q.max()) ) {
            cout << 5 << endl;
            return false;
        }
        if (! test_same(3, q.dequeue()) ) {
            cout << 6 << endl;
            return false;
        }
        if ( !test_same(4, q.max()) ) {
            cout << 7 << endl;
            return false;
        }

        q.enqueue(4);

        if ( !test_same(4, q.max()) ) {
            cout << 8 << endl;
            return false;
        }

        return true;
    }

  } // chapter9
} // epi
