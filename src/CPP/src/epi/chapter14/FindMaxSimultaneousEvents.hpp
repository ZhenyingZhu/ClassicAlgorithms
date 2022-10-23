#ifndef SRC_EPI_CHAPTER14_FINDMAXSIMULTANEOUSEVENTS_HPP_
#define SRC_EPI_CHAPTER14_FINDMAXSIMULTANEOUSEVENTS_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter14 {
    class FindMaxSimultaneousEvents : public myutils::Solution {
    public:
        struct Event;

        struct Endpoint;

        FindMaxSimultaneousEvents():
            Solution("EPI Chapter 14.4",
                     "Render a calendar",
                     "Sort endpoints of events. Iterate through endpoints, "
                     "if there is a start endpoint, increase the counter; "
                     "if it is an end endpoint, decrease the counter. Start "
                     "endpoint should come before end endpoint.") { }

        ~FindMaxSimultaneousEvents() { }

        int findMaxSimultaneousEvents(const std::vector<Event> &events);

        bool test();

    };

  } // chapter14
} // epi

#endif /* SRC_EPI_CHAPTER14_FINDMAXSIMULTANEOUSEVENTS_HPP_ */
