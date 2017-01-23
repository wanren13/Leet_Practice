#pragma once

#include "allhead.h"

namespace design_twitter {
	class Twitter {
	public:
		/** Initialize your data structure here. */
		Twitter() {
			time = INT_MAX;
		}

		/** Compose a new tweet. */
		void postTweet(int userId, int tweetId) {
			tweets[userId][time--] = tweetId;
		}

		/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
		vector<int> getNewsFeed(int userId) {
			vector<int> res;
			vector<map<int, int>::iterator> begins;
			vector<map<int, int>::iterator> ends;
			begins.emplace_back(tweets[userId].begin());
			ends.emplace_back(tweets[userId].end());
			for (int followeeId : follows[userId]) {
				if (userId != followeeId) {
					begins.emplace_back(tweets[followeeId].begin());
					ends.emplace_back(tweets[followeeId].end());
				}
			}

			for (int i = 0; i < 10; i++) {
				int id = 0;
				while (id < begins.size() && begins[id] == ends[id]) id++;
				if (id == begins.size()) return res;
				for (int j = id + 1; j < begins.size(); j++) {
					if (begins[j] != ends[j] && begins[id]->first > begins[j]->first) id = j;
				}
				res.emplace_back(begins[id]->second);
				begins[id]++;
			}

			return res;
		}

		/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
		void follow(int followerId, int followeeId) {
			follows[followerId].insert(followeeId);
		}

		/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
		void unfollow(int followerId, int followeeId) {
			follows[followerId].erase(followeeId);
		}
	private:
		int time;
		unordered_map<int, map<int, int>> tweets;
		unordered_map<int, unordered_set<int>> follows;
	};


	void test() {
		Twitter twitter;
		vector<int> newsfeed;
		// User 1 posts a new tweet (id = 5).
		twitter.postTweet(1, 5);

		// User 1's news feed should return a list with 1 tweet id -> [5].
		newsfeed = twitter.getNewsFeed(1);

		for (int i : newsfeed) cout << i << "  ";
		cout << endl;

		// User 1 follows user 2.
		twitter.follow(1, 2);

		// User 2 posts a new tweet (id = 6).
		twitter.postTweet(2, 6);

		// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
		// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
		newsfeed = twitter.getNewsFeed(1);

		for (int i : newsfeed) cout << i << "  ";
		cout << endl;

		// User 1 unfollows user 2.
		twitter.unfollow(1, 2);

		// User 1's news feed should return a list with 1 tweet id -> [5],
		// since user 1 is no longer following user 2.
		newsfeed = twitter.getNewsFeed(1);

		for (int i : newsfeed) cout << i << "  ";
		cout << endl;
	}
}