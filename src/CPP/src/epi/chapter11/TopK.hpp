#ifndef SRC_EPI_TOPK_HPP_
#define SRC_EPI_TOPK_HPP_

#include <queue>
#include <vector>
#include <string>
#include <sstream>

namespace epi {
  namespace chapter11 {
    class TopK {
    public:
        TopK() { }

        std::vector<std::string> topK(size_t k, std::istringstream *stream);

        bool test();
    };
  } // chapter11
} // epi

#endif /* SRC_EPI_TOPK_HPP_ */
