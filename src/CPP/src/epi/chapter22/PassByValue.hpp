#ifndef SRC_EPI_CHAPTER22_PASSBYVALUE_HPP_
#define SRC_EPI_CHAPTER22_PASSBYVALUE_HPP_

#include "../../Solution.h"

namespace epi {
  namespace chapter22 {
    class PassByValue : public myutils::Solution {
    public:
        class Base;
        
        class Child;

        PassByValue():
            Solution("EPI Chapter 22.2",
                     "Compute a shortest path with fewest edges",
                     "Use Dijkstra shortest path algorithm but compare edge numbers as well.") { }

        ~PassByValue() { }

        void castByValue(Base obj);

        void castByRef(Base &ref);

        bool test();

    };

  } // chapter22
} // epi

#endif /* SRC_EPI_CHAPTER22_PASSBYVALUE_HPP_ */
