package designpatterns.behaviour;

/*
 * Mediator → central hub for communication
 * The Mediator pattern defines an object that centralizes communication between other objects to reduce dependencies
 * Example: Chat room managing messages between participants
*/
// Mediator interface
interface ChatRoom {
    void showMessage(User user, String message);
}

// Concrete Mediator
class ChatRoomImpl implements ChatRoom {
    public void showMessage(User user, String message) {
        System.out.println(user.getName() + ": " + message);
    }
}

// Colleague
class User {
    private String name;
    private ChatRoom chatRoom;

    public User(String name, ChatRoom chatRoom) {
        this.name = name;
        this.chatRoom = chatRoom;
    }

    public String getName() {
        return name;
    }

    public void send(String message) {
        chatRoom.showMessage(this, message);
    }
}

public class MediatorPattern {
    public static void main(String[] args) {
        ChatRoom chat = new ChatRoomImpl();
        User u1 = new User("Alice", chat);
        User u2 = new User("Bob", chat);

        u1.send("Hi Bob!");
        u2.send("Hello Alice!");

    }
}
