class Twitter {
private:
    struct tweet{
        int tweetid;
        int userid;
        tweet(){}
        tweet(int u,int t):tweetid(t),userid(u){}
    };
    unordered_map<int,unordered_set<int>>follows;
    vector<tweet>tweets;
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.push_back(tweet(userId,tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        if(tweets.empty()) return res;
        for(int i=tweets.size()-1;i>=0;i--) if(tweets[i].userid==userId||follows[userId].find(tweets[i].userid)!=follows[userId].end()){
            res.push_back(tweets[i].tweetid);
            if(res.size()==10) break;
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
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
