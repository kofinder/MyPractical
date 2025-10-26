package threads.sync.src;

public class LockExample {
    private final Object lock = new Object();

    public void criticalSection() {
        synchronized (lock) {
            System.out.println("Thread safe block");
        }
    }

}
