#include <iostream>
#include <string>
#include <list>
using namespace std;


/*
   This program illustrates the usage of method overloading!.
 */

struct Post {
    string title;
    int likeCount;

    Post(string _title, int _likeCount) {
        title = _title;
        likeCount = _likeCount;
    }

    bool operator == (const Post& post) {
        return this->title == post.title;
    }
};

struct PostCollection {
    list<Post> collections;

    void operator+=(Post& post) {
        this->collections.push_back(post);
    }

    void operator-=(Post& post) {
        this->collections.remove(post);
    }
};


ostream& operator<<(ostream& COUT, Post& post) {
    COUT << "Post Title: " << post.title << endl;
    COUT << "Like Count: " << post.likeCount << endl;
    return COUT;
};

ostream& operator<<(ostream& COUT, PostCollection& postCollection) {
    for(Post post: postCollection.collections) {
        COUT << post << endl;
    }
    return COUT;
};