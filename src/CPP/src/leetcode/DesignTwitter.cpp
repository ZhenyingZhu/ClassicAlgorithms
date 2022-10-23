/*
 * [Source] https://leetcode.com/problems/design-twitter/
 * [Difficulty]: Medium
 * [Tag]: Hash Table
 * [Tag]: Heap
 * [Tag]: Design
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Use a user table, a tweet table to record all tweets and followers. Then get 10 last tweets from all followees, and do sort (can also use k merge sort).
// [Corner Case]:
class Twitter {
public:
    Twitter() {
        timestamp_ = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        followerMap_[userId].insert(userId);
        tweetMap_[userId].push_back({tweetId, timestamp_++});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
cout << "get" << endl;
        if (followerMap_.find(userId) == followerMap_.end())
            return {};

        unordered_set<int> &followees = followerMap_[userId];
        vector<Tweet> tweets;
        tweets.reserve(followees.size() * 10);
        for (auto it = followees.begin(); it != followees.end(); ++it) {
            if (tweetMap_.find(*it) == tweetMap_.end())
                continue;
            vector<Tweet> &userTweets = tweetMap_[*it];
            for (int i = 0; i < 10 && i < (int)userTweets.size(); ++i) {
                tweets.push_back(userTweets[userTweets.size() - i - 1]);
            }
        }
        sort(tweets.begin(), tweets.end(), greater);

        vector<int> res;
        for (int i = 0; i < (int)tweets.size() && i < 10; ++i) {
            res.push_back(tweets[i].tweetId);
        }
cout << "end" << endl;
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        // make sure every follower follow himself
        followerMap_[followerId].insert(followerId);
        followerMap_[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followerMap_[followerId].insert(followerId);
        // make sure the followee always exist
        followerMap_[followerId].insert(followeeId);
        if (followerId != followeeId)
            followerMap_[followerId].erase(followeeId);
    }

private:
    struct Tweet {
        int tweetId;
        int timestamp;
    };

    static bool greater(const Tweet &a, const Tweet &b) {
        return a.timestamp > b.timestamp;
    }

    int timestamp_;
    unordered_map<int, vector<Tweet>> tweetMap_;
    unordered_map<int, unordered_set<int>> followerMap_;
};

class Solution {
public:
    void test() {
        Twitter twitter;
        twitter.postTweet(1, 5);
        printVec(twitter.getNewsFeed(1));
        twitter.follow(1, 2);
        twitter.postTweet(2, 6);
        printVec(twitter.getNewsFeed(1));
        twitter.unfollow(1, 2);
        printVec(twitter.getNewsFeed(1));
    }

    void printVec(vector<int> vec) {
        for (int &n : vec)
            cout << n << " ";
        cout << endl;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    sol.test();

    return 0;
}
