/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start

/*
Notes:
A combination of OOP + algorithmic access
Basic idea: have Tweet and User structs, and an overall map that goes from user ID to users
each user has a set of following and a list of tweets, each tweet has a timestamp

getNewsFeed is hardest to implement: use priority queue and merge the lists with timestamp order
Ideally, you can use list iterators and compare them with end iterator; or use self-defined nodes
and compare with nullptr. Here I just added everything to the pq and it worked; but not ideal

Also would be better to have better abstraction between the Twitter object and each user and tweets
there should be sub-functions inside Tweet and User's API. Twitter class shouldn't know anything about
underlying functions
*/

#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <vector>
using namespace std;

class Twitter {
public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // if user doesn't exist, construct new user
        makeUserIfDoesntExist(userId);
        // get user, construct new tweet, push to user's tweet list
        User& user = allUsers[userId];
        Tweet tweet{tweetId, timeStamp};
        user.tweets.push_back(tweet);
        // increment timestamp
        timeStamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet, vector<Tweet>, decltype(cmpTweet)> feed(cmpTweet);
        vector<int> res;
        for (int followingId : allUsers[userId].following){
            for (Tweet& tweet : allUsers[followingId].tweets){
                // add all tweets to the pq. It's really inefficient to do this way
                // but the efficient way requires comparing list iterators against the end iterator
                // which is unique to each list. Not sure how to do that elegantly yet
                feed.push(tweet); 
            }
        }
        while (res.size() < 10 && !feed.empty()){
            res.push_back(feed.top().tweetId);
            feed.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        // check if users exist
        makeUserIfDoesntExist(followerId);
        makeUserIfDoesntExist(followeeId);
        // get user, insert followee into following set
        User& follower = allUsers[followerId];
        follower.following.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // they should both exist already
        User& follower = allUsers[followerId];
        follower.following.erase(followeeId);
    }

private:

    // class-level timeStamp for entire twitter instance, used for each tweet
    int timeStamp; 
    struct Tweet {
        int tweetId;
        int timeStamp;
    };
    
/*     // each user is mapped to a set of the users that they follow
    unordered_map<int, unordered_set<int>> user2Following;
    // each user to their own tweets. This should be enough to represent all tweets
    // since each tweet corresponds to a user
    unordered_map<int, list<Tweet>> user2Tweets; 
 */
    // or better yet, have a user struct that handles these
    struct User {
        int userId;
        unordered_set<int> following;
        list<Tweet> tweets;
    };

    // a map from userId to User
    unordered_map<int, User> allUsers;

    void makeUserIfDoesntExist(int userId){
        if (!allUsers.count(userId)) {
            // following the user himself (to make things a bit easier to do)
            allUsers[userId] = {userId, {userId}, {}};
        }
    }

    struct {
        bool operator()(Tweet& a, Tweet& b){
            return a.timeStamp < b.timeStamp;
        }
    } cmpTweet;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

