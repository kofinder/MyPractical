#include <iostream>
#include <list>

using namespace std;

/*
    * One of the easiest ways to implement polymorphism in OOP coding
    * This program is also relevant to real-world problems
*/
class YoutubeChannel {
    public:
        YoutubeChannel(string _name, string _ownerName) {
            name = _name;
            ownerName = _ownerName;
            subscriberCount = 0;
        }

        void getInfo() {
            cout << "Name: " << name << endl;
            cout << "Owner Name: " << ownerName << endl;
            cout << "Subscribers Count: " << subscriberCount << endl;
            cout << "Videos: " << endl;
            for(string title: publisheTitle) {
                cout << title << endl;
            }
        }

        void subscripbe() {
            subscriberCount++;
        }

        void unSubscribe() {
            subscriberCount--;
        }

        void publishVideo(string title) {
            publisheTitle.push_back(title);
        }

        void checkAnalytics() {
            if(contentQualtiy < 5) {
                cout << name << " has bad quality content." << endl;
            } else {
                cout << name << "has great content" << endl;
            }
        }

    protected:
        string ownerName;
        int contentQualtiy;

    private:
        string name;
        int subscriberCount;
        list<string> publisheTitle;
};


class CookingYoutubeChannel:public YoutubeChannel {
    public:
        CookingYoutubeChannel(string _name, string _ownerName):YoutubeChannel(_name, _ownerName) {
        }
        void pratice() {
            cout << ownerName << " is praticing cooking, learning new receips, experimenting with spices" << endl;
            contentQualtiy++;
        }
};


class SingerYoutubeChannel:public YoutubeChannel {
    public:
        SingerYoutubeChannel(string _name, string _onwerName):YoutubeChannel(_name, _onwerName) {
        }
        void pratice() {
            cout << ownerName << " is praticing cooking, learning new receips, experimenting with spices" << endl;
            contentQualtiy++;
        }
};
