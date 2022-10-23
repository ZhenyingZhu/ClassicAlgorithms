#ifndef SRC_EPI_CHAPTER9_SHORTESTEQUIVALENTPATH_HPP_
#define SRC_EPI_CHAPTER9_SHORTESTEQUIVALENTPATH_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <stack>
#include <string>

namespace epi {
  namespace chapter9 {

    class ShortestEquivalentPath : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        ShortestEquivalentPath():
            Solution("EPI Chapter 9.4",
                     "Normalize pathnames",
                     "corner case is '/' with '..'. "
                     "Use a vector to perform stack operations.") { }

        ~ShortestEquivalentPath() { }

        std::string shortestEquivalentPath(const std::string &path);

        bool test();
    };

  } // chapter9
} // epi

#endif /* SRC_EPI_CHAPTER9_SHORTESTEQUIVALENTPATH_HPP_ */
