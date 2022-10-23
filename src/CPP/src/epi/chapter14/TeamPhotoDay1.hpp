#ifndef SRC_EPI_CHAPTER14_TEAMPHOTODAY1_HPP_
#define SRC_EPI_CHAPTER14_TEAMPHOTODAY1_HPP_

#include "../../Solution.h"

namespace epi {
  namespace chapter14 {
    class TeamPhotoDay1 : myutils::Solution {
    public:
        struct Player;

        class Team;

        TeamPhotoDay1():
            Solution("EPI Chapter 14.8",
                     "Team photo day 1",
                     "Place two teams in two rows explicitly. Person "
                     "in the second row should be taller than the first "
                     "row. Sort two teams. Compare each pair to see if "
                     "the taller one is in the same team.") { }

        ~TeamPhotoDay1() { }

        bool validPlacementExists(const Team &team1, const Team &team2);

        bool test();

    };

  } // chapter14
} // epi

#endif /* SRC_EPI_CHAPTER14_TEAMPHOTODAY1_HPP_ */
