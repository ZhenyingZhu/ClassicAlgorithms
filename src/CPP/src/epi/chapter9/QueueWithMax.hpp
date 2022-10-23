#ifndef SRC_EPI_CHAPTER9_QUEUEWITHMAX_HPP_
#define SRC_EPI_CHAPTER9_QUEUEWITHMAX_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <queue>
#include <deque>
#include <stdexcept>

namespace epi {
  namespace chapter9 {

    class QueueWithMax : public myutils::Solution {
        friend class myutils::SmartPtr;

    private:
        template <typename T>
        class MaxQueue {
        public:
            T dequeue() {
                if (entries_.empty())
                    throw std::length_error("Empty queue.");

                T data = entries_.front();
                entries_.pop();
                if (data == maxValues_.front())
                    maxValues_.pop_front();

                return data;
            }

            void enqueue(T data) {
                entries_.push(data);

                while (!maxValues_.empty() && maxValues_.back() < data) {
                    maxValues_.pop_back();
                }

                maxValues_.push_back(data);
            }

            T max() const {
                return maxValues_.front();
            }

        private:
            std::queue<T> entries_;
            std::deque<T> maxValues_;
        };

    public:
        QueueWithMax():
            Solution("EPI Chapter 9.10",
                     "Implement a queue with max API",
                     "Maintain a queue with max value. If the next element "
                     "is bigger than the tail, remove elements until the "
                     "previous element is bigger or equal.") { }

        ~QueueWithMax() { }

        bool test();
    };

  } // chapter9
} // epi

#endif /* SRC_EPI_CHAPTER9_QUEUEWITHMAX_HPP_ */
