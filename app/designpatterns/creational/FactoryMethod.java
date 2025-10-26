package designpatterns.creational;

/*
1. Factory Method → 1 product, subclass decides.
    * The Factory Method pattern is used to create a single product, allowing subclasses to decide which concrete class to instantiate

2. Abstract Factory → multiple related products, family of products.
    * The Abstract Factory pattern provides an interface to create families of related or dependent objects without specifying their concrete classes.

--------------------------------- -------------------------------------------------------------
| Role                           | Class                                                      |
| ------------------------------ | ---------------------------------------------------------- |
| **Product interface**          | `Notification`                                             |
| **Concrete products**          | `EmailNotification`, `SMSNotification`, `PushNotification` |
| **Creator (abstract factory)** | `NotificationFactory`                                      |
| **Concrete creators**          | `EmailFactory`, `SMSFactory`, `PushFactory`                |
| **Client**                     | `FactoryMethodUsage`                                       |
--------------------------------- -------------------------------------------------------------
 */

interface Notification {
    void notifyUser();
}

class EmailNotification implements Notification {
    @Override
    public void notifyUser() {
        System.out.println("Sending an Email Notification");
    }
}

class SMSNotification implements Notification {
    @Override
    public void notifyUser() {
        System.out.println("Sending an SMS Notification");
    }
}

class PushNotification implements Notification {
    @Override
    public void notifyUser() {
        System.out.println("Sending a Push Notification");
    }
}

abstract class NotificationFactory {

    // Factory Method
    public abstract Notification createNotification();

    // Common logic
    public void sendNotification() {
        Notification notification = createNotification();
        notification.notifyUser();
    }
}

class EmailFactory extends NotificationFactory {
    @Override
    public Notification createNotification() {
        return new EmailNotification();
    }
}

class SMSFactory extends NotificationFactory {
    @Override
    public Notification createNotification() {
        return new SMSNotification();
    }
}

class PushFactory extends NotificationFactory {
    @Override
    public Notification createNotification() {
        return new PushNotification();
    }
}

public class FactoryMethod {
    public static void main(String[] args) {
        NotificationFactory factory;

        factory = new EmailFactory();
        factory.sendNotification(); // Sending an Email Notification

        factory = new SMSFactory();
        factory.sendNotification(); // Sending an SMS Notification

        factory = new PushFactory();
        factory.sendNotification(); // Sending a Push Notification

    }
}
