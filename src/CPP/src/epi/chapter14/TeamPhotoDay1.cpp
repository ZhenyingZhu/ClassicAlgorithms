#include "TeamPhotoDay1.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>

using std::vector;
using std::sort;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter14 {
    struct TeamPhotoDay1::Player {
        bool operator<(const Player &that) const {
            return height < that.height;
        }

        bool operator>(const Player &that) const {
            return height > that.height;
        }

        int height;
    };

    class TeamPhotoDay1::Team {
    public:
        Team(std::vector<int> heights) {
            for (int height : heights) {
                players_.push_back(Player{height});
            }

            sort(players_.begin(), players_.end());
        }

        const std::vector<Player>& getPlayers() const {
            return players_;
        }

    private:
        std::vector<Player> players_;
    };

    bool TeamPhotoDay1::validPlacementExists(const Team &team1, const Team &team2) {
        const vector<Player> &t1 = team1.getPlayers(), &t2 = team2.getPlayers();
        assert(!t1.empty() && t1.size() == t2.size());

        for (size_t i = 1; i != t1.size(); ++i) {
            if (t1[0] > t2[0]) {
                if ( !(t1[i] > t2[i]) )
                    return false;
            } else if (t2[0] > t1[0]){
                if ( !(t2[i] > t1[i]) )
                    return false;
            } else {
                return false;
            }
        }

        return true;
    }

    bool TeamPhotoDay1::test() {
        vector<int> heights1 = {1, 2, 3, 4, 5};
        vector<int> heights2 = {2, 3, 4, 5, 6};

        Team team1(heights1), team2(heights2);

        if (!validPlacementExists(team1, team2)) {
            cout << "Case 1 fail" << endl;
            return false;
        }

        if (!validPlacementExists(team2, team1)) {
            cout << "Case 2 fail" << endl;
            return false;
        }

        vector<int> heights3 = {1, 2, 3, 4, 5};
        vector<int> heights4 = {3, 3, 3, 3, 3};

        Team team3(heights3), team4(heights4);

        if (validPlacementExists(team3, team4)) {
            cout << "Case 3 fail" << endl;
            return false;
        }

        if (validPlacementExists(team4, team3)) {
            cout << "Case 4 fail" << endl;
            return false;
        }

        return true;
    }

  } // chapter14
} // epi
