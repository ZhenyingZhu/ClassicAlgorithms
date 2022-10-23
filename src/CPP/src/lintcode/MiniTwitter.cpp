/*
 * [Source] http://www.lintcode.com/en/problem/mini-twitter/
 * [Difficulty]: 
 * [Tag]: 
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int inc_id_ = 0;

class Tweet {
public:
    int id;
    int user_id;
    string text;
    static Tweet create(int user_id, string tweet_text) {
        // This will create a new tweet object,
        // and auto fill id
        return {inc_id_++, user_id, tweet_text};
    }
};

// [Corner Case]:
// [Solution]: Something like Pull Model
class MiniTwitter {
public:
    MiniTwitter() {
        LISTLEN = 10;
    }

    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    Tweet postTweet(int user_id, string tweet_text) {
        // If the user first appears, follow himself
        if (following_map_.find(user_id) == following_map_.end())
            follow(user_id, user_id);

        Tweet tweet = Tweet::create(user_id, tweet_text);
        tweets_.push_back(tweet);
        return tweet;
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    vector<Tweet> getNewsFeed(int user_id) {
        unordered_map<int, unordered_set<int>>::const_iterator it = following_map_.find(user_id);
        if (it == following_map_.end())
            return {};

        // list size is LISTLEN
        return getTweets(it->second);
    }
        
    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    vector<Tweet> getTimeline(int user_id) {
        // even the user didn't follow anyone, he should still in the following_map_
        if (following_map_.find(user_id) == following_map_.end())
            return {};

        unordered_set<int> singleUser;
        singleUser.insert(user_id);
        return getTweets(singleUser);
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
        // Add follower himself to the map if didn't exist
        following_map_[from_user_id].insert(from_user_id);
        following_map_[from_user_id].insert(to_user_id);
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        // user not found
        if (following_map_.find(from_user_id) == following_map_.end())
            return;

        // cannot unfollower self
        if (from_user_id == to_user_id)
            return;

        following_map_[from_user_id].erase(to_user_id);
    }

private:
    vector<Tweet> getTweets(const unordered_set<int> &following) {
        vector<Tweet> res;
        for (vector<Tweet>::const_reverse_iterator it = tweets_.rbegin(); it != tweets_.rend(); ++it) {
            // get enough tweets already
            if (res.size() == LISTLEN)
                break;

            // Search from end to begin, which means the recent tweets show first
            if (following.find(it->user_id) != following.end()) {
                res.push_back(*it);
            }
        }
        return res;
    }

private:
    vector<Tweet> tweets_;
    unordered_map<int, unordered_set<int>> following_map_;

    size_t LISTLEN;
};

// [Solution]: Use tweet node to simulate DB. 
// http://www.jiuzhang.com/solutions/mini-twitter/

int main() {

    return 0;
}
