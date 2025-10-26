package designpatterns.behaviour;

/*
 * Observer → publish-subscribe notifications
    * The Observer pattern defines a one-to-many dependency so that when one object changes, all dependents are notified automatically
    * Example: Event listeners in GUI frameworks
 */

import java.util.*;

// Subject
class NewsAgency {
    private List<Subscriber> subscribers = new ArrayList<>();
    private String news;

    public void addSubscriber(Subscriber s) {
        subscribers.add(s);
    }

    public void removeSubscriber(Subscriber s) {
        subscribers.remove(s);
    }

    public void setNews(String news) {
        this.news = news;
        notifySubscribers();
    }

    private void notifySubscribers() {
        for (Subscriber s : subscribers)
            s.update(news);
    }
}

// Observer
interface Subscriber {
    void update(String news);
}

// Concrete Observer
class NewsReader implements Subscriber {
    private String name;

    public NewsReader(String name) {
        this.name = name;
    }

    public void update(String news) {
        System.out.println(name + " received news: " + news);
    }
}

public class ObserverPattern {
    public static void main(String[] args) {
        NewsAgency agency = new NewsAgency();
        Subscriber s1 = new NewsReader("Alice");
        Subscriber s2 = new NewsReader("Bob");

        agency.addSubscriber(s1);
        agency.addSubscriber(s2);

        agency.setNews("Breaking News!");

    }
}
